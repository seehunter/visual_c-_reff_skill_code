// ShutComputerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShutComputer.h"
#include "ShutComputerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define WM_MY_TRAY_NOTIFICATION WM_USER+100
BOOL   TrayMessage(HWND hWnd, DWORD dwMessage, HICON hIcon, PSTR pszTip);
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
// CShutComputerDlg dialog

CShutComputerDlg::CShutComputerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShutComputerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShutComputerDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
    m_strResourceTime = "";
}

void CShutComputerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShutComputerDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShutComputerDlg, CDialog)
	//{{AFX_MSG_MAP(CShutComputerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_TIME_BTN, OnTimeBtn)
	ON_MESSAGE(WM_MY_TRAY_NOTIFICATION , OnTrayNotification)
	ON_BN_CLICKED(IDC_BTN_TRAY, OnBtnTray)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShutComputerDlg message handlers

BOOL CShutComputerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
    SetTimer(1,1000,NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShutComputerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CShutComputerDlg::OnPaint() 
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
HCURSOR CShutComputerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CShutComputerDlg::OnTimer(UINT nIDEvent) 
{
	CString strTime = "";
	CString strMinute = "";
	CString strHour = "";
	CString strSecond = "";
	CTime time = CTime::GetCurrentTime();   ///构造CTime对象
	int m_nYear = time.GetYear();      ///年
	int m_nMonth = time.GetMonth();      ///月
	int m_nDay = time.GetDay();      ///日
	int m_nHour = time.GetHour();      ///小时
	int m_nMinute = time.GetMinute();   ///分钟
	int m_nSecond = time.GetSecond();   ///秒
	if(m_nHour < 10)
		strHour.Format("0%d",m_nHour);
	else
		strHour.Format("%d",m_nHour);
	if(m_nMinute < 10)
		strMinute.Format("0%d",m_nMinute);
	else
		strMinute.Format("%d",m_nMinute);
	if(m_nSecond <10)
		strSecond.Format("0%d",m_nSecond);
	else
		strSecond.Format("%d",m_nSecond);

    strTime = strHour + strMinute + strSecond;
	if(strTime == m_strResourceTime)
       MySystemShutDown();
	CDialog::OnTimer(nIDEvent);
}
///////////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////////
BOOL CShutComputerDlg::MySystemShutDown()
{
	  HANDLE   hToken;   
      TOKEN_PRIVILEGES   tkp;   
      if   (!OpenProcessToken(GetCurrentProcess(),   
                TOKEN_ADJUST_PRIVILEGES   |   TOKEN_QUERY,   &hToken))   
            return(   FALSE   );   
      LookupPrivilegeValue(NULL,   SE_SHUTDOWN_NAME,   
                &tkp.Privileges[0].Luid);   
      tkp.PrivilegeCount   =   1;     //   one   privilege   to   set         
      tkp.Privileges[0].Attributes   =   SE_PRIVILEGE_ENABLED;     
      AdjustTokenPrivileges(hToken,   FALSE,   &tkp,   0,   
               (PTOKEN_PRIVILEGES)NULL,   0);   
      if   (GetLastError()   !=   ERROR_SUCCESS)   
            return   FALSE;   
  
      if   (!ExitWindowsEx(EWX_POWEROFF   |   EWX_FORCE,   0))   
            return   FALSE;   
	  return TRUE;
}

void CShutComputerDlg::OnTimeBtn() 
{
   	GetDlgItemText(IDC_TIME_EDIT,m_strResourceTime);
}

BOOL TrayMessage(HWND hWnd,DWORD dwMessage, HICON hIcon, PSTR pszTip)
{
	BOOL bReturn;
	NOTIFYICONDATA NotifyData;
	NotifyData.cbSize = sizeof(NOTIFYICONDATA);
    NotifyData.hWnd = hWnd;	
    NotifyData.hIcon = hIcon;
    NotifyData.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
    NotifyData.uCallbackMessage = WM_MY_TRAY_NOTIFICATION;
    NotifyData.uID = IDI_ICON1;
	lstrcpyn(NotifyData.szTip, pszTip, sizeof(NotifyData.szTip));
	bReturn = Shell_NotifyIcon(dwMessage , &NotifyData);
	if(hIcon)
		DestroyIcon(hIcon);
	return bReturn;
}
/////////////////////////////////////////////////////////////////////////////////
LRESULT CShutComputerDlg::OnTrayNotification(WPARAM wparam, LPARAM lparam)
{
   switch(lparam)
   {
   case WM_RBUTTONUP:
   case WM_LBUTTONDBLCLK:
	   ShowWindow(SW_SHOW);
	TrayMessage(m_hWnd, NIM_DELETE, NULL, "");
   }
   return 0;
}
//


void CShutComputerDlg::OnBtnTray() 
{
   	TrayMessage(m_hWnd, NIM_ADD, NULL, "定时关机");
	TrayMessage(m_hWnd, NIM_MODIFY, m_hIcon, "定时关机");
	ShowWindow(SW_HIDE);

}
