// SystemButton.h : main header file for the SYSTEMBUTTON application
//

#if !defined(AFX_SYSTEMBUTTON_H__88BB072B_56C1_46E4_B3C6_58201AFE0735__INCLUDED_)
#define AFX_SYSTEMBUTTON_H__88BB072B_56C1_46E4_B3C6_58201AFE0735__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSystemButtonApp:
// See SystemButton.cpp for the implementation of this class
//

class CSystemButtonApp : public CWinApp
{
public:
	CSystemButtonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSystemButtonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSystemButtonApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTEMBUTTON_H__88BB072B_56C1_46E4_B3C6_58201AFE0735__INCLUDED_)
