// ChangeViewSize.h : main header file for the CHANGEVIEWSIZE application
//

#if !defined(AFX_CHANGEVIEWSIZE_H__EFB7157C_399F_4008_B46C_62279BCBE2A8__INCLUDED_)
#define AFX_CHANGEVIEWSIZE_H__EFB7157C_399F_4008_B46C_62279BCBE2A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CChangeViewSizeApp:
// See ChangeViewSize.cpp for the implementation of this class
//

class CChangeViewSizeApp : public CWinApp
{
public:
	CChangeViewSizeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeViewSizeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CChangeViewSizeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEVIEWSIZE_H__EFB7157C_399F_4008_B46C_62279BCBE2A8__INCLUDED_)
