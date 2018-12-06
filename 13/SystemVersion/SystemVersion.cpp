// SystemVersion.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SystemVersion.h"
#include "SystemVersionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSystemVersionApp

BEGIN_MESSAGE_MAP(CSystemVersionApp, CWinApp)
	//{{AFX_MSG_MAP(CSystemVersionApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSystemVersionApp construction

CSystemVersionApp::CSystemVersionApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSystemVersionApp object

CSystemVersionApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSystemVersionApp initialization

BOOL CSystemVersionApp::InitInstance()
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
     OSVERSIONINFO VerInfo;
	CString  OSName;
	VerInfo.dwOSVersionInfoSize = sizeof(VerInfo);
	if( GetVersionEx( &VerInfo ) )
	{
		switch( VerInfo.dwPlatformId )
		{
		case VER_PLATFORM_WIN32s:
			OSName = "Win32s";
			break;
		case VER_PLATFORM_WIN32_WINDOWS:
			OSName = "Windows 95/98";
			break;
		case VER_PLATFORM_WIN32_NT:
			OSName = "Windows NT";
			break;
		default:
			break;
		}
		CString stTmp;
		stTmp.Format("操作系统的类型:%s",OSName);
		if(OSName != "Windows NT")
		{
			::MessageBox(NULL,"该程序需要运行在NT系统下 ", "WARNNING",MB_OKCANCEL);
			return FALSE;
		}
	}


	CSystemVersionDlg dlg;
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
