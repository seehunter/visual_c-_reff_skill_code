// Object.h : Declaration of the CObject

#ifndef __OBJECT_H_
#define __OBJECT_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CObject
class ATL_NO_VTABLE CObject : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CObject, &CLSID_Object>,
	public IDispatchImpl<IObject, &IID_IObject, &LIBID_PROCOUTLib>
{
public:
	CObject()
	{
		m_dCurrent = 100;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_OBJECT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CObject)
	COM_INTERFACE_ENTRY(IObject)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IObject
public:
	STDMETHOD(get_CurrentCount)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_CurrentCount)(/*[in]*/ double newVal);
	STDMETHOD(Customer)(/*[in]*/double x);
	STDMETHOD(Produce)(/*[in]*/double x);
protected:
	double m_dCurrent;
};

#endif //__OBJECT_H_
