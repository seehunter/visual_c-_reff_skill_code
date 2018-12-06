// HotKeyHookDll.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"

#include "HotKeyHookDll.h"
#define DLLEXPORT __declspec(dllexport)
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CHotKeyHookDllApp

BEGIN_MESSAGE_MAP(CHotKeyHookDllApp, CWinApp)
	//{{AFX_MSG_MAP(CHotKeyHookDllApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHotKeyHookDllApp construction

CHotKeyHookDllApp::CHotKeyHookDllApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CHotKeyHookDllApp object

CHotKeyHookDllApp theApp;
HHOOK  g_hHook;
/************************************************************************/
/* 钩子回调函数
/************************************************************************/
LRESULT  CALLBACK  HookFun(int nCode,WPARAM wParam,LPARAM lParam)
{
	KBDLLHOOKSTRUCT *phs = (KBDLLHOOKSTRUCT *) lParam;	
	if(nCode  == HC_ACTION)
	{
		BOOL bControl = GetAsyncKeyState(VK_CONTROL)>>((sizeof(SHORT) * 8) - 1);
		if ((phs->vkCode==VK_ESCAPE && bControl) ||				    // CTRL+ESC
			 (phs->vkCode==VK_TAB && phs->flags & LLKHF_ALTDOWN) ||   // Alt+TAB
			 (phs->vkCode==VK_ESCAPE && phs->flags & LLKHF_ALTDOWN)|| // Alt+ESC
			 (phs->vkCode==VK_LWIN || phs->vkCode==VK_RWIN)) // START MENU
		{ 
		    	return 1; //
		}
	}
	return CallNextHookEx(g_hHook,nCode,wParam,lParam);
}
/************************************************************************/
/* 安装钩子
/************************************************************************/
DLLEXPORT BOOL installHook()
{
	g_hHook = SetWindowsHookEx(WH_KEYBOARD_LL,HookFun,theApp.m_hInstance,0);
	if(g_hHook) return TRUE;
		else return FALSE;
		
}
/************************************************************************/
/* 卸载函数
/************************************************************************/
DLLEXPORT BOOL uninstallHook()
{
	if(UnhookWindowsHookEx(g_hHook))return TRUE;
	else return FALSE;
}