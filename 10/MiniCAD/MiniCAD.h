// MiniCAD.h : main header file for the MINICAD application
//

#if !defined(AFX_MINICAD_H__9E0FC8AC_E579_4043_BD4F_72641AF62C1E__INCLUDED_)
#define AFX_MINICAD_H__9E0FC8AC_E579_4043_BD4F_72641AF62C1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMiniCADApp:
// See MiniCAD.cpp for the implementation of this class
//

class CMiniCADApp : public CWinApp
{
public:
	CMiniCADApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMiniCADApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMiniCADApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MINICAD_H__9E0FC8AC_E579_4043_BD4F_72641AF62C1E__INCLUDED_)
