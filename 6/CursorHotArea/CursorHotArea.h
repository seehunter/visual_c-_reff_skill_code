// CursorHotArea.h : main header file for the CURSORHOTAREA application
//

#if !defined(AFX_CURSORHOTAREA_H__CD5F57D1_37CA_4866_8E41_5EE6C12F01C4__INCLUDED_)
#define AFX_CURSORHOTAREA_H__CD5F57D1_37CA_4866_8E41_5EE6C12F01C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCursorHotAreaApp:
// See CursorHotArea.cpp for the implementation of this class
//

class CCursorHotAreaApp : public CWinApp
{
public:
	CCursorHotAreaApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCursorHotAreaApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCursorHotAreaApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CURSORHOTAREA_H__CD5F57D1_37CA_4866_8E41_5EE6C12F01C4__INCLUDED_)
