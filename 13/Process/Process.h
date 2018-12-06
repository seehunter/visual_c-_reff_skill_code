// Process.h : main header file for the PROCESS application
//

#if !defined(AFX_PROCESS_H__F972477F_A228_4FC3_8AB7_DB12A9E82C9B__INCLUDED_)
#define AFX_PROCESS_H__F972477F_A228_4FC3_8AB7_DB12A9E82C9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProcessApp:
// See Process.cpp for the implementation of this class
//

class CProcessApp : public CWinApp
{
public:
	CProcessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CProcessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCESS_H__F972477F_A228_4FC3_8AB7_DB12A9E82C9B__INCLUDED_)
