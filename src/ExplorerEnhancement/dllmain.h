// dllmain.h: 模块类的声明。

class CExplorerEnhancementModule : public ATL::CAtlDllModuleT< CExplorerEnhancementModule >
{
public :
	DECLARE_LIBID(LIBID_ExplorerEnhancementLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_EXPLORERENHANCEMENT, "{ad8e9b75-e82e-4c6a-830b-4acf8c407d6c}")
};

extern class CExplorerEnhancementModule _AtlModule;
