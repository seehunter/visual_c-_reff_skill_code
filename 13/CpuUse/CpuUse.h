// CpuUse.h : main header file for the CPUUSE application
//

#if !defined(AFX_CPUUSE_H__2B49057A_A1EE_49D5_AD23_031DD355A527__INCLUDED_)
#define AFX_CPUUSE_H__2B49057A_A1EE_49D5_AD23_031DD355A527__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCpuUseApp:
// See CpuUse.cpp for the implementation of this class
//

class CCpuUseApp : public CWinApp
{
public:
	CCpuUseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCpuUseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCpuUseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPUUSE_H__2B49057A_A1EE_49D5_AD23_031DD355A527__INCLUDED_)
