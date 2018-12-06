// ClearRecy.h : main header file for the CLEARRECY application
//

#if !defined(AFX_CLEARRECY_H__DE42836C_282A_43B7_840A_56A5BC077812__INCLUDED_)
#define AFX_CLEARRECY_H__DE42836C_282A_43B7_840A_56A5BC077812__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CClearRecyApp:
// See ClearRecy.cpp for the implementation of this class
//

class CClearRecyApp : public CWinApp
{
public:
	CClearRecyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClearRecyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CClearRecyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLEARRECY_H__DE42836C_282A_43B7_840A_56A5BC077812__INCLUDED_)
