// BackGround.h : main header file for the BACKGROUND application
//

#if !defined(AFX_BACKGROUND_H__BE39B772_21AA_4CDC_B0AA_A04EDC835CD6__INCLUDED_)
#define AFX_BACKGROUND_H__BE39B772_21AA_4CDC_B0AA_A04EDC835CD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBackGroundApp:
// See BackGround.cpp for the implementation of this class
//

class CBackGroundApp : public CWinApp
{
public:
	CBackGroundApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackGroundApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBackGroundApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKGROUND_H__BE39B772_21AA_4CDC_B0AA_A04EDC835CD6__INCLUDED_)
