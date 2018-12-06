// DynamicAddMenu.h : main header file for the DYNAMICADDMENU application
//

#if !defined(AFX_DYNAMICADDMENU_H__8ED28FBD_1D9C_4A21_B348_CF2FF1FB4897__INCLUDED_)
#define AFX_DYNAMICADDMENU_H__8ED28FBD_1D9C_4A21_B348_CF2FF1FB4897__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDynamicAddMenuApp:
// See DynamicAddMenu.cpp for the implementation of this class
//

class CDynamicAddMenuApp : public CWinApp
{
public:
	CDynamicAddMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynamicAddMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDynamicAddMenuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMICADDMENU_H__8ED28FBD_1D9C_4A21_B348_CF2FF1FB4897__INCLUDED_)
