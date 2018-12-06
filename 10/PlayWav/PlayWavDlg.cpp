// PlayWavDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlayWav.h"
#include "PlayWavDlg.h"

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
// CPlayWavDlg dialog

CPlayWavDlg::CPlayWavDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlayWavDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlayWavDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nDeviceID = 0;
	m_nElementID = 0;
}

void CPlayWavDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlayWavDlg)
	DDX_Control(pDX, IDC_CLOSE_BTN, m_CloseBtn);
	DDX_Control(pDX, IDC_STOP_BTN, m_StopBtn);
	DDX_Control(pDX, IDC_PRE_BTN, m_PreBtn);
	DDX_Control(pDX, IDC_PLAY_BTN, m_PlayBtn);
	DDX_Control(pDX, IDC_OPEN_BTN, m_OpenBtn);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPlayWavDlg, CDialog)
	//{{AFX_MSG_MAP(CPlayWavDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_BTN, OnOpenBtn)
	ON_BN_CLICKED(IDC_PLAY_BTN, OnPlayBtn)
	ON_BN_CLICKED(IDC_PRE_BTN, OnPreBtn)
	ON_BN_CLICKED(IDC_CLOSE_BTN, OnCloseBtn)
	ON_BN_CLICKED(IDC_STOP_BTN, OnStopBtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlayWavDlg message handlers

BOOL CPlayWavDlg::OnInitDialog()
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
	m_OpenBtn.EnableWindow(TRUE);
	m_PlayBtn.EnableWindow(FALSE);
	m_PreBtn.EnableWindow(FALSE);
	m_StopBtn.EnableWindow(FALSE);
	m_CloseBtn.EnableWindow(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPlayWavDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPlayWavDlg::OnPaint() 
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
HCURSOR CPlayWavDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPlayWavDlg::OnOpenBtn() 
{
	char  szFilter[] = "wav文件 (*.wav)|*.wav|All Files (*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter, NULL);
    CString strTmp;
	if(IDOK != dlg.DoModal())
	{
		return;
	}
	strTmp = dlg.GetPathName();

	MCI_OPEN_PARMS  OpenParms; 
	OpenParms.lpstrDeviceType = (LPCSTR) MCI_DEVTYPE_WAVEFORM_AUDIO;//MIDI类型 
	OpenParms.lpstrElementName = (LPCSTR)strTmp;//播放的文件名 
	OpenParms.wDeviceID = 0; //MCI设备ID。
	DWORD dwResult = mciSendCommand (NULL, MCI_OPEN, MCI_WAIT | MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID | MCI_OPEN_ELEMENT, (DWORD)(LPVOID) &OpenParms) ;
    if(dwResult)
	{
		MessageBox("打开失败");

	}
	else
	{
		m_PlayBtn.EnableWindow(TRUE);
		m_PreBtn.EnableWindow(TRUE);
		m_StopBtn.EnableWindow(TRUE);
		m_CloseBtn.EnableWindow(TRUE);
	}
	m_nDeviceID = OpenParms.wDeviceID;	
}

void CPlayWavDlg::OnPlayBtn() 
{
   	MCI_PLAY_PARMS PlayParms; 
	PlayParms.dwFrom = 0; // 指定从什么地方（时间）播放 
	mciSendCommand (m_nDeviceID, MCI_PLAY, MCI_FROM, (DWORD)(LPVOID) &PlayParms);
}

void CPlayWavDlg::OnPreBtn() 
{
	mciSendCommand (m_nDeviceID, MCI_SEEK, 
		MCI_SEEK_TO_START, NULL); 
}



void CPlayWavDlg::OnCloseBtn() 
{
    mciSendCommand (m_nDeviceID, MCI_CLOSE, NULL, NULL); 
		m_OpenBtn.EnableWindow(TRUE);
	m_PlayBtn.EnableWindow(FALSE);
	m_PreBtn.EnableWindow(FALSE);
	m_StopBtn.EnableWindow(FALSE);
	m_CloseBtn.EnableWindow(FALSE);
}

void CPlayWavDlg::OnStopBtn() 
{
	MCI_PLAY_PARMS PlayParms; 
	mciSendCommand (m_nDeviceID, MCI_PAUSE, 0, (DWORD)(LPVOID) &PlayParms);

}
