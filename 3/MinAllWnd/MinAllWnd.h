// MinAllWnd.h : main header file for the MINALLWND application
//

#if !defined(AFX_MINALLWND_H__91E27E0A_8B55_4EB7_AE86_8B9058648207__INCLUDED_)
#define AFX_MINALLWND_H__91E27E0A_8B55_4EB7_AE86_8B9058648207__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMinAllWndApp:
// See MinAllWnd.cpp for the implementation of this class
//

class CMinAllWndApp : public CWinApp
{
public:
	CMinAllWndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMinAllWndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMinAllWndApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MINALLWND_H__91E27E0A_8B55_4EB7_AE86_8B9058648207__INCLUDED_)
