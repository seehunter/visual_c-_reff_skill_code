// StaticNotify.h : main header file for the STATICNOTIFY application
//

#if !defined(AFX_STATICNOTIFY_H__4B50E0A2_B10C_47C4_8798_2A0B5035EAD3__INCLUDED_)
#define AFX_STATICNOTIFY_H__4B50E0A2_B10C_47C4_8798_2A0B5035EAD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStaticNotifyApp:
// See StaticNotify.cpp for the implementation of this class
//

class CStaticNotifyApp : public CWinApp
{
public:
	CStaticNotifyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticNotifyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStaticNotifyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICNOTIFY_H__4B50E0A2_B10C_47C4_8798_2A0B5035EAD3__INCLUDED_)
