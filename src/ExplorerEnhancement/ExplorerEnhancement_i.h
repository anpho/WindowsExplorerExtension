

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ExplorerEnhancement.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0626 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ExplorerEnhancement_i_h__
#define __ExplorerEnhancement_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if _CONTROL_FLOW_GUARD_XFG
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __INewFolderExt_FWD_DEFINED__
#define __INewFolderExt_FWD_DEFINED__
typedef interface INewFolderExt INewFolderExt;

#endif 	/* __INewFolderExt_FWD_DEFINED__ */


#ifndef __IBreakFolderExt_FWD_DEFINED__
#define __IBreakFolderExt_FWD_DEFINED__
typedef interface IBreakFolderExt IBreakFolderExt;

#endif 	/* __IBreakFolderExt_FWD_DEFINED__ */


#ifndef __NewFolderExt_FWD_DEFINED__
#define __NewFolderExt_FWD_DEFINED__

#ifdef __cplusplus
typedef class NewFolderExt NewFolderExt;
#else
typedef struct NewFolderExt NewFolderExt;
#endif /* __cplusplus */

#endif 	/* __NewFolderExt_FWD_DEFINED__ */


#ifndef __BreakFolderExt_FWD_DEFINED__
#define __BreakFolderExt_FWD_DEFINED__

#ifdef __cplusplus
typedef class BreakFolderExt BreakFolderExt;
#else
typedef struct BreakFolderExt BreakFolderExt;
#endif /* __cplusplus */

#endif 	/* __BreakFolderExt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __INewFolderExt_INTERFACE_DEFINED__
#define __INewFolderExt_INTERFACE_DEFINED__

/* interface INewFolderExt */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_INewFolderExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("be2e806b-f1ab-422f-89f7-8cd07f269cfc")
    INewFolderExt : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct INewFolderExtVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INewFolderExt * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INewFolderExt * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INewFolderExt * This);
        
        END_INTERFACE
    } INewFolderExtVtbl;

    interface INewFolderExt
    {
        CONST_VTBL struct INewFolderExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INewFolderExt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INewFolderExt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INewFolderExt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INewFolderExt_INTERFACE_DEFINED__ */


#ifndef __IBreakFolderExt_INTERFACE_DEFINED__
#define __IBreakFolderExt_INTERFACE_DEFINED__

/* interface IBreakFolderExt */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBreakFolderExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("303c2141-664e-4698-8811-58a0220d528b")
    IBreakFolderExt : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IBreakFolderExtVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBreakFolderExt * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBreakFolderExt * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBreakFolderExt * This);
        
        END_INTERFACE
    } IBreakFolderExtVtbl;

    interface IBreakFolderExt
    {
        CONST_VTBL struct IBreakFolderExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBreakFolderExt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBreakFolderExt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBreakFolderExt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBreakFolderExt_INTERFACE_DEFINED__ */



#ifndef __ExplorerEnhancementLib_LIBRARY_DEFINED__
#define __ExplorerEnhancementLib_LIBRARY_DEFINED__

/* library ExplorerEnhancementLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ExplorerEnhancementLib;

EXTERN_C const CLSID CLSID_NewFolderExt;

#ifdef __cplusplus

class DECLSPEC_UUID("c36a65af-0a1e-4e09-9729-6da3e4e4461a")
NewFolderExt;
#endif

EXTERN_C const CLSID CLSID_BreakFolderExt;

#ifdef __cplusplus

class DECLSPEC_UUID("f2a0aaf9-2961-4465-a843-884383fcd13b")
BreakFolderExt;
#endif
#endif /* __ExplorerEnhancementLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


