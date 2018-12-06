// Object.cpp : Implementation of CObject
#include "stdafx.h"
#include "ProcOut.h"
#include "Object.h"

/////////////////////////////////////////////////////////////////////////////
// CObject


STDMETHODIMP CObject::Produce(double x)
{
	// TODO: Add your implementation code here
    m_dCurrent = m_dCurrent + x;
	return S_OK;
}

STDMETHODIMP CObject::Customer(double x)
{
	// TODO: Add your implementation code here
    m_dCurrent = m_dCurrent - x;
	if(m_dCurrent<0)
	{
        MessageBox(NULL,"×ÊÔ´ºÄ¾¡","ºÄ¾¡",MB_OK);
		m_dCurrent = 0;
	}
	return S_OK;
}

STDMETHODIMP CObject::get_CurrentCount(double *pVal)
{
	// TODO: Add your implementation code here
    *pVal = m_dCurrent;
	return S_OK;
}

STDMETHODIMP CObject::put_CurrentCount(double newVal)
{
	// TODO: Add your implementation code here
    m_dCurrent = m_dCurrent;
	return S_OK;
}
