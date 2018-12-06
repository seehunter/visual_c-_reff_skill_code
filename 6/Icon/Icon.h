// Icon.h : main header file for the ICON application
//

#if !defined(AFX_ICON_H__0E78F4DF_171E_4DAB_B7E9_A42419298710__INCLUDED_)
#define AFX_ICON_H__0E78F4DF_171E_4DAB_B7E9_A42419298710__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIconApp:
// See Icon.cpp for the implementation of this class
//

class CIconApp : public CWinApp
{
public:
	CIconApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIconApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIconApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICON_H__0E78F4DF_171E_4DAB_B7E9_A42419298710__INCLUDED_)
