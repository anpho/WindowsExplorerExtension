# New Folder Extension

## What you need

1. Visual Studio 2019+ with C++ Development Payload installed.
2. Windows of course

## What is required

1. C++
2. ATL/DLL
3. COM Operation
4. Windows Registry
5. Documents of IShellExtInit, IContextMenu

## How to build

1. Clone this repo or download it to your PC.
2. Open ```ExplorerEnhancement.sln``` in ```src``` folder.
3. Build.
4. Do ```Regsvr32``` on the generated dll in *Administrator Mode*
5. Open Explorer and check it out.

## Tips.

1. Remember to check ```Open Explorer window in a separate process``` option in Explorer's Settings.

