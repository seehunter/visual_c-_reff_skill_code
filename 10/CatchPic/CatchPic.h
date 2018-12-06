// CatchPic.h : main header file for the CATCHPIC application
//

#if !defined(AFX_CATCHPIC_H__5FB94B7F_28F6_4965_8806_3475376DC8DA__INCLUDED_)
#define AFX_CATCHPIC_H__5FB94B7F_28F6_4965_8806_3475376DC8DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCatchPicApp:
// See CatchPic.cpp for the implementation of this class
//

class CCatchPicApp : public CWinApp
{
public:
	CCatchPicApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCatchPicApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCatchPicApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CATCHPIC_H__5FB94B7F_28F6_4965_8806_3475376DC8DA__INCLUDED_)
