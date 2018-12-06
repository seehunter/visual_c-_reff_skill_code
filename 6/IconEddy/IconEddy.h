// IconEddy.h : main header file for the ICONEDDY application
//

#if !defined(AFX_ICONEDDY_H__765403AB_2B7F_4235_9F2A_0B7D5C9045D9__INCLUDED_)
#define AFX_ICONEDDY_H__765403AB_2B7F_4235_9F2A_0B7D5C9045D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CIconEddyApp:
// See IconEddy.cpp for the implementation of this class
//

class CIconEddyApp : public CWinApp
{
public:
	CIconEddyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIconEddyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CIconEddyApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICONEDDY_H__765403AB_2B7F_4235_9F2A_0B7D5C9045D9__INCLUDED_)
