// LockRect.h : main header file for the LOCKRECT application
//

#if !defined(AFX_LOCKRECT_H__DAC3945C_774E_4992_B098_A1903BA1CD28__INCLUDED_)
#define AFX_LOCKRECT_H__DAC3945C_774E_4992_B098_A1903BA1CD28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLockRectApp:
// See LockRect.cpp for the implementation of this class
//

class CLockRectApp : public CWinApp
{
public:
	CLockRectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLockRectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLockRectApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOCKRECT_H__DAC3945C_774E_4992_B098_A1903BA1CD28__INCLUDED_)
