// OLEDB.h : main header file for the OLEDB application
//

#if !defined(AFX_OLEDB_H__C8BB1D33_5220_4794_9881_36AE8BEC5A16__INCLUDED_)
#define AFX_OLEDB_H__C8BB1D33_5220_4794_9881_36AE8BEC5A16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COLEDBApp:
// See OLEDB.cpp for the implementation of this class
//

class COLEDBApp : public CWinApp
{
public:
	COLEDBApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEDBApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COLEDBApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDB_H__C8BB1D33_5220_4794_9881_36AE8BEC5A16__INCLUDED_)
