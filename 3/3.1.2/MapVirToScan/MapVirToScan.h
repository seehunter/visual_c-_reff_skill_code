// MapVirToScan.h : main header file for the MAPVIRTOSCAN application
//

#if !defined(AFX_MAPVIRTOSCAN_H__602BF2C6_9E56_4D19_AAEE_C14F73CAAF5B__INCLUDED_)
#define AFX_MAPVIRTOSCAN_H__602BF2C6_9E56_4D19_AAEE_C14F73CAAF5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMapVirToScanApp:
// See MapVirToScan.cpp for the implementation of this class
//

class CMapVirToScanApp : public CWinApp
{
public:
	CMapVirToScanApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapVirToScanApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMapVirToScanApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPVIRTOSCAN_H__602BF2C6_9E56_4D19_AAEE_C14F73CAAF5B__INCLUDED_)
