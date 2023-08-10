

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if defined(_M_AMD64)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#include "ndr64types.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "ExplorerEnhancement_i.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   1                                 
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _ExplorerEnhancement_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } ExplorerEnhancement_MIDL_TYPE_FORMAT_STRING;

typedef struct _ExplorerEnhancement_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } ExplorerEnhancement_MIDL_PROC_FORMAT_STRING;

typedef struct _ExplorerEnhancement_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } ExplorerEnhancement_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

static const RPC_SYNTAX_IDENTIFIER  _NDR64_RpcTransferSyntax = 
{{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}};

#if defined(_CONTROL_FLOW_GUARD_XFG)
#define XFG_TRAMPOLINES(ObjectType)\
static unsigned long ObjectType ## _UserSize_XFG(unsigned long * pFlags, unsigned long Offset, void * pObject)\
{\
return  ObjectType ## _UserSize(pFlags, Offset, pObject);\
}\
static unsigned char * ObjectType ## _UserMarshal_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserMarshal(pFlags, pBuffer, pObject);\
}\
static unsigned char * ObjectType ## _UserUnmarshal_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserUnmarshal(pFlags, pBuffer, pObject);\
}\
static void ObjectType ## _UserFree_XFG(unsigned long * pFlags, void * pObject)\
{\
ObjectType ## _UserFree(pFlags, pObject);\
}
#define XFG_TRAMPOLINES64(ObjectType)\
static unsigned long ObjectType ## _UserSize64_XFG(unsigned long * pFlags, unsigned long Offset, void * pObject)\
{\
return  ObjectType ## _UserSize64(pFlags, Offset, pObject);\
}\
static unsigned char * ObjectType ## _UserMarshal64_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserMarshal64(pFlags, pBuffer, pObject);\
}\
static unsigned char * ObjectType ## _UserUnmarshal64_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserUnmarshal64(pFlags, pBuffer, pObject);\
}\
static void ObjectType ## _UserFree64_XFG(unsigned long * pFlags, void * pObject)\
{\
ObjectType ## _UserFree64(pFlags, pObject);\
}
#define XFG_BIND_TRAMPOLINES(HandleType, ObjectType)\
static void* ObjectType ## _bind_XFG(HandleType pObject)\
{\
return ObjectType ## _bind((ObjectType) pObject);\
}\
static void ObjectType ## _unbind_XFG(HandleType pObject, handle_t ServerHandle)\
{\
ObjectType ## _unbind((ObjectType) pObject, ServerHandle);\
}
#define XFG_TRAMPOLINE_FPTR(Function) Function ## _XFG
#else
#define XFG_TRAMPOLINES(ObjectType)
#define XFG_TRAMPOLINES64(ObjectType)
#define XFG_BIND_TRAMPOLINES(HandleType, ObjectType)
#define XFG_TRAMPOLINE_FPTR(Function) Function
#endif



extern const ExplorerEnhancement_MIDL_TYPE_FORMAT_STRING ExplorerEnhancement__MIDL_TypeFormatString;
extern const ExplorerEnhancement_MIDL_PROC_FORMAT_STRING ExplorerEnhancement__MIDL_ProcFormatString;
extern const ExplorerEnhancement_MIDL_EXPR_FORMAT_STRING ExplorerEnhancement__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO INewFolderExt_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO INewFolderExt_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IBreakFolderExt_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IBreakFolderExt_ProxyInfo;



#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const ExplorerEnhancement_MIDL_PROC_FORMAT_STRING ExplorerEnhancement__MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const ExplorerEnhancement_MIDL_TYPE_FORMAT_STRING ExplorerEnhancement__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: INewFolderExt, ver. 0.0,
   GUID={0xbe2e806b,0xf1ab,0x422f,{0x89,0xf7,0x8c,0xd0,0x7f,0x26,0x9c,0xfc}} */

#pragma code_seg(".orpc")
static const unsigned short INewFolderExt_FormatStringOffsetTable[] =
    {
    0
    };



/* Object interface: IBreakFolderExt, ver. 0.0,
   GUID={0x303c2141,0x664e,0x4698,{0x88,0x11,0x58,0xa0,0x22,0x0d,0x52,0x8b}} */

#pragma code_seg(".orpc")
static const unsigned short IBreakFolderExt_FormatStringOffsetTable[] =
    {
    0
    };



#endif /* defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if defined(_M_AMD64)




#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif


#include "ndr64types.h"
#include "pshpack8.h"


typedef 
NDR64_FORMAT_UINT32
__midl_frag1_t;
extern const __midl_frag1_t __midl_frag1;

static const __midl_frag1_t __midl_frag1 =
(NDR64_UINT32) 0 /* 0x0 */;


#include "poppack.h"



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: INewFolderExt, ver. 0.0,
   GUID={0xbe2e806b,0xf1ab,0x422f,{0x89,0xf7,0x8c,0xd0,0x7f,0x26,0x9c,0xfc}} */

#pragma code_seg(".orpc")
static const FormatInfoRef INewFolderExt_Ndr64ProcTable[] =
    {
    0
    };


