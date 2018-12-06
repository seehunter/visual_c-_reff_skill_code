// EasyFollow.h : main header file for the EASYFOLLOW application
//

#if !defined(AFX_EASYFOLLOW_H__BB422551_C42D_4CD4_86B6_594B25A7F546__INCLUDED_)
#define AFX_EASYFOLLOW_H__BB422551_C42D_4CD4_86B6_594B25A7F546__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEasyFollowApp:
// See EasyFollow.cpp for the implementation of this class
//

class CEasyFollowApp : public CWinApp
{
public:
	CEasyFollowApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEasyFollowApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEasyFollowApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EASYFOLLOW_H__BB422551_C42D_4CD4_86B6_594B25A7F546__INCLUDED_)
