// ShutComputer.h : main header file for the SHUTCOMPUTER application
//

#if !defined(AFX_SHUTCOMPUTER_H__AE86E473_E588_42D0_91F6_E575BA951456__INCLUDED_)
#define AFX_SHUTCOMPUTER_H__AE86E473_E588_42D0_91F6_E575BA951456__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShutComputerApp:
// See ShutComputer.cpp for the implementation of this class
//

class CShutComputerApp : public CWinApp
{
public:
	CShutComputerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShutComputerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShutComputerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHUTCOMPUTER_H__AE86E473_E588_42D0_91F6_E575BA951456__INCLUDED_)
