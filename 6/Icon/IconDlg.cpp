// IconDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Icon.h"
#include "IconDlg.h"

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
// CIconDlg dialog

CIconDlg::CIconDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIconDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIconDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIconDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIconDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIconDlg, CDialog)
	//{{AFX_MSG_MAP(CIconDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GET_APPLICATION_ICON, OnGetApplicationIcon)
	ON_BN_CLICKED(IDC_SET_APPLICATION_ICON, OnSetApplicationIcon)
	ON_BN_CLICKED(IDC_LOAD_ICON, OnLoadIcon)
	ON_BN_CLICKED(IDC_SYSTEM_SALVER_SET, OnSystemSalverSet)
	ON_BN_CLICKED(IDC_GET_ICON_SIZE, OnGetIconSize)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIconDlg message handlers

BOOL CIconDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CIconDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIconDlg::OnPaint() 
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
HCURSOR CIconDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
//////////////////////////////////////////////////////////
//获得应用程序图标
void CIconDlg::OnGetApplicationIcon() 
{
	CFileDialog fileDialog(TRUE,"*.ICO",NULL,NULL,"资源文件(*.ICO,*.BMP,*.EXE,*.DLL,*.ICL)|*.ICO;*.BMP;*.EXE;*.DLL;*.ICL||");
	if(fileDialog.DoModal()==IDOK) 
	{	
		//以下是用SHGetFileInfo获得图标：
		CString strOpenFileName=fileDialog.GetPathName();
		SHFILEINFO  shfileinfo;
		if(::SHGetFileInfo(strOpenFileName,0,&shfileinfo,sizeof(shfileinfo),SHGFI_ICON))
		{
			HICON  hIcon=shfileinfo.hIcon;
			CClientDC  clientdc(this);
			clientdc.DrawIcon(20,20,hIcon);//在指定设备描述表中画一个图标
			clientdc.DeleteDC;//删除DC
		}
		//以下是用ExtractIcon获得图标：
        /*CString strOpenFileName=fileDialog.GetPathName();
		CClientDC clientDc(this);
		HICON hIcon=::ExtractIcon(AfxGetApp()->m_hInstance,strOpenFileName,0);
		if(hIcon&&hIcon!=(HICON)-1)
			clientDc.DrawIcon(20,20,hIcon);//在指定设备描述表中画一个图标
		DestroyIcon(hIcon);//取消图标*/
	}
}
//////////////////////////////////////////////////////////
//设置应用程序图标
void CIconDlg::OnSetApplicationIcon() 
{
    HICON m_hIcon;
    m_hIcon=AfxGetApp()->LoadIcon(IDI_ICON_IMPOT);//加载图标资源
    SetIcon(m_hIcon,FALSE);//设置图标
}
///////////////////////////////////////////////////////////
//直接从文件中装入一个图标
void CIconDlg::OnLoadIcon() 
{
	CFileDialog fileDialog(TRUE,"*.ICO",NULL,NULL,"资源文件(*.ICO)|*.ICO||");
	if(fileDialog.DoModal()==IDOK) 
	{	
		CString strOpenFileName=fileDialog.GetPathName();
	    HICON hicon=(HICON)LoadImage(NULL,strOpenFileName,IMAGE_ICON,0,0,LR_LOADFROMFILE);
		CClientDC  clientdc(this);
		clientdc.DrawIcon(20,20,hicon);
		clientdc.DeleteDC;//删除DC
	}	
}
///////////////////////////////////////////////////////////
//设置系统托盘图标
void CIconDlg::OnSystemSalverSet() 
{
	HICON hIcon;
	char szIcon[]="鼠标在图标上！";	
	HINSTANCE hInst=AfxFindResourceHandle(MAKEINTRESOURCE(IDR_MAINFRAME),RT_GROUP_ICON);				
	hIcon=(HICON)LoadImage(hInst,MAKEINTRESOURCE(IDR_MAINFRAME),IMAGE_ICON,16,16,LR_DEFAULTCOLOR);
	NOTIFYICONDATA nid;
    nid.cbSize=sizeof(NOTIFYICONDATA); 
    nid.hWnd=m_hWnd; 
    nid.uID=IDR_MAINFRAME; 
    nid.uFlags=NIF_MESSAGE | NIF_ICON | NIF_TIP; 
	nid.hIcon=hIcon;     			
	if(szIcon) 
        lstrcpyn(nid.szTip,szIcon,sizeof(nid.szTip)); 
    else 
        nid.szTip[0]='\0'; 
 	//调用Shell_NotifyIcon函数通过NIM_ADD向任务栏添加图标
	Shell_NotifyIcon(NIM_ADD,&nid);
	if(hIcon)
		DestroyIcon(hIcon);//释放图标资源
}
///////////////////////////////////////////////////////////
//获取默认图标大小
void CIconDlg::OnGetIconSize() 
{
	CString strIconSize;
	strIconSize.Format("默认图标的大小为:X方向为%d，Y方向为 %d。",
		GetSystemMetrics(SM_CXICON),GetSystemMetrics(SM_CYICON));
	MessageBox(strIconSize,"提示",MB_OK);	
}
