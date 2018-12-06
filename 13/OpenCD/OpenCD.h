// OpenCD.h : main header file for the OPENCD application
//

#if !defined(AFX_OPENCD_H__FE21C35B_5D74_4B24_8671_AD3ADD41C087__INCLUDED_)
#define AFX_OPENCD_H__FE21C35B_5D74_4B24_8671_AD3ADD41C087__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COpenCDApp:
// See OpenCD.cpp for the implementation of this class
//

class COpenCDApp : public CWinApp
{
public:
	COpenCDApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenCDApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COpenCDApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENCD_H__FE21C35B_5D74_4B24_8671_AD3ADD41C087__INCLUDED_)
