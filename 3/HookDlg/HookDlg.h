// HookDlg.h : main header file for the HOOKDLG application
//

#if !defined(AFX_HOOKDLG_H__67F05071_ED6F_414A_9A24_D8233FC012EC__INCLUDED_)
#define AFX_HOOKDLG_H__67F05071_ED6F_414A_9A24_D8233FC012EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHookDlgApp:
// See HookDlg.cpp for the implementation of this class
//

class CHookDlgApp : public CWinApp
{
public:
	CHookDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHookDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHookDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOOKDLG_H__67F05071_ED6F_414A_9A24_D8233FC012EC__INCLUDED_)
