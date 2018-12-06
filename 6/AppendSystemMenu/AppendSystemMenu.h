// AppendSystemMenu.h : main header file for the APPENDSYSTEMMENU application
//

#if !defined(AFX_APPENDSYSTEMMENU_H__88F5DEF5_BA1B_4E09_B889_429B18127C0E__INCLUDED_)
#define AFX_APPENDSYSTEMMENU_H__88F5DEF5_BA1B_4E09_B889_429B18127C0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAppendSystemMenuApp:
// See AppendSystemMenu.cpp for the implementation of this class
//

class CAppendSystemMenuApp : public CWinApp
{
public:
	CAppendSystemMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAppendSystemMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAppendSystemMenuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APPENDSYSTEMMENU_H__88F5DEF5_BA1B_4E09_B889_429B18127C0E__INCLUDED_)
