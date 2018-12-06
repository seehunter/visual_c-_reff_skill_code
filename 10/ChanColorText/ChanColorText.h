// ChanColorText.h : main header file for the CHANCOLORTEXT application
//

#if !defined(AFX_CHANCOLORTEXT_H__DFE9C914_2974_4855_83F6_3B8A9BF1B1C3__INCLUDED_)
#define AFX_CHANCOLORTEXT_H__DFE9C914_2974_4855_83F6_3B8A9BF1B1C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CChanColorTextApp:
// See ChanColorText.cpp for the implementation of this class
//

class CChanColorTextApp : public CWinApp
{
public:
	CChanColorTextApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChanColorTextApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CChanColorTextApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANCOLORTEXT_H__DFE9C914_2974_4855_83F6_3B8A9BF1B1C3__INCLUDED_)
