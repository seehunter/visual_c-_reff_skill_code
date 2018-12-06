// DlgToolBar.h : main header file for the DLGTOOLBAR application
//

#if !defined(AFX_DLGTOOLBAR_H__1F143006_33ED_4C97_A0F2_C68726CEA4EF__INCLUDED_)
#define AFX_DLGTOOLBAR_H__1F143006_33ED_4C97_A0F2_C68726CEA4EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgToolBarApp:
// See DlgToolBar.cpp for the implementation of this class
//

class CDlgToolBarApp : public CWinApp
{
public:
	CDlgToolBarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgToolBarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDlgToolBarApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTOOLBAR_H__1F143006_33ED_4C97_A0F2_C68726CEA4EF__INCLUDED_)
