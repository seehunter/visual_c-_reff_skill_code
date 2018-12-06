// OpenCom.h : main header file for the OPENCOM application
//

#if !defined(AFX_OPENCOM_H__E9F9C6D2_5B49_43B2_998C_610E75B06FA7__INCLUDED_)
#define AFX_OPENCOM_H__E9F9C6D2_5B49_43B2_998C_610E75B06FA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COpenComApp:
// See OpenCom.cpp for the implementation of this class
//

class COpenComApp : public CWinApp
{
public:
	COpenComApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenComApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COpenComApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENCOM_H__E9F9C6D2_5B49_43B2_998C_610E75B06FA7__INCLUDED_)
