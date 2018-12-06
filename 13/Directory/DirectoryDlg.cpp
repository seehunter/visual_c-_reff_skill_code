// DirectoryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Directory.h"
#include "DirectoryDlg.h"

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
// CDirectoryDlg dialog

CDirectoryDlg::CDirectoryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDirectoryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDirectoryDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDirectoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDirectoryDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDirectoryDlg, CDialog)
	//{{AFX_MSG_MAP(CDirectoryDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDirectoryDlg message handlers

BOOL CDirectoryDlg::OnInitDialog()
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
	GetDirectory();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDirectoryDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDirectoryDlg::OnPaint() 
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
HCURSOR CDirectoryDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/************************************************************************/
/* 
/************************************************************************/
void CDirectoryDlg::GetDirectory()
{
	/*获取当前目录*/
	char  szDirectory[MAX_PATH+1];//缓冲区
	int nErrorCode = 0;
	int nRet = 0;
	CString strTmp;
	memset(szDirectory,0,sizeof(char)*(MAX_PATH+1));//清空缓冲区
	nRet = GetCurrentDirectory(MAX_PATH+1,szDirectory);//获取当前目录
	if(nRet == 0)
	{
        nErrorCode = GetLastError();
		strTmp.Format("获取当前目录出现错误，错误代码为%d",nErrorCode);
		MessageBox(strTmp);
    }
	SetDlgItemText(IDC_CURRENT_DIRECTORY,szDirectory);
    /*获取系统目录*/
	memset(szDirectory,0,sizeof(char)*(MAX_PATH+1));//清空缓冲区
	nRet = GetSystemDirectory(szDirectory,MAX_PATH+1);//获取系统目录
	if(nRet == 0)
	{
        nErrorCode = GetLastError();
		strTmp.Format("获取当前目录出现错误，错误代码为%d",nErrorCode);
		MessageBox(strTmp);
    }
	SetDlgItemText(IDC_SYSTEM_DIRECTORY,szDirectory);
	/*获取 Windows目录*/
    memset(szDirectory,0,sizeof(char)*(MAX_PATH+1));//清空缓冲区
	nRet = GetWindowsDirectory(szDirectory,MAX_PATH+1);//获取系统目录
	if(nRet == 0)
	{
        nErrorCode = GetLastError();
		strTmp.Format("获取当前目录出现错误，错误代码为%d",nErrorCode);
		MessageBox(strTmp);
    }
	SetDlgItemText(IDC_WINDOWS_DIRECTORY,szDirectory);
	/*获取临时路径*/
    memset(szDirectory,0,sizeof(char)*(MAX_PATH+1));//清空缓冲区
	nRet = GetTempPath(MAX_PATH+1,szDirectory);//获取系统目录
	if(nRet == 0)
	{
        nErrorCode = GetLastError();
		strTmp.Format("获取当前目录出现错误，错误代码为%d",nErrorCode);
		MessageBox(strTmp);
    }
	SetDlgItemText(IDC_TEMP_DIRECTORY,szDirectory);
	/*获取Desktop  的目录*/
	memset(szDirectory,0,sizeof(char)*(MAX_PATH+1));//清空缓冲区
	HRESULT hr ;
	ITEMIDLIST* itemList = new ITEMIDLIST;
	hr = SHGetSpecialFolderLocation(0,CSIDL_COMMON_DESKTOPDIRECTORY,&itemList);
	if(hr == NOERROR)
	{
       SHGetPathFromIDList(itemList,szDirectory);
	   SetDlgItemText(IDC_DESKTOP_DIRECTORY,szDirectory);
	}
	/*获取开始菜单目录*/
	memset(szDirectory,0,sizeof(char)*(MAX_PATH+1));//清空缓冲区
	hr = SHGetSpecialFolderLocation(0,CSIDL_COMMON_STARTMENU,&itemList);
	if(hr == NOERROR)
	{
       SHGetPathFromIDList(itemList,szDirectory);
	   SetDlgItemText(IDC_START_DIRECTORY,szDirectory);
	}
	/*获取启动路径*/
    memset(szDirectory,0,sizeof(char)*(MAX_PATH+1));//清空缓冲区
	hr = SHGetSpecialFolderLocation(0,CSIDL_COMMON_STARTUP ,&itemList);
	if(hr == NOERROR)
	{
       SHGetPathFromIDList(itemList,szDirectory);
	   SetDlgItemText(IDC_STARTUP_ED,szDirectory);
	}
	/*获取收藏夹目录*/
    memset(szDirectory,0,sizeof(char)*(MAX_PATH+1));//清空缓冲区
	hr = SHGetSpecialFolderLocation(0,CSIDL_FAVORITES,&itemList);
	if(hr == NOERROR)
	{
       SHGetPathFromIDList(itemList,szDirectory);
	   SetDlgItemText(IDC_FAVORITE_DIRECTORY,szDirectory);
	}
	/*获取字体目录*/
    memset(szDirectory,0,sizeof(char)*(MAX_PATH+1));//清空缓冲区
	hr = SHGetSpecialFolderLocation(0,CSIDL_FONTS ,&itemList);
	if(hr == NOERROR)
	{
       SHGetPathFromIDList(itemList,szDirectory);
	   SetDlgItemText(IDC_FONT_DIRECTIRY,szDirectory);
	}
    /*获取字体目录*/
    memset(szDirectory,0,sizeof(char)*(MAX_PATH+1));//清空缓冲区
	hr = SHGetSpecialFolderLocation(0,CSIDL_COOKIES ,&itemList);
	if(hr == NOERROR)
	{
       SHGetPathFromIDList(itemList,szDirectory);
	   SetDlgItemText(IDC_COOKIE_DIRECTORY,szDirectory);
	}
	/*获得 Cookie目录*/
	memset(szDirectory,0,sizeof(char)*(MAX_PATH+1));//清空缓冲区
	hr = SHGetSpecialFolderLocation(0,CSIDL_COOKIES ,&itemList);
	if(hr == NOERROR)
	{
       SHGetPathFromIDList(itemList,szDirectory);
	   SetDlgItemText(IDC_COOKIE_DIRECTORY,szDirectory);
	}
	/*获得网页临时文件目录*/
	memset(szDirectory,0,sizeof(char)*(MAX_PATH+1));//清空缓冲区
	hr = SHGetSpecialFolderLocation(0,CSIDL_INTERNET_CACHE   ,&itemList);
	if(hr == NOERROR)
	{
       SHGetPathFromIDList(itemList,szDirectory);
	   SetDlgItemText(IDC_INTENET_TEMP_DIRECTORY,szDirectory);
	}
    /*获得历史目录*/
	memset(szDirectory,0,sizeof(char)*(MAX_PATH+1));//清空缓冲区
	hr = SHGetSpecialFolderLocation(0,CSIDL_HISTORY  ,&itemList);
	if(hr == NOERROR)
	{
       SHGetPathFromIDList(itemList,szDirectory);
	   SetDlgItemText(IDC_HISTORY_DIRCTORY,szDirectory);
	}
}