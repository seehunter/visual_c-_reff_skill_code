// GetHostIPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GetHostIP.h"
#include "GetHostIPDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetHostIPDlg dialog

CGetHostIPDlg::CGetHostIPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetHostIPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetHostIPDlg)
	m_strName = _T("");
	m_strIP = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetHostIPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetHostIPDlg)
	DDX_Text(pDX, IDC_NAME_ED, m_strName);
	DDX_Text(pDX, IDC_IP_ED, m_strIP);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGetHostIPDlg, CDialog)
	//{{AFX_MSG_MAP(CGetHostIPDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GET_BTN, OnGetBtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetHostIPDlg message handlers

BOOL CGetHostIPDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	int nRetCode;
	
	nRetCode = StartUp();
	TRACE1("StartUp RetCode: %d\n", nRetCode);

	nRetCode = GetLocalHostName(m_strName);
	TRACE1("GetLocalHostName RetCode: %d\n", nRetCode);

	nRetCode = GetIPAddress(m_strName, m_strIP);
	TRACE1("GetIPAddress RetCode: %d\n", nRetCode);

	nRetCode = CleanUp();
	TRACE1("CleanUp RetCode: %d\n", nRetCode);

	UpdateData(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGetHostIPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGetHostIPDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGetHostIPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CGetHostIPDlg::OnGetBtn() 
{
	CDialog::OnOK();	
}
/************************************************************************/
/* 
/************************************************************************/
int CGetHostIPDlg::StartUp()
{
	WORD    wVersionRequested;
	WSADATA wsaData;
	int     err; 	
	wVersionRequested = MAKEWORD( 2, 0 ); 
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		// Couldn't find a usable WinSock DLL.                                  */    
		return err;
	} 
	if ( LOBYTE( wsaData.wVersion ) != 2 ||
        HIBYTE( wsaData.wVersion ) != 0 ) {
		// Couldn't find a usable WinSock DLL.
		WSACleanup( );
		return WSAVERNOTSUPPORTED; 
	} 
	
	// The WinSock DLL is acceptable
	return 0;
}
/************************************************************************/
/* 
/************************************************************************/
int CGetHostIPDlg::CleanUp()
{
	int nRetCode;

	nRetCode = WSACleanup();
	if (nRetCode != 0) {
		// An error occured. 
		return WSAGetLastError();
	}
	return 0; 
}
/************************************************************************/
/* 
/************************************************************************/
int CGetHostIPDlg::GetLocalHostName(CString& sHostName)
{

	char szHostName[256];
	int  nRetCode;

	nRetCode = gethostname(szHostName, sizeof(szHostName));

	if (nRetCode != 0) {
		// An error has occurred
		sHostName = _T("Not available");;
		return WSAGetLastError();
	}

	sHostName = szHostName;
	return 0;
}
/************************************************************************/
/* 
/************************************************************************/
int CGetHostIPDlg::GetIPAddress(const CString& sHostName, CString& sIPAddress)
{
	struct hostent FAR *lpHostEnt = gethostbyname (sHostName);

	if (lpHostEnt == NULL) {
		// An error occurred. 
		sIPAddress = _T("");
		return WSAGetLastError();
	}

	LPSTR lpAddr = lpHostEnt->h_addr_list[0];
	if (lpAddr) {
		struct in_addr  inAddr;
		memmove (&inAddr, lpAddr, 4);
		sIPAddress = inet_ntoa (inAddr);
		if (sIPAddress.IsEmpty())
			sIPAddress = _T("Not available");
	}		
	
	return 0;
}


