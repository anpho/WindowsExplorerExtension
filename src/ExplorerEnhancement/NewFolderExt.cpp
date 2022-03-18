// NewFolderExt.cpp: CNewFolderExt 的实现

#include "pch.h"
#include "NewFolderExt.h"
#include <atlpath.h>
#include <string>
#pragma comment( lib,"winmm.lib" )

// CNewFolderExt

DWORD CNewFolderExt::_ThreadProc()
{
	IShellItemArray* psia;
	HRESULT hr = CoGetInterfaceAndReleaseStream(_pstmShellItemArray, IID_PPV_ARGS(&psia));
	_pstmShellItemArray = NULL;
	if (SUCCEEDED(hr))
	{
		DoCreateAndMoveItems(NULL, psia);
		psia->Release();
	}

	return 0;
}

/// <summary>
/// https://www.cnblogs.com/weiym/p/3928348.html
/// </summary>
/// <param name="hIcon"></param>
/// <param name="pTargetSize"></param>
/// <returns></returns>
HBITMAP CNewFolderExt::IconToBitmap(HICON hIcon, SIZE* pTargetSize = NULL)
{
	ICONINFO info = { 0 };
	if (hIcon == NULL
		|| !GetIconInfo(hIcon, &info)
		|| !info.fIcon)
	{
		return NULL;
	}

	INT nWidth = 0;
	INT nHeight = 0;
	if (pTargetSize != NULL)
	{
		nWidth = pTargetSize->cx;
		nHeight = pTargetSize->cy;
	}
	else
	{
		if (info.hbmColor != NULL)
		{
			BITMAP bmp = { 0 };
			GetObject(info.hbmColor, sizeof(bmp), &bmp);

			nWidth = bmp.bmWidth;
			nHeight = bmp.bmHeight;
		}
	}

	if (info.hbmColor != NULL)
	{
		DeleteObject(info.hbmColor);
		info.hbmColor = NULL;
	}

	if (info.hbmMask != NULL)
	{
		DeleteObject(info.hbmMask);
		info.hbmMask = NULL;
	}

	if (nWidth <= 0
		|| nHeight <= 0)
	{
		return NULL;
	}

	INT nPixelCount = nWidth * nHeight;

	HDC dc = GetDC(NULL);
	INT* pData = NULL;
	HDC dcMem = NULL;
	HBITMAP hBmpOld = NULL;
	bool* pOpaque = NULL;
	HBITMAP dib = NULL;
	BOOL bSuccess = FALSE;

	do
	{
		BITMAPINFOHEADER bi = { 0 };
		bi.biSize = sizeof(BITMAPINFOHEADER);
		bi.biWidth = nWidth;
		bi.biHeight = -nHeight;
		bi.biPlanes = 1;
		bi.biBitCount = 32;
		bi.biCompression = BI_RGB;
		dib = CreateDIBSection(dc, (BITMAPINFO*)&bi, DIB_RGB_COLORS, (VOID**)&pData, NULL, 0);
		if (dib == NULL) break;

		memset(pData, 0, nPixelCount * 4);

		dcMem = CreateCompatibleDC(dc);
		if (dcMem == NULL) break;

		hBmpOld = (HBITMAP)SelectObject(dcMem, dib);
		::DrawIconEx(dcMem, 0, 0, hIcon, nWidth, nHeight, 0, NULL, DI_MASK);

		pOpaque = new(std::nothrow) bool[nPixelCount];
		if (pOpaque == NULL) break;
		for (INT i = 0; i < nPixelCount; ++i)
		{
			pOpaque[i] = !pData[i];
		}

		memset(pData, 0, nPixelCount * 4);
		::DrawIconEx(dcMem, 0, 0, hIcon, nWidth, nHeight, 0, NULL, DI_NORMAL);

		BOOL bPixelHasAlpha = FALSE;
		UINT* pPixel = (UINT*)pData;
		for (INT i = 0; i < nPixelCount; ++i, ++pPixel)
		{
			if ((*pPixel & 0xff000000) != 0)
			{
				bPixelHasAlpha = TRUE;
				break;
			}
		}

		if (!bPixelHasAlpha)
		{
			pPixel = (UINT*)pData;
			for (INT i = 0; i < nPixelCount; ++i, ++pPixel)
			{
				if (pOpaque[i])
				{
					*pPixel |= 0xFF000000;
				}
				else
				{
					*pPixel &= 0x00FFFFFF;
				}
			}
		}

		bSuccess = TRUE;

	} while (FALSE);


	if (pOpaque != NULL)
	{
		delete[]pOpaque;
		pOpaque = NULL;
	}

	if (dcMem != NULL)
	{
		SelectObject(dcMem, hBmpOld);
		DeleteDC(dcMem);
	}

	ReleaseDC(NULL, dc);

	if (!bSuccess)
	{
		if (dib != NULL)
		{
			DeleteObject(dib);
			dib = NULL;
		}
	}

	return dib;
}

