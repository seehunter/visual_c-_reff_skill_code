// CharToVK.h : main header file for the CHARTOVK application
//

#if !defined(AFX_CHARTOVK_H__BDA91626_C055_45F9_8E57_BA0C7FD7D345__INCLUDED_)
#define AFX_CHARTOVK_H__BDA91626_C055_45F9_8E57_BA0C7FD7D345__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCharToVKApp:
// See CharToVK.cpp for the implementation of this class
//

class CCharToVKApp : public CWinApp
{
public:
	CCharToVKApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCharToVKApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCharToVKApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHARTOVK_H__BDA91626_C055_45F9_8E57_BA0C7FD7D345__INCLUDED_)
