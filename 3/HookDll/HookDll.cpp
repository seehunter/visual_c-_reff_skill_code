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
LRESULT  CALLBACK  HookFun(int nCode,WPARAM wParam,LPARAM lParam)
{
	
	if(HC_ACTION == nCode)
	{
		switch(wParam) {
		case 0x08:
		case 0x0A:
		case 0x1B:
		case 0x09:
		case 0x0D:
			break;
		default:
            ch[0] = (TCHAR)wParam;
			MessageBox(NULL,ch,"HookChar",MB_OK);
			m_hWnd = ::FindWindow(NULL,"InjectHook");
			SendMessage(m_hWnd,WM_INFO_VIEW,(WPARAM)ch,0);
		}
	}
	return CallNextHookEx(hHook,nCode,wParam,lParam);
}
BOOL  InstallDll(HWND hWnd,DWORD threadID)
{   
	hHook = SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)HookFun,theApp.m_hInstance,threadID);
	return TRUE;
}
void  UnInstallDll()
{
	UnhookWindowsHookEx(hHook);
}