HRESULT __stdcall CNewFolderExt::Initialize(PCIDLIST_ABSOLUTE pidlFolder, IDataObject* pdtobj, HKEY hkeyProgID)
{
	m_spdo = pdtobj;
	bool r = selected_files.empty();

	{
		/*
		* 检查是否存在可移动的文件，如果只存在一项且该项为文件夹，则不显示
		*/
		if (SUCCEEDED(GetShellItemArrayFromDataObject(m_spdo, &spsia))) {
			DWORD file_count = 0;
			spsia->GetCount(&file_count);
			for (DWORD i = 0; i < file_count; i++) {
				CComPtr<IShellItem> item;
				LPWSTR name_buffer;
				spsia->GetItemAt(i, &item);
				item->GetDisplayName(SIGDN::SIGDN_DESKTOPABSOLUTEPARSING, &name_buffer);
				ATL::CString item_name(name_buffer);
				selected_files.push_back(item_name);
				CoTaskMemFree(name_buffer);
			}

			if (selected_files.size() == 1) {
				ATL::CPath onePath(selected_files.at(0));
				if (onePath.IsDirectory()) {
					return E_INVALIDARG;
				}
			}
			return S_OK;
		}
		else {
			return E_FAIL;
		}
	}
	return E_FAIL;
}

HRESULT __stdcall CNewFolderExt::GetShellItemArrayFromDataObject(_In_ IUnknown* dataSource, _COM_Outptr_ IShellItemArray** items)
{
	*items = nullptr;
	CComPtr<IDataObject> dataObj;
	HRESULT hr;
	if (SUCCEEDED(dataSource->QueryInterface(IID_PPV_ARGS(&dataObj))))
	{
		hr = SHCreateShellItemArrayFromDataObject(dataObj, IID_PPV_ARGS(items));
	}
	else
	{
		hr = dataSource->QueryInterface(IID_PPV_ARGS(items));
	}

	return hr;
}

HRESULT __stdcall CNewFolderExt::QueryContextMenu(HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags)
{
	if (uFlags & CMF_DEFAULTONLY) {
		return E_FAIL;
	}


	MENUITEMINFO mii = { 0 };
	mii.cbSize = sizeof(MENUITEMINFO);
	mii.fMask = MIIM_BITMAP | MIIM_STRING | MIIM_FTYPE | MIIM_ID;
	mii.fType = MFT_STRING;
	mii.dwTypeData = m_contextmenu_name.GetBuffer();
	mii.wID = idCmdFirst++;
	mii.hbmpItem = m_icon;

	InsertMenuItem(hmenu, 1, TRUE, (LPCMENUITEMINFO)&mii);

	return MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_NULL, 1);
}

HRESULT __stdcall CNewFolderExt::InvokeCommand(CMINVOKECOMMANDINFO* pici)
{
	if ((IS_INTRESOURCE(pici->lpVerb)) && (LOWORD(pici->lpVerb) == 0)) {
		HRESULT hr = CoMarshalInterThreadInterfaceInStream(__uuidof(spsia), spsia, &_pstmShellItemArray);
		if (SUCCEEDED(hr))
		{
			AddRef();
			if (!SHCreateThread(s_ThreadProc, this, CTF_COINIT_STA | CTF_PROCESS_REF, NULL))
			{
				Release();
			}
		}
		return S_OK;
	}
	else {
		return E_FAIL;
	}
}

