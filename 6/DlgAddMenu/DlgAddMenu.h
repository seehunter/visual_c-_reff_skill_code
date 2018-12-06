// DlgAddMenu.h : main header file for the DLGADDMENU application
//

#if !defined(AFX_DLGADDMENU_H__FD22A3E2_E47E_4CDD_9368_8C08683D8B89__INCLUDED_)
#define AFX_DLGADDMENU_H__FD22A3E2_E47E_4CDD_9368_8C08683D8B89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgAddMenuApp:
// See DlgAddMenu.cpp for the implementation of this class
//

class CDlgAddMenuApp : public CWinApp
{
public:
	CDlgAddMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAddMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDlgAddMenuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADDMENU_H__FD22A3E2_E47E_4CDD_9368_8C08683D8B89__INCLUDED_)
