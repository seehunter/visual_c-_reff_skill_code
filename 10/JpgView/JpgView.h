// JpgView.h : main header file for the JPGVIEW application
//

#if !defined(AFX_JPGVIEW_H__CA367956_056D_428D_8F17_55CB2455051E__INCLUDED_)
#define AFX_JPGVIEW_H__CA367956_056D_428D_8F17_55CB2455051E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CJpgViewApp:
// See JpgView.cpp for the implementation of this class
//

class CJpgViewApp : public CWinApp
{
public:
	CJpgViewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJpgViewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CJpgViewApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JPGVIEW_H__CA367956_056D_428D_8F17_55CB2455051E__INCLUDED_)
