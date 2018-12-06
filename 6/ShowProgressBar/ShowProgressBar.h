// ShowProgressBar.h : main header file for the SHOWPROGRESSBAR application
//

#if !defined(AFX_SHOWPROGRESSBAR_H__BCD8EEB0_53CB_413C_9581_2FAD8738A9BD__INCLUDED_)
#define AFX_SHOWPROGRESSBAR_H__BCD8EEB0_53CB_413C_9581_2FAD8738A9BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowProgressBarApp:
// See ShowProgressBar.cpp for the implementation of this class
//

class CShowProgressBarApp : public CWinApp
{
public:
	CShowProgressBarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowProgressBarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CShowProgressBarApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWPROGRESSBAR_H__BCD8EEB0_53CB_413C_9581_2FAD8738A9BD__INCLUDED_)
