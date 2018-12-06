// Cursor.h : main header file for the CURSOR application
//

#if !defined(AFX_CURSOR_H__C138E325_9151_49B0_8317_AEF7A6C984BA__INCLUDED_)
#define AFX_CURSOR_H__C138E325_9151_49B0_8317_AEF7A6C984BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCursorApp:
// See Cursor.cpp for the implementation of this class
//

class CCursorApp : public CWinApp
{
public:
	CCursorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCursorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCursorApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CURSOR_H__C138E325_9151_49B0_8317_AEF7A6C984BA__INCLUDED_)
