// SimuteKey.h : main header file for the SIMUTEKEY application
//

#if !defined(AFX_SIMUTEKEY_H__8DB5A133_D624_4B1C_9848_61CD01BC423D__INCLUDED_)
#define AFX_SIMUTEKEY_H__8DB5A133_D624_4B1C_9848_61CD01BC423D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSimuteKeyApp:
// See SimuteKey.cpp for the implementation of this class
//

class CSimuteKeyApp : public CWinApp
{
public:
	CSimuteKeyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimuteKeyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSimuteKeyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMUTEKEY_H__8DB5A133_D624_4B1C_9848_61CD01BC423D__INCLUDED_)