// CircleText.h : main header file for the CIRCLETEXT application
//

#if !defined(AFX_CIRCLETEXT_H__0B772405_169B_4BCE_9152_1FFE4A49B7E8__INCLUDED_)
#define AFX_CIRCLETEXT_H__0B772405_169B_4BCE_9152_1FFE4A49B7E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCircleTextApp:
// See CircleText.cpp for the implementation of this class
//

class CCircleTextApp : public CWinApp
{
public:
	CCircleTextApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCircleTextApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCircleTextApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CIRCLETEXT_H__0B772405_169B_4BCE_9152_1FFE4A49B7E8__INCLUDED_)
