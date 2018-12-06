// HookDll.h : main header file for the HOOKDLL DLL
//

#if !defined(AFX_HOOKDLL_H__13D5E4A6_0E41_48C3_96AA_07EC5C02AE99__INCLUDED_)
#define AFX_HOOKDLL_H__13D5E4A6_0E41_48C3_96AA_07EC5C02AE99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHookDllApp
// See HookDll.cpp for the implementation of this class
//

class CHookDllApp : public CWinApp
{
public:
	CHookDllApp();

// Overrides

	//{{AFX_VIRTUAL(CHookDllApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CHookDllApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
LRESULT  CALLBACK  HookFun(int nCode,WPARAM wParam,LPARAM lParam);
BOOL  InstallDll(DWORD threadID);
void  UnInstallDll();
HWND  m_hWnd;
#define WM_INFO_VIEW WM_USER+100
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOOKDLL_H__13D5E4A6_0E41_48C3_96AA_07EC5C02AE99__INCLUDED_)
