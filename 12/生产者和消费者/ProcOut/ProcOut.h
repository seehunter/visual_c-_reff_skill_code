/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Jan 22 01:27:36 2008
 */
/* Compiler settings for E:\Visual C++编程技巧与代码参考\代码\第12章\生产者和消费者\ProcOut\ProcOut.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ProcOut_h__
#define __ProcOut_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IObject_FWD_DEFINED__
#define __IObject_FWD_DEFINED__
typedef interface IObject IObject;
#endif 	/* __IObject_FWD_DEFINED__ */


#ifndef __Object_FWD_DEFINED__
#define __Object_FWD_DEFINED__

#ifdef __cplusplus
typedef class Object Object;
#else
typedef struct Object Object;
#endif /* __cplusplus */

#endif 	/* __Object_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IObject_INTERFACE_DEFINED__
#define __IObject_INTERFACE_DEFINED__

/* interface IObject */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6CEC51A9-E57B-49B3-839B-880ADD12DFBD")
    IObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Produce( 
            /* [in] */ double x) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Customer( 
            /* [in] */ double x) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentCount( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentCount( 
            /* [in] */ double newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IObject __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IObject __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IObject __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Produce )( 
            IObject __RPC_FAR * This,
            /* [in] */ double x);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Customer )( 
            IObject __RPC_FAR * This,
            /* [in] */ double x);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CurrentCount )( 
            IObject __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CurrentCount )( 
            IObject __RPC_FAR * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } IObjectVtbl;

    interface IObject
    {
        CONST_VTBL struct IObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IObject_Produce(This,x)	\
    (This)->lpVtbl -> Produce(This,x)

#define IObject_Customer(This,x)	\
    (This)->lpVtbl -> Customer(This,x)

#define IObject_get_CurrentCount(This,pVal)	\
    (This)->lpVtbl -> get_CurrentCount(This,pVal)

#define IObject_put_CurrentCount(This,newVal)	\
    (This)->lpVtbl -> put_CurrentCount(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IObject_Produce_Proxy( 
    IObject __RPC_FAR * This,
    /* [in] */ double x);


void __RPC_STUB IObject_Produce_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IObject_Customer_Proxy( 
    IObject __RPC_FAR * This,
    /* [in] */ double x);


void __RPC_STUB IObject_Customer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IObject_get_CurrentCount_Proxy( 
    IObject __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IObject_get_CurrentCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IObject_put_CurrentCount_Proxy( 
    IObject __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IObject_put_CurrentCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IObject_INTERFACE_DEFINED__ */



#ifndef __PROCOUTLib_LIBRARY_DEFINED__
#define __PROCOUTLib_LIBRARY_DEFINED__

/* library PROCOUTLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_PROCOUTLib;

EXTERN_C const CLSID CLSID_Object;

#ifdef __cplusplus

class DECLSPEC_UUID("46BE1C21-DFC5-4529-A48D-E7B46E158F0E")
Object;
#endif
#endif /* __PROCOUTLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
