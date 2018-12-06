// InjectHook.h : main header file for the INJECTHOOK application
//

#if !defined(AFX_INJECTHOOK_H__E0E9D56D_B906_43CC_A879_8D2BE5EEDDDA__INCLUDED_)
#define AFX_INJECTHOOK_H__E0E9D56D_B906_43CC_A879_8D2BE5EEDDDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CInjectHookApp:
// See InjectHook.cpp for the implementation of this class
//

class CInjectHookApp : public CWinApp
{
public:
	CInjectHookApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInjectHookApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CInjectHookApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INJECTHOOK_H__E0E9D56D_B906_43CC_A879_8D2BE5EEDDDA__INCLUDED_)
