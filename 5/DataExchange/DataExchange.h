// DataExchange.h : main header file for the DATAEXCHANGE application
//

#if !defined(AFX_DATAEXCHANGE_H__01479C2A_EEAF_4564_9EEE_B9DD7CBC5C6F__INCLUDED_)
#define AFX_DATAEXCHANGE_H__01479C2A_EEAF_4564_9EEE_B9DD7CBC5C6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDataExchangeApp:
// See DataExchange.cpp for the implementation of this class
//

class CDataExchangeApp : public CWinApp
{
public:
	CDataExchangeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataExchangeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDataExchangeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAEXCHANGE_H__01479C2A_EEAF_4564_9EEE_B9DD7CBC5C6F__INCLUDED_)
