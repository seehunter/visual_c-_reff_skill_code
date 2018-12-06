// ScreenPix.h : main header file for the SCREENPIX application
//

#if !defined(AFX_SCREENPIX_H__D5CDD697_B5EE_4567_AC51_2A80D22DA4DD__INCLUDED_)
#define AFX_SCREENPIX_H__D5CDD697_B5EE_4567_AC51_2A80D22DA4DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CScreenPixApp:
// See ScreenPix.cpp for the implementation of this class
//

class CScreenPixApp : public CWinApp
{
public:
	CScreenPixApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScreenPixApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CScreenPixApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCREENPIX_H__D5CDD697_B5EE_4567_AC51_2A80D22DA4DD__INCLUDED_)
