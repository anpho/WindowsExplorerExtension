// NewFolderExt.h: CNewFolderExt 的声明

#pragma once
#include "resource.h"       // 主符号
#include <ShlObj.h>
#include <wil/resource.h>
#include <atlstr.h>
#include <vector>
#include <new>

#include "ExplorerEnhancement_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CNewFolderExt

class ATL_NO_VTABLE CNewFolderExt :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CNewFolderExt, &CLSID_NewFolderExt>,
	public INewFolderExt,
	public IShellExtInit,
	public IContextMenu,
	public IExplorerCommand
{
public:

	DECLARE_REGISTRY_RESOURCEID(106)

		DECLARE_NOT_AGGREGATABLE(CNewFolderExt)

	BEGIN_COM_MAP(CNewFolderExt)
		COM_INTERFACE_ENTRY(INewFolderExt)
		COM_INTERFACE_ENTRY(IShellExtInit)
		COM_INTERFACE_ENTRY(IContextMenu)
		COM_INTERFACE_ENTRY(IExplorerCommand)
	END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

		HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{

	}

	CNewFolderExt();
	~CNewFolderExt();
	DWORD _ThreadProc();
	static DWORD __stdcall s_ThreadProc(void* pv);
	// 通过 IShellExtInit 继承
	virtual HRESULT __stdcall Initialize(PCIDLIST_ABSOLUTE pidlFolder, IDataObject* pdtobj, HKEY hkeyProgID) override;

	/// <summary>
	/// 从IDataObject中获取IShellItemArray
	/// </summary>
	/// <param name="dataSource">IDataObject</param>
	/// <param name="items">IShellItemArray</param>
	/// <returns>HRESULT</returns>
	HRESULT __stdcall GetShellItemArrayFromDataObject(_In_ IUnknown* dataSource, _COM_Outptr_ IShellItemArray** items);


	// 通过 IContextMenu 继承
	virtual HRESULT __stdcall QueryContextMenu(HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags) override;
	virtual HRESULT __stdcall InvokeCommand(CMINVOKECOMMANDINFO* pici) override;
	HRESULT __stdcall DoCreateAndMoveItems(CMINVOKECOMMANDINFO* pici, IShellItemArray* psiItemArray);

	/*
	* 2022/3/18
	* 增加 length_to_compare 参数，提高处理速度
	*/
	int first_common_substring_length(const ATL::CString& str1, const ATL::CString& str2, int length_to_compare);
	/*
	* 2022/3/18
	* 最长公共前缀
	*/
	ATL::CString longestCommonPrefix(const std::vector<ATL::CString>& strs);

	ATL::CString find_common_prefix(const std::vector<ATL::CString> filepaths, OUT ATL::CString* default_path);

	ATL::CString extract_filename(const ATL::CString filepath);

	ATL::CString extract_filename_without_ext(const ATL::CString filepath);

	ATL::CString rebase_path(ATL::CString src_path, ATL::CString new_base_folder);

	ATL::CString combine_path(ATL::CString folder_name, ATL::CString suffix);

	virtual HRESULT __stdcall GetCommandString(UINT_PTR idCmd, UINT uType, UINT* pReserved, CHAR* pszName, UINT cchMax) override;


	// 通过 IExplorerCommand 继承
	virtual HRESULT __stdcall GetTitle(IShellItemArray* psiItemArray, LPWSTR* ppszName) override;

	virtual HRESULT __stdcall GetIcon(IShellItemArray* psiItemArray, LPWSTR* ppszIcon) override;

	virtual HRESULT __stdcall GetToolTip(IShellItemArray* psiItemArray, LPWSTR* ppszInfotip) override;

	virtual HRESULT __stdcall GetCanonicalName(GUID* pguidCommandName) override;

	virtual HRESULT __stdcall GetState(IShellItemArray* psiItemArray, BOOL fOkToBeSlow, EXPCMDSTATE* pCmdState) override;

	virtual HRESULT __stdcall Invoke(IShellItemArray* psiItemArray, IBindCtx* pbc) override;

	virtual HRESULT __stdcall GetFlags(EXPCMDFLAGS* pFlags) override;

	virtual HRESULT __stdcall EnumSubCommands(IEnumExplorerCommand** ppEnum) override;
private:
	CComPtr<IDataObject> m_spdo = nullptr;
	CComPtr<IBindCtx> ibindctx = nullptr;
	ATL::CString m_contextmenu_name = nullptr;
	std::vector<ATL::CString> selected_files;
	HBITMAP m_icon = nullptr;
	IShellItemArray* spsia;
	IStream* _pstmShellItemArray;

};
struct threadParam
{
	HWND hwnd;
	LPCWSTR folder_to_select;
};
unsigned __stdcall selectItem(void* pArguments);
OBJECT_ENTRY_AUTO(__uuidof(NewFolderExt), CNewFolderExt)
