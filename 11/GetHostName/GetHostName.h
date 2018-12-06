// GetHostName.h : main header file for the GETHOSTNAME application
//

#if !defined(AFX_GETHOSTNAME_H__363A29A0_36E5_4B0E_A852_B87D306437B4__INCLUDED_)
#define AFX_GETHOSTNAME_H__363A29A0_36E5_4B0E_A852_B87D306437B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetHostNameApp:
// See GetHostName.cpp for the implementation of this class
//

class CGetHostNameApp : public CWinApp
{
public:
	CGetHostNameApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetHostNameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetHostNameApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETHOSTNAME_H__363A29A0_36E5_4B0E_A852_B87D306437B4__INCLUDED_)
