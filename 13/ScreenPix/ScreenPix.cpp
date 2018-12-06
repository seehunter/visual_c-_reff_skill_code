// ScreenPix.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ScreenPix.h"
#include "ScreenPixDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScreenPixApp

BEGIN_MESSAGE_MAP(CScreenPixApp, CWinApp)
	//{{AFX_MSG_MAP(CScreenPixApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScreenPixApp construction

CScreenPixApp::CScreenPixApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CScreenPixApp object

CScreenPixApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CScreenPixApp initialization

BOOL CScreenPixApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

    HDC  HScreenDC;
	HScreenDC =  CreateDC("DISPLAY",NULL,NULL,NULL);
	/*检索设备*/
	int xPix; int yPix;
	xPix = GetDeviceCaps(HScreenDC,HORZRES);
	yPix = GetDeviceCaps(HScreenDC,VERTRES);
	/*和初设定的分辨率进行比较,如果适合进入程序,否则退出程序*/
	if(xPix != 1024 || yPix != 768)
	{
		int nRet = MessageBox(NULL,"请将分辨率设置为800*600","Warnning",MB_OKCANCEL);
		if(nRet == IDOK)
		{
			DEVMODE   lpDevMode;   
			lpDevMode.dmBitsPerPel=32;   
            lpDevMode.dmPelsWidth=1024;   
			lpDevMode.dmPelsHeight=768;   
			lpDevMode.dmSize=sizeof(lpDevMode);   
			lpDevMode.dmFields   =DM_PELSWIDTH|DM_BITSPERPEL|DM_PELSHEIGHT;   
			LONG   res;   
			res=ChangeDisplaySettings(&lpDevMode,0);   
		}
		else
		   return FALSE;
	}

	CScreenPixDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
