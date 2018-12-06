// Directory.h : main header file for the DIRECTORY application
//

#if !defined(AFX_DIRECTORY_H__1BCD97A7_B29E_424D_BBB5_BE96D5FCBFA8__INCLUDED_)
#define AFX_DIRECTORY_H__1BCD97A7_B29E_424D_BBB5_BE96D5FCBFA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDirectoryApp:
// See Directory.cpp for the implementation of this class
//

class CDirectoryApp : public CWinApp
{
public:
	CDirectoryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDirectoryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDirectoryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIRECTORY_H__1BCD97A7_B29E_424D_BBB5_BE96D5FCBFA8__INCLUDED_)
