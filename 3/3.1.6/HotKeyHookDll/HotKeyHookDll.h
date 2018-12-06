// HotKeyHookDll.h : main header file for the HOTKEYHOOKDLL DLL
//

#if !defined(AFX_HOTKEYHOOKDLL_H__5D88C511_1368_4869_80C9_856930751A6A__INCLUDED_)
#define AFX_HOTKEYHOOKDLL_H__5D88C511_1368_4869_80C9_856930751A6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHotKeyHookDllApp
// See HotKeyHookDll.cpp for the implementation of this class
//

class CHotKeyHookDllApp : public CWinApp
{
public:
	CHotKeyHookDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHotKeyHookDllApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CHotKeyHookDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOTKEYHOOKDLL_H__5D88C511_1368_4869_80C9_856930751A6A__INCLUDED_)
