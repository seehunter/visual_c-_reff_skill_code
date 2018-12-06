// GetCurrWnd.h : main header file for the GETCURRWND application
//

#if !defined(AFX_GETCURRWND_H__04613D07_BFF9_4ED7_83C1_FC67CEE8A742__INCLUDED_)
#define AFX_GETCURRWND_H__04613D07_BFF9_4ED7_83C1_FC67CEE8A742__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetCurrWndApp:
// See GetCurrWnd.cpp for the implementation of this class
//

class CGetCurrWndApp : public CWinApp
{
public:
	CGetCurrWndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetCurrWndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetCurrWndApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETCURRWND_H__04613D07_BFF9_4ED7_83C1_FC67CEE8A742__INCLUDED_)
