// XXXDlg.cpp : implementation file
//

#include "stdafx.h"
#include "XXX.h"
#include "XXXDlg.h"

#include <mmsystem.h>	// PlaySound()
#pragma comment(lib,"winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const BYTE		KEY_SPACE = 0x20;
const BYTE		KEY_CAPS = 0x14;
const BYTE		KEY_ENTER = 0x0D;

const BYTE		KEY_0 = 0x30;
const BYTE		KEY_1 =	0x31;
const BYTE		KEY_2 =	0x32;
const BYTE		KEY_3 =	0x33;
const BYTE		KEY_4 =	0x34;
const BYTE		KEY_5 =	0x35;
const BYTE		KEY_6 =	0x36;
const BYTE		KEY_7 =	0x37;
const BYTE		KEY_8 =	0x38;
const BYTE		KEY_9 =	0x39;
const BYTE      KEY_10 = 0x3A;

const BYTE		KEY_A = 0x41;
const BYTE		KEY_B = 0x42;
const BYTE		KEY_C = 0x43;
const BYTE		KEY_D = 0x44;
const BYTE		KEY_E = 0x45;
const BYTE		KEY_F = 0x46;
const BYTE		KEY_G = 0x47;
const BYTE		KEY_H = 0x48;
const BYTE		KEY_I = 0x49;
const BYTE		KEY_J = 0x4A;
const BYTE		KEY_K = 0x4B;
const BYTE		KEY_L = 0x4C;
const BYTE		KEY_M = 0x4D;
const BYTE		KEY_N = 0x4E;
const BYTE		KEY_O = 0x4F;
const BYTE		KEY_P = 0x50;
const BYTE		KEY_Q = 0x51;
const BYTE		KEY_R = 0x52;
const BYTE		KEY_S = 0x53;
const BYTE		KEY_T = 0x54;
const BYTE		KEY_U = 0x55;
const BYTE		KEY_V = 0x56;
const BYTE		KEY_W = 0x57;
const BYTE		KEY_X = 0x58;
const BYTE		KEY_Y = 0x59;
const BYTE		KEY_Z = 0x5A;

BYTE key[] = {

// hello boy i hope you can love it
KEY_H,KEY_E,KEY_L,KEY_L,KEY_O,KEY_SPACE,KEY_B,KEY_O,KEY_Y,KEY_SPACE,KEY_I,KEY_SPACE,
KEY_H,KEY_O,KEY_P,KEY_E,KEY_SPACE,KEY_Y,KEY_O,KEY_U,KEY_SPACE,KEY_C,KEY_A,KEY_N,KEY_SPACE,
KEY_L,KEY_O,KEY_V,KEY_E,KEY_SPACE,KEY_I,KEY_T,

// 回车换行
KEY_ENTER,
KEY_ENTER,

// if you have any problem ple concact me
KEY_I,KEY_F,KEY_SPACE,KEY_Y,KEY_O,KEY_U,KEY_SPACE,KEY_H,KEY_A,KEY_V,KEY_E,KEY_SPACE,KEY_A,KEY_N,KEY_Y,KEY_SPACE,
KEY_P,KEY_R,KEY_O,KEY_B,KEY_L,KEY_E,KEY_M,KEY_SPACE,KEY_P,KEY_L,KEY_E,KEY_SPACE,
KEY_C,KEY_O,KEY_N,KEY_C,KEY_A,KEY_C,KEY_T,KEY_SPACE,
KEY_M,KEY_E,

// 回车换行
KEY_ENTER,
KEY_ENTER,

// qq   121238684
KEY_Q,KEY_Q,KEY_10,KEY_SPACE,KEY_SPACE,KEY_SPACE,KEY_1,KEY_2,KEY_1,KEY_2,KEY_3,KEY_8,KEY_6,KEY_8,KEY_4,

};

UINT Thread(LPVOID lparam)
{  
	PlaySound("data/打字声.wav", NULL, 1);
	return 0;
}

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
// CXXXDlg dialog

CXXXDlg::CXXXDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CXXXDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CXXXDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CXXXDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXXXDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CXXXDlg, CDialog)
	//{{AFX_MSG_MAP(CXXXDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXXXDlg message handlers

BOOL CXXXDlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here

	SetTimer(0, 265, NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CXXXDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CXXXDlg::OnPaint() 
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
HCURSOR CXXXDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CXXXDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	static int i = 0;

	BYTE keyTemp = key[i];

	// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// 模拟按下键盘上的任一键
	::keybd_event(keyTemp, 0, 0, 0);				// 按下
	::AfxBeginThread(Thread,this);					// 打字声
	::keybd_event(keyTemp, 0, KEYEVENTF_KEYUP, 0);	// 弹起
	// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	i++;

	if( i >= sizeof(key)/sizeof(BYTE))
		KillTimer(0);

	CDialog::OnTimer(nIDEvent);
}


void CXXXDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}
