// HookDll.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "HookDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHookDllApp

BEGIN_MESSAGE_MAP(CHookDllApp, CWinApp)
	//{{AFX_MSG_MAP(CHookDllApp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHookDllApp construction

CHookDllApp::CHookDllApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CHookDllApp object

CHookDllApp theApp;
TCHAR ch[2];
HHOOK hHook;
LRESULT  CALLBACK  HookFun(int nCode,WPARAM wParam,LPARAM lp)
{
	
	KBDLLHOOKSTRUCT *pkh = (KBDLLHOOKSTRUCT *) lp;

	if (nCode==HC_ACTION) {
		BOOL bCtrlKeyDown =
			GetAsyncKeyState(VK_CONTROL)>>((sizeof(SHORT) * 8) - 1);

		if ((pkh->vkCode==VK_ESCAPE && bCtrlKeyDown) ||				    // Ctrl+Esc
			(pkh->vkCode==VK_TAB && pkh->flags & LLKHF_ALTDOWN) ||   // Alt+TAB
			(pkh->vkCode==VK_ESCAPE && pkh->flags & LLKHF_ALTDOWN)|| // Alt+Esc
			
			(pkh->vkCode==VK_LWIN || pkh->vkCode==VK_RWIN)) 
		{ // Start Menu
			//		if (g_bBeep && (wp==WM_SYSKEYDOWN||wp==WM_KEYDOWN))
			//			MessageBeep(0); // only beep on downstroke if requested
			return 1; // gobble it: go directly to jail, do not pass go
		}
	}
	return CallNextHookEx(hHook,nCode,wParam,lp);
}

BOOL  InstallDll(HWND hWnd,DWORD threadID)
{   
	hHook = SetWindowsHookEx(WH_KEYBOARD_LL,(HOOKPROC)HookFun,theApp.m_hInstance,threadID);
	return TRUE;
}
void  UnInstallDll()
{
	UnhookWindowsHookEx(hHook);
}