// BreakFolderExt.cpp: CBreakFolderExt 的实现

#include "pch.h"
#include "BreakFolderExt.h"
#include "common.h"


// CBreakFolderExt

HRESULT __stdcall CBreakFolderExt::Initialize(PCIDLIST_ABSOLUTE pidlFolder, IDataObject* pdtobj, HKEY hkeyProgID)
{
	m_selectedFolders.clear();
	CComPtr<IShellItemArray> items;
	CComPtr<IDataObject> dataObj;

	HRESULT hr = pdtobj->QueryInterface(IID_PPV_ARGS(&dataObj));
	if (SUCCEEDED(hr)) {
		hr = SHCreateShellItemArrayFromDataObject(pdtobj, IID_PPV_ARGS(&items));
	}
	else {
		hr = pdtobj->QueryInterface(IID_PPV_ARGS(&items));
	}

	if (SUCCEEDED(hr)) {
		// Get Count of Files
		DWORD file_count = 0;
		items->GetCount(&file_count);
		// Save them to m_vSelectedFiles;
		for (DWORD i = 0; i < file_count; i++) {
			CComPtr<IShellItem> cur_item;
			LPWSTR filename_buf;
			items->GetItemAt(i, &cur_item);
			cur_item->GetDisplayName(SIGDN::SIGDN_DESKTOPABSOLUTEPARSING, &filename_buf);

			std::filesystem::path cur_filename(filename_buf);
			if (std::filesystem::is_directory(cur_filename)) {
				m_selectedFolders.push_back(cur_filename);
			}
			CoTaskMemFree(filename_buf);
		}
		return S_OK;
	}
	return E_FAIL;
}

HRESULT __stdcall CBreakFolderExt::QueryContextMenu(HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags)
{

	if (uFlags & CMF_DEFAULTONLY) return E_FAIL;
	bool enabled = true;
	if (!enabled) {
		return MAKE_HRESULT(SEVERITY_SUCCESS, 0, USHORT(0));
	}
	if (!m_hBitmap) {
		loadIcon();
	}

	// Create MenuItem.
	MENUITEMINFO mii = { 0 };
	mii.cbSize = sizeof(MENUITEMINFO);
	mii.fMask = MIIM_STRING | MIIM_FTYPE | MIIM_ID | MIIM_BITMAP;
	mii.fType = MFT_STRING;
	mii.hbmpItem = m_hBitmap;
	mii.dwTypeData = m_contextMenuName.AllocSysString();
	mii.wID = idCmdFirst++;
	InsertMenuItem(hmenu, 0, TRUE, (LPCMENUITEMINFO)&mii);

	return MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_NULL, 1);
}

HRESULT __stdcall CBreakFolderExt::InvokeCommand(CMINVOKECOMMANDINFO* pici)
{
	if ((IS_INTRESOURCE(pici->lpVerb)) && (LOWORD(pici->lpVerb) == 0)) {
		return OnBreakFoldersTriggered();
	}
	else {
		return E_FAIL;
	}
}

HRESULT __stdcall CBreakFolderExt::GetCommandString(UINT_PTR idCmd, UINT uType, UINT* pReserved, CHAR* pszName, UINT cchMax)
{
    return E_NOTIMPL;
}


HRESULT CBreakFolderExt::OnBreakFoldersTriggered()
{
	CComPtr<IFileOperation> pfo;
	HRESULT hr;
	if (SUCCEEDED(CoCreateInstance(CLSID_FileOperation, NULL, CLSCTX_ALL, IID_PPV_ARGS(&pfo)))) {
		HWND hwnd = GetActiveWindow();
		pfo->SetOwnerWindow(hwnd);
		pfo->SetOperationFlags(FOF_ALLOWUNDO | FOF_SIMPLEPROGRESS | FOF_NOCONFIRMMKDIR);

		std::filesystem::path base(m_selectedFolders[0].parent_path());
		CComPtr<IShellItem> pDstDir;
		hr = SHCreateItemFromParsingName(base.c_str(), NULL, IID_PPV_ARGS(&pDstDir));
		if (FAILED(hr)) return hr;
		for (auto i = m_selectedFolders.begin(); i < m_selectedFolders.end(); i++) {
			for (const auto& dir_entry : std::filesystem::recursive_directory_iterator(*i)) {
				if (dir_entry.is_directory()) {
					continue;
				}
				else {
					CComPtr<IShellItem> cur_file;

					HRESULT hr = SHCreateItemFromParsingName(dir_entry.path().c_str(), NULL, IID_PPV_ARGS(&cur_file));
					if (SUCCEEDED(hr)) {
						pfo->MoveItem(cur_file, pDstDir, dir_entry.path().filename().c_str(), NULL);
					}
					else {
						continue;
					}
				}
			}
		}
		hr = pfo->PerformOperations();
		SHChangeNotify(SHCNE_ALLEVENTS, SHCNF_FLUSHNOWAIT, NULL, NULL);
		return S_OK;
	}
	else {
		return E_FAIL;
	}
}

void CBreakFolderExt::loadIcon()
{
	HINSTANCE hShell32 = GetModuleHandle(L"shell32.dll");
	m_hIcon = (HICON)LoadImage(
		hShell32,
		MAKEINTRESOURCE(46),
		IMAGE_ICON,
		GetSystemMetrics(SM_CXMENUCHECK),
		GetSystemMetrics(SM_CYMENUCHECK),
		LR_LOADTRANSPARENT | LR_SHARED | LR_COLOR
	);
	m_hBitmap = IconToBitmap(m_hIcon);
	if (hShell32)DeleteObject(hShell32);
}