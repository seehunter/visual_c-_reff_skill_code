// StClock.h : main header file for the STCLOCK application
//

#if !defined(AFX_STCLOCK_H__6FDFD23E_3135_4C1C_B84B_A957F7B01D16__INCLUDED_)
#define AFX_STCLOCK_H__6FDFD23E_3135_4C1C_B84B_A957F7B01D16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStClockApp:
// See StClock.cpp for the implementation of this class
//

class CStClockApp : public CWinApp
{
public:
	CStClockApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStClockApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStClockApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STCLOCK_H__6FDFD23E_3135_4C1C_B84B_A957F7B01D16__INCLUDED_)
