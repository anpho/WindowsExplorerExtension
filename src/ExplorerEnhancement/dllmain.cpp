﻿// dllmain.cpp: DllMain 的实现。

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "ExplorerEnhancement_i.h"
#include "dllmain.h"

CExplorerEnhancementModule _AtlModule;

// DLL 入口点
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved);
}
