// DownPullButton.h : main header file for the DOWNPULLBUTTON application
//

#if !defined(AFX_DOWNPULLBUTTON_H__94F7A5C6_916F_4119_B842_28406BF4686C__INCLUDED_)
#define AFX_DOWNPULLBUTTON_H__94F7A5C6_916F_4119_B842_28406BF4686C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDownPullButtonApp:
// See DownPullButton.cpp for the implementation of this class
//

class CDownPullButtonApp : public CWinApp
{
public:
	CDownPullButtonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownPullButtonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDownPullButtonApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNPULLBUTTON_H__94F7A5C6_916F_4119_B842_28406BF4686C__INCLUDED_)
