

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_INewFolderExt,0xbe2e806b,0xf1ab,0x422f,0x89,0xf7,0x8c,0xd0,0x7f,0x26,0x9c,0xfc);


MIDL_DEFINE_GUID(IID, IID_IBreakFolderExt,0x303c2141,0x664e,0x4698,0x88,0x11,0x58,0xa0,0x22,0x0d,0x52,0x8b);


MIDL_DEFINE_GUID(IID, LIBID_ExplorerEnhancementLib,0xad8e9b75,0xe82e,0x4c6a,0x83,0x0b,0x4a,0xcf,0x8c,0x40,0x7d,0x6c);


MIDL_DEFINE_GUID(CLSID, CLSID_NewFolderExt,0xc36a65af,0x0a1e,0x4e09,0x97,0x29,0x6d,0xa3,0xe4,0xe4,0x46,0x1a);


MIDL_DEFINE_GUID(CLSID, CLSID_BreakFolderExt,0xf2a0aaf9,0x2961,0x4465,0xa8,0x43,0x88,0x43,0x83,0xfc,0xd1,0x3b);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



