// ViewTray.h : main header file for the VIEWTRAY application
//

#if !defined(AFX_VIEWTRAY_H__0F846E72_E9BD_438D_A88C_10C2F67812F4__INCLUDED_)
#define AFX_VIEWTRAY_H__0F846E72_E9BD_438D_A88C_10C2F67812F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CViewTrayApp:
// See ViewTray.cpp for the implementation of this class
//

class CViewTrayApp : public CWinApp
{
public:
	CViewTrayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewTrayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CViewTrayApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWTRAY_H__0F846E72_E9BD_438D_A88C_10C2F67812F4__INCLUDED_)
