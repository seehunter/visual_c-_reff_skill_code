// WordTextStyle.h : main header file for the WORDTEXTSTYLE application
//

#if !defined(AFX_WORDTEXTSTYLE_H__89B3C839_A992_48CC_B43B_B2E567747EE2__INCLUDED_)
#define AFX_WORDTEXTSTYLE_H__89B3C839_A992_48CC_B43B_B2E567747EE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWordTextStyleApp:
// See WordTextStyle.cpp for the implementation of this class
//

class CWordTextStyleApp : public CWinApp
{
public:
	CWordTextStyleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordTextStyleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWordTextStyleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDTEXTSTYLE_H__89B3C839_A992_48CC_B43B_B2E567747EE2__INCLUDED_)