static const MIDL_SYNTAX_INFO INewFolderExt_SyntaxInfo [  2 ] = 
    {
    {
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    ExplorerEnhancement__MIDL_ProcFormatString.Format,
    &INewFolderExt_FormatStringOffsetTable[-3],
    ExplorerEnhancement__MIDL_TypeFormatString.Format,
    0,
    0,
    0
    }
    ,{
    {{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}},
    0,
    0 ,
    (unsigned short *) &INewFolderExt_Ndr64ProcTable[-3],
    0,
    0,
    0,
    0
    }
    };

static const MIDL_STUBLESS_PROXY_INFO INewFolderExt_ProxyInfo =
    {
    &Object_StubDesc,
    ExplorerEnhancement__MIDL_ProcFormatString.Format,
    &INewFolderExt_FormatStringOffsetTable[-3],
    (RPC_SYNTAX_IDENTIFIER*)&_RpcTransferSyntax,
    2,
    (MIDL_SYNTAX_INFO*)INewFolderExt_SyntaxInfo
    
    };


static const MIDL_SERVER_INFO INewFolderExt_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    ExplorerEnhancement__MIDL_ProcFormatString.Format,
    (unsigned short *) &INewFolderExt_FormatStringOffsetTable[-3],
    0,
    (RPC_SYNTAX_IDENTIFIER*)&_NDR64_RpcTransferSyntax,
    2,
    (MIDL_SYNTAX_INFO*)INewFolderExt_SyntaxInfo
    };
CINTERFACE_PROXY_VTABLE(3) _INewFolderExtProxyVtbl = 
{
    0,
    &IID_INewFolderExt,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _INewFolderExtStubVtbl =
{
    &IID_INewFolderExt,
    &INewFolderExt_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IBreakFolderExt, ver. 0.0,
   GUID={0x303c2141,0x664e,0x4698,{0x88,0x11,0x58,0xa0,0x22,0x0d,0x52,0x8b}} */

#pragma code_seg(".orpc")
static const FormatInfoRef IBreakFolderExt_Ndr64ProcTable[] =
    {
    0
    };


static const MIDL_SYNTAX_INFO IBreakFolderExt_SyntaxInfo [  2 ] = 
    {
    {
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    ExplorerEnhancement__MIDL_ProcFormatString.Format,
    &IBreakFolderExt_FormatStringOffsetTable[-3],
    ExplorerEnhancement__MIDL_TypeFormatString.Format,
    0,
    0,
    0
    }
    ,{
    {{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}},
    0,
    0 ,
    (unsigned short *) &IBreakFolderExt_Ndr64ProcTable[-3],
    0,
    0,
    0,
    0
    }
    };

static const MIDL_STUBLESS_PROXY_INFO IBreakFolderExt_ProxyInfo =
    {
    &Object_StubDesc,
    ExplorerEnhancement__MIDL_ProcFormatString.Format,
    &IBreakFolderExt_FormatStringOffsetTable[-3],
    (RPC_SYNTAX_IDENTIFIER*)&_RpcTransferSyntax,
    2,
    (MIDL_SYNTAX_INFO*)IBreakFolderExt_SyntaxInfo
    
    };


static const MIDL_SERVER_INFO IBreakFolderExt_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    ExplorerEnhancement__MIDL_ProcFormatString.Format,
    (unsigned short *) &IBreakFolderExt_FormatStringOffsetTable[-3],
    0,
    (RPC_SYNTAX_IDENTIFIER*)&_NDR64_RpcTransferSyntax,
    2,
    (MIDL_SYNTAX_INFO*)IBreakFolderExt_SyntaxInfo
    };
CINTERFACE_PROXY_VTABLE(3) _IBreakFolderExtProxyVtbl = 
{
    0,
    &IID_IBreakFolderExt,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _IBreakFolderExtStubVtbl =
{
    &IID_IBreakFolderExt,
    &IBreakFolderExt_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    ExplorerEnhancement__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x8010272, /* MIDL Version 8.1.626 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x2000001, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _ExplorerEnhancement_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IBreakFolderExtProxyVtbl,
    ( CInterfaceProxyVtbl *) &_INewFolderExtProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _ExplorerEnhancement_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IBreakFolderExtStubVtbl,
    ( CInterfaceStubVtbl *) &_INewFolderExtStubVtbl,
    0
};

PCInterfaceName const _ExplorerEnhancement_InterfaceNamesList[] = 
{
    "IBreakFolderExt",
    "INewFolderExt",
    0
};


#define _ExplorerEnhancement_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _ExplorerEnhancement, pIID, n)

int __stdcall _ExplorerEnhancement_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _ExplorerEnhancement, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _ExplorerEnhancement, 2, *pIndex )
    
}

const ExtendedProxyFileInfo ExplorerEnhancement_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _ExplorerEnhancement_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _ExplorerEnhancement_StubVtblList,
    (const PCInterfaceName * ) & _ExplorerEnhancement_InterfaceNamesList,
    0, /* no delegation */
    & _ExplorerEnhancement_IID_Lookup, 
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

