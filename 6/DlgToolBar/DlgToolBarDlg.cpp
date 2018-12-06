// DlgToolBarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DlgToolBar.h"
#include "DlgToolBarDlg.h"

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
// CDlgToolBarDlg dialog

CDlgToolBarDlg::CDlgToolBarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgToolBarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgToolBarDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgToolBarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgToolBarDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgToolBarDlg, CDialog)
	//{{AFX_MSG_MAP(CDlgToolBarDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgToolBarDlg message handlers
BOOL CDlgToolBarDlg::OnInitDialog()
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
	////////////////////////////////////
	//创建工具条并调入资源   
	if(!m_wndToolBar.Create(this)||!m_wndToolBar.LoadToolBar(IDR_TOOLBAR1))   
	{   
		TRACE0("Failed to Create Dialog Toolbar\n");   
		EndDialog(IDCANCEL);   
	}
	CRect rcClientOld;//旧客户区RECT   
	CRect rcClientNew;//加入TOOLBAR后的CLIENT RECT   
	GetClientRect(rcClientOld); 
	//重新计算RECT大小   
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0,reposQuery,rcClientNew);
	//所有的子窗口将被移动，以免被TOOLBAR覆盖
	//计算移动的距离   
	CPoint ptOffset(rcClientNew.left-rcClientOld.left,rcClientNew.top-rcClientOld.top);
	CRect rcChild;   
	CWnd* pwndChild=GetWindow(GW_CHILD);//得到子窗口   
	while(pwndChild)//处理所有子窗口   
	{//移动所有子窗口   
		pwndChild->GetWindowRect(rcChild);   
		ScreenToClient(rcChild);     
		rcChild.OffsetRect(ptOffset);     
		pwndChild->MoveWindow(rcChild,FALSE);     
		pwndChild=pwndChild->GetNextWindow();   
	}
	CRect rcWindow;
	GetWindowRect(rcWindow);//得到对话框RECT   
	rcWindow.right+=rcClientOld.Width()-rcClientNew.Width();//修改对话框尺寸   
	rcWindow.bottom+=rcClientOld.Height()-rcClientNew.Height();     
	MoveWindow(rcWindow,FALSE);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
	//
	////////////////////////////////////
	/*if(!m_wndToolBar.CreateEx(this,TBSTYLE_FLAT,WS_CHILD|WS_VISIBLE|CBRS_ALIGN_TOP|
		CBRS_GRIPPER|CBRS_TOOLTIPS,CRect(4,4,0,0))||!m_wndToolBar.LoadToolBar(IDR_TOOLBAR1))   
	{   
		TRACE0("Failed to Create Dialog Toolbar\n");  
		return  FALSE;               
	}   
	m_wndToolBar.ShowWindow(SW_SHOW);   
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);*/
	//
	////////////////////////////////////
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDlgToolBarDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDlgToolBarDlg::OnPaint() 
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
HCURSOR CDlgToolBarDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


