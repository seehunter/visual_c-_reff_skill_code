// ADO.h : main header file for the ADO application
//

#if !defined(AFX_ADO_H__AE4DCAE3_6BA0_482C_B0B7_7841B93372A0__INCLUDED_)
#define AFX_ADO_H__AE4DCAE3_6BA0_482C_B0B7_7841B93372A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CADOApp:
// See ADO.cpp for the implementation of this class
//

class CADOApp : public CWinApp
{
public:
	CADOApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CADOApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADO_H__AE4DCAE3_6BA0_482C_B0B7_7841B93372A0__INCLUDED_)
