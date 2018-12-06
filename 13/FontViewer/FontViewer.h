// FontViewer.h : main header file for the FONTVIEWER application
//

#if !defined(AFX_FONTVIEWER_H__27AA915D_688D_482E_ADB8_CF10EE58CFA6__INCLUDED_)
#define AFX_FONTVIEWER_H__27AA915D_688D_482E_ADB8_CF10EE58CFA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFontViewerApp:
// See FontViewer.cpp for the implementation of this class
//

class CFontViewerApp : public CWinApp
{
public:
	CFontViewerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontViewerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFontViewerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTVIEWER_H__27AA915D_688D_482E_ADB8_CF10EE58CFA6__INCLUDED_)
