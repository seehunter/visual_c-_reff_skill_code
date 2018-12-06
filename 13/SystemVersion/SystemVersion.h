// SystemVersion.h : main header file for the SYSTEMVERSION application
//

#if !defined(AFX_SYSTEMVERSION_H__8D273482_F8AC_41FD_808B_5E539779D4A5__INCLUDED_)
#define AFX_SYSTEMVERSION_H__8D273482_F8AC_41FD_808B_5E539779D4A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSystemVersionApp:
// See SystemVersion.cpp for the implementation of this class
//

class CSystemVersionApp : public CWinApp
{
public:
	CSystemVersionApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSystemVersionApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSystemVersionApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTEMVERSION_H__8D273482_F8AC_41FD_808B_5E539779D4A5__INCLUDED_)