/// <summary>
/// 执行创建文件夹并将选择项移动到文件夹内的操作
/// </summary>
/// <param name="pici"></param>
/// <param name="psiItemArray"></param>
/// <returns></returns>
HRESULT __stdcall CNewFolderExt::DoCreateAndMoveItems(CMINVOKECOMMANDINFO* pici, IShellItemArray* psiItemArray)
{
	HRESULT hr = E_FAIL;

	ATL::CString target_path;
	ATL::CString common_part = find_common_prefix(selected_files, &target_path);
	{
		//如果没有共同前导子串，那么以第一个文件的文件名为基础，加一个随机数作为新的common Part
		if (common_part.Trim().GetLength() == 0) {
			common_part = extract_filename_without_ext(selected_files.at(0));
			srand(timeGetTime());
			common_part.Append(L"-");
			common_part.Append(std::to_wstring(rand() * 7 % 100).c_str());
		}
	}
	hr = CoInitialize(NULL);
	if (FAILED(hr)) return hr;

	CComPtr<IFileOperation> pfo;
	hr = CoCreateInstance(CLSID_FileOperation, NULL, CLSCTX_ALL, IID_PPV_ARGS(&pfo));
	if (FAILED(hr)) return hr;

	//此处似乎不应该使用pici->hwnd，待考
	HWND hwnd = pici ? pici->hwnd : GetActiveWindow();
	pfo->SetOwnerWindow(hwnd);

	//设置一下Pfo的标志位，此处不设置也可
	pfo->SetOperationFlags(FOF_ALLOWUNDO | FOF_SIMPLEPROGRESS | FOF_NOCONFIRMMKDIR);


	//要生成的文件夹路径
	CComPtr<IShellItem> pDstFolder;
	ATL::CString path_of_the_new_folder = combine_path(target_path, common_part);

	if (!PathIsDirectory(path_of_the_new_folder.GetString())) {
		//如果目标文件夹不存在的话，就创建一个
		bool rs = CreateDirectory(path_of_the_new_folder.GetString(), NULL);
		if (!rs) {
			return HRESULT_FROM_WIN32(GetLastError());
		}
		//通知Shell
		SHChangeNotify(SHCNE_MKDIR, SHCNF_PATH, path_of_the_new_folder.GetString(), NULL);
	}

	//把目标文件夹创建为IShellItem，给pfo使用
	hr = SHCreateItemFromParsingName(path_of_the_new_folder.GetString(), NULL, IID_PPV_ARGS(&pDstFolder));
	if (FAILED(hr)) return hr;

	if (!psiItemArray) {
		for (auto iter = selected_files.begin(); iter != selected_files.end(); iter++) {
			{
				//避免同名文件夹移动
				if ((*iter).CompareNoCase(path_of_the_new_folder) == 0) {
					continue;
				}
			}
			CComPtr<IShellItem> pitem;
			hr = SHCreateItemFromParsingName((*iter).GetString(), NULL, IID_PPV_ARGS(&pitem));
			if (SUCCEEDED(hr)) {
				pfo->MoveItem(pitem, pDstFolder, extract_filename((*iter)).GetString(), NULL);
				/*
				* 2022/3/18 对于每一个移动的文件，向shell发送通知
				*/
				SHChangeNotify(SHCNE_DELETE, SHCNF_IDLIST, pitem, NULL);
			}
		}

	}
	else {
		pfo->MoveItems(psiItemArray, pDstFolder);
	}
	SHChangeNotify(SHCNE_ALLEVENTS, SHCNF_FLUSHNOWAIT, NULL, NULL);
	//执行pfo操作
	hr = pfo->PerformOperations();
	CoUninitialize();
	selectItem(&path_of_the_new_folder);
	return hr;
}
/// <summary>
/// 以线程方式执行重命名操作，目前大部分情况下可用
/// </summary>
/// <param name="pArguments">threadParam结构</param>
/// <returns></returns>
unsigned __stdcall selectItem(void* pArguments) {

	if (FAILED(CoInitialize(NULL))) {
		return 0;
	};
	ATL::CString* folder_to_select = static_cast<ATL::CString*>(pArguments);

	CComPtr<IShellWindows> shellwindow;
	HRESULT h = CoCreateInstance(CLSID_ShellWindows, NULL, CLSCTX_ALL, IID_PPV_ARGS(&shellwindow));
	if (FAILED(h)) { return 0; }

	long count;
	shellwindow->get_Count(&count);
	for (long i = 0; i < count; i++) {
		CComPtr<IDispatch> pdisp;
		CComVariant va(i, VT_I4);
		if (SUCCEEDED(shellwindow->Item(va, &pdisp)) && (!!pdisp)) {
			CComPtr<IWebBrowserApp> pwba;
			h = pdisp->QueryInterface(IID_PPV_ARGS(&pwba));
			if (FAILED(h)) { continue; }
			HWND hwba;
			if (SUCCEEDED(pwba->get_HWND((LONG_PTR*)&hwba))) {
				CComPtr<IServiceProvider> psp;
				h = pwba->QueryInterface(IID_PPV_ARGS(&psp));
				if (FAILED(h)) { continue; }
				CComPtr<IShellBrowser> psb;
				h = psp->QueryService(SID_STopLevelBrowser, IID_PPV_ARGS(&psb));
				if (FAILED(h)) { continue; }
				CComPtr<IShellView> psv;
				h = psb->QueryActiveShellView(&psv);
				if (FAILED(h)) { continue; }
				psv->Refresh();
				CComPtr<IFolderView2> pfv;
				h = psv->QueryInterface(IID_PPV_ARGS(&pfv));
				if (FAILED(h)) { continue; }
				CComPtr<IShellItemArray> items;
				if (SUCCEEDED(pfv->Items(SVGIO_ALLVIEW, IID_PPV_ARGS(&items)))) {
					DWORD count = 0;
					items->GetCount(&count);
					for (DWORD i = 0; i < count; i++) {
						IShellItem* _item;
						if (SUCCEEDED(items->GetItemAt(i, &_item))) {
							LPWSTR filename = NULL;
							if (SUCCEEDED(_item->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &filename))) {
								ATL::CPath fpath(filename);
								fpath.Canonicalize();
								if (fpath.m_strPath.CompareNoCase(*folder_to_select) == 0) {
									try {
										if (SUCCEEDED(pfv->SelectItem(i, SVSI_EDIT | SVSI_DESELECTOTHERS | SVSI_ENSUREVISIBLE | SVSI_POSITIONITEM))) {
											//PostMessage(hwba, WM_KEYDOWN, VK_F2, 0);
										}
										break;
									}
									catch (const std::exception&) {
										break;
									}
								}
							}
						}
					}
				}

			}
		}
	}
	CoUninitialize();
	return 0;
}

