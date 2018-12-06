// EasySimulate.h : main header file for the EASYSIMULATE application
//

#if !defined(AFX_EASYSIMULATE_H__98681866_85D8_4BA1_ADFD_3E599AB090E9__INCLUDED_)
#define AFX_EASYSIMULATE_H__98681866_85D8_4BA1_ADFD_3E599AB090E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEasySimulateApp:
// See EasySimulate.cpp for the implementation of this class
//

class CEasySimulateApp : public CWinApp
{
public:
	CEasySimulateApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEasySimulateApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEasySimulateApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EASYSIMULATE_H__98681866_85D8_4BA1_ADFD_3E599AB090E9__INCLUDED_)
