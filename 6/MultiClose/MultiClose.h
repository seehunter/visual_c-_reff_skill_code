// MultiClose.h : main header file for the MULTICLOSE application
//

#if !defined(AFX_MULTICLOSE_H__DFE7B3A5_6F3D_4C75_919E_B0257E232B42__INCLUDED_)
#define AFX_MULTICLOSE_H__DFE7B3A5_6F3D_4C75_919E_B0257E232B42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiCloseApp:
// See MultiClose.cpp for the implementation of this class
//

class CMultiCloseApp : public CWinApp
{
public:
	CMultiCloseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiCloseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMultiCloseApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTICLOSE_H__DFE7B3A5_6F3D_4C75_919E_B0257E232B42__INCLUDED_)
