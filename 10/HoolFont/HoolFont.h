// HoolFont.h : main header file for the HOOLFONT application
//

#if !defined(AFX_HOOLFONT_H__4385FB99_F694_4FA9_9275_433C6C3AE328__INCLUDED_)
#define AFX_HOOLFONT_H__4385FB99_F694_4FA9_9275_433C6C3AE328__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHoolFontApp:
// See HoolFont.cpp for the implementation of this class
//

class CHoolFontApp : public CWinApp
{
public:
	CHoolFontApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHoolFontApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHoolFontApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOOLFONT_H__4385FB99_F694_4FA9_9275_433C6C3AE328__INCLUDED_)
