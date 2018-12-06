// AutoStart.h : main header file for the AUTOSTART application
//

#if !defined(AFX_AUTOSTART_H__9E82095F_D406_4CC9_9762_139B88A3D370__INCLUDED_)
#define AFX_AUTOSTART_H__9E82095F_D406_4CC9_9762_139B88A3D370__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAutoStartApp:
// See AutoStart.cpp for the implementation of this class
//

class CAutoStartApp : public CWinApp
{
public:
	CAutoStartApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoStartApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAutoStartApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOSTART_H__9E82095F_D406_4CC9_9762_139B88A3D370__INCLUDED_)
