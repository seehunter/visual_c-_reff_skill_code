// TitleBarLetter.h : main header file for the TITLEBARLETTER application
//

#if !defined(AFX_TITLEBARLETTER_H__30A0437D_5DA3_4CC5_857C_E692BEE6E7DD__INCLUDED_)
#define AFX_TITLEBARLETTER_H__30A0437D_5DA3_4CC5_857C_E692BEE6E7DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTitleBarLetterApp:
// See TitleBarLetter.cpp for the implementation of this class
//

class CTitleBarLetterApp : public CWinApp
{
public:
	CTitleBarLetterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTitleBarLetterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTitleBarLetterApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TITLEBARLETTER_H__30A0437D_5DA3_4CC5_857C_E692BEE6E7DD__INCLUDED_)
