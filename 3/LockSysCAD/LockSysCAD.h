// LockSysCAD.h : main header file for the LOCKSYSCAD application
//

#if !defined(AFX_LOCKSYSCAD_H__3227818F_CD89_4A2E_ADB6_6B5F209F37A6__INCLUDED_)
#define AFX_LOCKSYSCAD_H__3227818F_CD89_4A2E_ADB6_6B5F209F37A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLockSysCADApp:
// See LockSysCAD.cpp for the implementation of this class
//

class CLockSysCADApp : public CWinApp
{
public:
	CLockSysCADApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLockSysCADApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLockSysCADApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOCKSYSCAD_H__3227818F_CD89_4A2E_ADB6_6B5F209F37A6__INCLUDED_)
