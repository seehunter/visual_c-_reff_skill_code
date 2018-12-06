// DrawButton.h : main header file for the DRAWBUTTON application
//

#if !defined(AFX_DRAWBUTTON_H__9234D9E4_7B5B_405B_9BBC_6A06C6C2936E__INCLUDED_)
#define AFX_DRAWBUTTON_H__9234D9E4_7B5B_405B_9BBC_6A06C6C2936E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawButtonApp:
// See DrawButton.cpp for the implementation of this class
//

class CDrawButtonApp : public CWinApp
{
public:
	CDrawButtonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawButtonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDrawButtonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWBUTTON_H__9234D9E4_7B5B_405B_9BBC_6A06C6C2936E__INCLUDED_)
