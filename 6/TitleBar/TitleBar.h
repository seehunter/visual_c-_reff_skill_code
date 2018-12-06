// TitleBar.h : main header file for the TITLEBAR application
//

#if !defined(AFX_TITLEBAR_H__928DD607_D6A2_4C86_AA7C_D0DF0BC6A280__INCLUDED_)
#define AFX_TITLEBAR_H__928DD607_D6A2_4C86_AA7C_D0DF0BC6A280__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTitleBarApp:
// See TitleBar.cpp for the implementation of this class
//

class CTitleBarApp : public CWinApp
{
public:
	CTitleBarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTitleBarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTitleBarApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TITLEBAR_H__928DD607_D6A2_4C86_AA7C_D0DF0BC6A280__INCLUDED_)
