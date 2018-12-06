// ShowScrollText.h : main header file for the SHOWSCROLLTEXT application
//

#if !defined(AFX_SHOWSCROLLTEXT_H__E2086FBA_B10F_4330_BAEB_DB8B8774C04D__INCLUDED_)
#define AFX_SHOWSCROLLTEXT_H__E2086FBA_B10F_4330_BAEB_DB8B8774C04D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowScrollTextApp:
// See ShowScrollText.cpp for the implementation of this class
//

class CShowScrollTextApp : public CWinApp
{
public:
	CShowScrollTextApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowScrollTextApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CShowScrollTextApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWSCROLLTEXT_H__E2086FBA_B10F_4330_BAEB_DB8B8774C04D__INCLUDED_)