/// <summary>
/// 查找共同前导子串的长度（共同前缀）
/// </summary>
/// <param name="str1"></param>
/// <param name="str2"></param>
/// <returns></returns>
int CNewFolderExt::first_common_substring_length(const ATL::CString& str1, const ATL::CString& str2, int length_to_compare)
{
	/*
	* 2022/3/18 重构，增加length_to_compare参数，用于提高处理速度。
	*/
	int l = min(str1.GetLength(), str2.GetLength());
	l = min(l, length_to_compare);
	int result = l;
	for (int i = 0; i < l; i++) {
		if (str1[i] != str2[i]) {
			result = i;
			break;
		}
	}
	return result;
}

/// <summary>
/// 求一组字符串的最长公共前导子串
/// </summary>
/// <param name="strs"></param>
/// <returns></returns>
ATL::CString CNewFolderExt::longestCommonPrefix(const std::vector<ATL::CString>& strs)
{
	/*
	* 2022/3/18 重构，增加length_to_compare参数，用于提高处理速度。
	*/
	ATL::CString base = strs[0];
	int common_prefix_length = base.GetLength();
	for (int i = 1; i < strs.size(); i++) {
		common_prefix_length = first_common_substring_length(base, strs[i], common_prefix_length);
	}
	if (common_prefix_length == 0) {
		return ATL::CString("");
	}
	else {
		return base.Left(common_prefix_length);
	}
}

