// StClockDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StClock.h"
#include "StClockDlg.h"

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
// CStClockDlg dialog

CStClockDlg::CStClockDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStClockDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStClockDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStClockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStClockDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStClockDlg, CDialog)
	//{{AFX_MSG_MAP(CStClockDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_ENABLE_BTN, OnEnableBtn)
	ON_BN_CLICKED(IDC_STOP_BTN, OnStopBtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStClockDlg message handlers

BOOL CStClockDlg::OnInitDialog()
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
	CRect rect;
	::GetWindowRect(GetDlgItem(IDC_STATIC_1)->m_hWnd,&rect);
	ScreenToClient(rect);
	m_Clock.InitClock(this,8,rect.left+15,rect.top+15,0);
    m_Clock.MyFun("88888888");
	((CWnd*)GetDlgItem(IDC_STOP_BTN))->EnableWindow(FALSE);
	//SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStClockDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CStClockDlg::OnPaint() 
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
HCURSOR CStClockDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStClockDlg::OnTimer(UINT nIDEvent) 
{
	CTime curtime=CTime::GetCurrentTime();
	int Sec1=curtime.GetSecond();
	int Sec2=Sec1%10;
	Sec1/=10;
	int minu1=curtime.GetMinute();
	int minu2=minu1%10;
	minu1/=10;
	int hour1=curtime.GetHour();
	int hour2=hour1%10;
	hour1/=10;
	CString strTemp;
	strTemp.Format("%d%d|%d%d|%d%d",hour1,hour2,minu1,minu2,Sec1,Sec2);
	m_Clock.MyFun(strTemp);	
	CDialog::OnTimer(nIDEvent);
}

void CStClockDlg::OnEnableBtn() 
{
	SetTimer(1,1000,NULL);
	::SetWindowText(GetDlgItem(IDC_STATIC_2)->m_hWnd,"Æô¶¯");
	((CWnd*)GetDlgItem(IDC_ENABLE_BTN))->EnableWindow(FALSE);
	((CWnd*)GetDlgItem(IDC_STOP_BTN))->EnableWindow(TRUE);	
}

void CStClockDlg::OnStopBtn() 
{
	KillTimer(1);
	::SetWindowText(GetDlgItem(IDC_STATIC_2)->m_hWnd,"Í£Ö¹");
	((CWnd*)GetDlgItem(IDC_ENABLE_BTN))->EnableWindow(TRUE);
	((CWnd*)GetDlgItem(IDC_STOP_BTN))->EnableWindow(FALSE);	
	
}
