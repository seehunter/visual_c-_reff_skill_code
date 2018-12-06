// ODBC.h : main header file for the ODBC application
//

#if !defined(AFX_ODBC_H__4B5FCBF0_1E56_4FD7_8B1B_D2F94E310D40__INCLUDED_)
#define AFX_ODBC_H__4B5FCBF0_1E56_4FD7_8B1B_D2F94E310D40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CODBCApp:
// See ODBC.cpp for the implementation of this class
//

class CODBCApp : public CWinApp
{
public:
	CODBCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CODBCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBC_H__4B5FCBF0_1E56_4FD7_8B1B_D2F94E310D40__INCLUDED_)
