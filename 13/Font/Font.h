// Font.h : main header file for the FONT application
//

#if !defined(AFX_FONT_H__CE3CE5C1_24F4_4647_B1A0_FB408E82D84E__INCLUDED_)
#define AFX_FONT_H__CE3CE5C1_24F4_4647_B1A0_FB408E82D84E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFontApp:
// See Font.cpp for the implementation of this class
//

class CFontApp : public CWinApp
{
public:
	CFontApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFontApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONT_H__CE3CE5C1_24F4_4647_B1A0_FB408E82D84E__INCLUDED_)
