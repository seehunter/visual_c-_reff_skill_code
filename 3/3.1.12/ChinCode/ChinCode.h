// ChinCode.h : main header file for the CHINCODE application
//

#if !defined(AFX_CHINCODE_H__2AC04A74_8300_49FB_992C_22E0B6CCB914__INCLUDED_)
#define AFX_CHINCODE_H__2AC04A74_8300_49FB_992C_22E0B6CCB914__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CChinCodeApp:
// See ChinCode.cpp for the implementation of this class
//

class CChinCodeApp : public CWinApp
{
public:
	CChinCodeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChinCodeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CChinCodeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHINCODE_H__2AC04A74_8300_49FB_992C_22E0B6CCB914__INCLUDED_)
