// BreakFolderExt.h: CBreakFolderExt 的声明

#pragma once
#include "resource.h"       // 主符号
#include <ShlObj.h>
#include <vector>
#include <filesystem>
#include <string>
#include <atlstr.h>


#include "ExplorerEnhancement_i.h"



using namespace ATL;


// CBreakFolderExt

class ATL_NO_VTABLE CBreakFolderExt :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CBreakFolderExt, &CLSID_BreakFolderExt>,
	public IBreakFolderExt,
	public IShellExtInit,
	public IContextMenu
{
public:
	CBreakFolderExt()
	{
		(m_contextMenuName.LoadStringW(IDS_MENU_BREAKFOLDERS));
		if (!m_hBitmap) {
			loadIcon();
		}
	}

DECLARE_REGISTRY_RESOURCEID(107)
DECLARE_NOT_AGGREGATABLE(CBreakFolderExt)

BEGIN_COM_MAP(CBreakFolderExt)
	COM_INTERFACE_ENTRY(IBreakFolderExt)
	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IContextMenu)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		if (SUCCEEDED(CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE))) {
			return S_OK;
		}
		else {
			return E_FAIL;
		}
	}

	void FinalRelease()
	{
		if (m_hIcon) {
			DeleteObject(m_hIcon);
			m_hIcon = nullptr;
		}
		CoUninitialize();
	}

public:




	// 通过 IShellExtInit 继承
	virtual HRESULT __stdcall Initialize(PCIDLIST_ABSOLUTE pidlFolder, IDataObject* pdtobj, HKEY hkeyProgID) override;


	// 通过 IContextMenu 继承
	virtual HRESULT __stdcall QueryContextMenu(HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags) override;

	virtual HRESULT __stdcall InvokeCommand(CMINVOKECOMMANDINFO* pici) override;

	virtual HRESULT __stdcall GetCommandString(UINT_PTR idCmd, UINT uType, UINT* pReserved, CHAR* pszName, UINT cchMax) override;
private:
	ATL::CString m_contextMenuName;
	std::vector<std::filesystem::path> m_selectedFolders;
	HRESULT OnBreakFoldersTriggered();
	HICON m_hIcon = nullptr;
	HBITMAP m_hBitmap = nullptr;
	void loadIcon();
};

OBJECT_ENTRY_AUTO(__uuidof(BreakFolderExt), CBreakFolderExt)
