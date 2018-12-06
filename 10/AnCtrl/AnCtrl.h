// AnCtrl.h : main header file for the ANCTRL application
//

#if !defined(AFX_ANCTRL_H__00FF5FED_C2B3_4B36_AD0F_F4468FD14F83__INCLUDED_)
#define AFX_ANCTRL_H__00FF5FED_C2B3_4B36_AD0F_F4468FD14F83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAnCtrlApp:
// See AnCtrl.cpp for the implementation of this class
//

class CAnCtrlApp : public CWinApp
{
public:
	CAnCtrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAnCtrlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANCTRL_H__00FF5FED_C2B3_4B36_AD0F_F4468FD14F83__INCLUDED_)
