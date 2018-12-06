// ProcOutTest.h : main header file for the PROCOUTTEST application
//

#if !defined(AFX_PROCOUTTEST_H__0F688955_1227_4FA8_86D1_18E139E20B74__INCLUDED_)
#define AFX_PROCOUTTEST_H__0F688955_1227_4FA8_86D1_18E139E20B74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProcOutTestApp:
// See ProcOutTest.cpp for the implementation of this class
//

class CProcOutTestApp : public CWinApp
{
public:
	CProcOutTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcOutTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CProcOutTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCOUTTEST_H__0F688955_1227_4FA8_86D1_18E139E20B74__INCLUDED_)
