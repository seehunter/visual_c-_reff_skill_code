// KeyState.h : main header file for the KEYSTATE application
//

#if !defined(AFX_KEYSTATE_H__DCD688B4_D680_4502_B6D9_B6DD41E626C2__INCLUDED_)
#define AFX_KEYSTATE_H__DCD688B4_D680_4502_B6D9_B6DD41E626C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKeyStateApp:
// See KeyState.cpp for the implementation of this class
//

class CKeyStateApp : public CWinApp
{
public:
	CKeyStateApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyStateApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CKeyStateApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYSTATE_H__DCD688B4_D680_4502_B6D9_B6DD41E626C2__INCLUDED_)