/// <summary>
/// 查找一系列文件的共同前导子串
/// </summary>
/// <param name="filepaths"></param>
/// <param name="default_path">新文件夹创建时的基目录</param>
/// <returns></returns>
ATL::CString CNewFolderExt::find_common_prefix(const std::vector<ATL::CString> filepaths, OUT ATL::CString* default_path)
{
	ATL::CPath base_folder(filepaths.at(0));
	base_folder.RemoveFileSpec();
	*default_path = ATL::CString(base_folder);

	std::vector<ATL::CString> filenames;

	for (auto iter = filepaths.begin(); iter != filepaths.end(); iter++) {
		ATL::CString _filename = extract_filename_without_ext(*iter);
		filenames.push_back(_filename);
	}

	ATL::CString common_part = longestCommonPrefix(filenames);

	return common_part.Trim();
}

/// <summary>
/// 提取文件名（含扩展名）
/// </summary>
/// <param name="filepath"></param>
/// <returns></returns>
ATL::CString CNewFolderExt::extract_filename(const ATL::CString filepath)
{
	ATL::CPath path(filepath);
	path.StripPath();
	return ATL::CString(path);
}

/// <summary>
/// 提取文件名（不含扩展名）
/// </summary>
/// <param name="filepath"></param>
/// <returns></returns>
ATL::CString CNewFolderExt::extract_filename_without_ext(const ATL::CString filepath)
{
	ATL::CPath path(filepath);
	path.StripPath();
	path.RemoveExtension();
	return path;
}

/// <summary>
/// 将src_path 调整到 new_base_folder文件夹下
/// </summary>
/// <param name="src_path"></param>
/// <param name="new_base_folder"></param>
/// <returns></returns>
ATL::CString CNewFolderExt::rebase_path(ATL::CString src_path, ATL::CString new_base_folder)
{
	ATL::CString filename = extract_filename(src_path);
	ATL::CPath new_path(new_base_folder);
	new_path.Combine(new_path, filename);
	return ATL::CString(new_path);
}

/// <summary>
/// 拼合路径
/// </summary>
/// <param name="folder_name"></param>
/// <param name="suffix"></param>
/// <returns></returns>
ATL::CString CNewFolderExt::combine_path(ATL::CString folder_name, ATL::CString suffix)
{
	ATL::CPath base(folder_name);
	base.Append(suffix);
	return base;
}

HRESULT __stdcall CNewFolderExt::GetCommandString(UINT_PTR idCmd, UINT uType, UINT* pReserved, CHAR* pszName, UINT cchMax)
{
	return E_NOTIMPL;
}

HRESULT __stdcall CNewFolderExt::GetTitle(IShellItemArray* psiItemArray, LPWSTR* ppszName)
{
	return SHStrDup(m_contextmenu_name.GetString(), ppszName);
}

HRESULT __stdcall CNewFolderExt::GetIcon(IShellItemArray* psiItemArray, LPWSTR* ppszIcon)
{
	UNREFERENCED_PARAMETER(psiItemArray);
	ATL::CString iconpath = L"%systemroot%\\system32\\shell32.dll, -20";
	return SHStrDup(iconpath.GetString(), ppszIcon);
}

HRESULT __stdcall CNewFolderExt::GetToolTip(IShellItemArray* psiItemArray, LPWSTR* ppszInfotip)
{
	return E_NOTIMPL;
}

HRESULT __stdcall CNewFolderExt::GetCanonicalName(GUID* pguidCommandName)
{
	*pguidCommandName = __uuidof(NewFolderExt);
	return S_OK;
}

HRESULT __stdcall CNewFolderExt::GetState(IShellItemArray* psiItemArray, BOOL fOkToBeSlow, EXPCMDSTATE* pCmdState)
{
	UNREFERENCED_PARAMETER(psiItemArray);
	*pCmdState = ECS_ENABLED;
	return S_OK;
}

HRESULT __stdcall CNewFolderExt::Invoke(IShellItemArray* psiItemArray, IBindCtx* pbc)
{
	ibindctx = pbc;
	return DoCreateAndMoveItems(nullptr, psiItemArray);
}

HRESULT __stdcall CNewFolderExt::GetFlags(EXPCMDFLAGS* pFlags)
{
	*pFlags = ECF_DEFAULT;
	return S_OK;
}

HRESULT __stdcall CNewFolderExt::EnumSubCommands(IEnumExplorerCommand** ppEnum)
{
	*ppEnum = nullptr;
	return E_NOTIMPL;
}
