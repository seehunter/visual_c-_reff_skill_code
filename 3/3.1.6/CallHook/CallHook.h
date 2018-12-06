// CallHook.h : main header file for the CALLHOOK application
//

#if !defined(AFX_CALLHOOK_H__95977303_48A2_4DC9_9750_41502E4A27FC__INCLUDED_)
#define AFX_CALLHOOK_H__95977303_48A2_4DC9_9750_41502E4A27FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCallHookApp:
// See CallHook.cpp for the implementation of this class
//

class CCallHookApp : public CWinApp
{
public:
	CCallHookApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCallHookApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCallHookApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALLHOOK_H__95977303_48A2_4DC9_9750_41502E4A27FC__INCLUDED_)
