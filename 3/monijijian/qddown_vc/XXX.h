// XXX.h : main header file for the XXX application
//

#if !defined(AFX_XXX_H__D11A89F8_6786_4C76_A6E9_0CD71F4202D4__INCLUDED_)
#define AFX_XXX_H__D11A89F8_6786_4C76_A6E9_0CD71F4202D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CXXXApp:
// See XXX.cpp for the implementation of this class
//

class CXXXApp : public CWinApp
{
public:
	CXXXApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXXXApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CXXXApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XXX_H__D11A89F8_6786_4C76_A6E9_0CD71F4202D4__INCLUDED_)
