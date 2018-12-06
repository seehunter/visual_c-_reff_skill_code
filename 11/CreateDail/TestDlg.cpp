// TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Test.h"
#include "TestDlg.h"

#include "Ras.h"

#include "ras.h"
#include "raserror.h"
#include ".\testdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTestDlg 对话框



CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CONNECT, OnBnClickedConnect)
	ON_BN_CLICKED(IDC_CLOSE, OnBnClickedClose)
END_MESSAGE_MAP()


// CTestDlg 消息处理程序

BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将\“关于...\”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	
	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
}

void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestDlg::OnBnClickedCancel()
{
	OnCancel();
}

void CTestDlg::OnBnClickedConnect()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData( TRUE );
    RASDIALPARAMS rdParams;
    rdParams.dwSize = sizeof(RASDIALPARAMS);
	rdParams.szEntryName[0] = '\0';

	CString photo = "";//用于存放用户输入的电话号码
	GetDlgItem(IDC_EDIT3)->GetWindowText(photo);

	if( photo == "" ){
		MessageBox("请输入电话号码！", "信息提示窗口", MB_OK);
		return ;
	}
	lstrcpy( rdParams.szPhoneNumber, photo);
	rdParams.szCallbackNumber[0] = '\0';

	CString name = "";//用于存放用户姓名
	GetDlgItem(IDC_EDIT1)->GetWindowText(name);

	if( name == "" ){
		MessageBox("请输入用户姓名！", "信息提示窗口", MB_OK);
		return ;
	}

	lstrcpy( rdParams.szUserName, name );

	CString password = "";//用于存放用户输入的密码信息。
	GetDlgItem(IDC_EDIT2)->GetWindowText(password);

	if( password == "" ){
		MessageBox("请输入用户密码！", "信息提示窗口", MB_OK);
		return ;
	}
	lstrcpy( rdParams.szPassword, password);
	rdParams.szDomain[0] = '\0';
	HRASCONN hRasConn = NULL;
    DWORD dwRet = RasDial( NULL, NULL, &rdParams, 0L, NULL, &hRasConn );
    if ( dwRet == 0 )  return ;
    char  szBuf[256];
	if ( RasGetErrorString( (UINT)dwRet, (LPSTR)szBuf, 256 ) != 0 )
		wsprintf( (LPSTR)szBuf, "未知拨号错误： (%ld).", dwRet );
	RasHangUp( hRasConn );
	MessageBox( (LPSTR)szBuf, "信息提示窗口", MB_OK | MB_ICONSTOP );	
}

void CTestDlg::OnBnClickedClose()
{
	// TODO: 在此添加控件通知处理程序代码
	RASCONN ras[20];
	DWORD  dSize, dNumber;
	char  szBuf[256];	
	ras[0].dwSize = sizeof( RASCONN );
	dSize = sizeof( ras );   
	DWORD  dwRet = RasEnumConnections( ras, &dSize, &dNumber );
	if ( dwRet != 0 )
	{
		if ( RasGetErrorString( (UINT)dwRet, (LPSTR)szBuf, 256 ) != 0 )
			wsprintf( (LPSTR)szBuf, "未定义连接错误 (%ld).", dwRet );
		MessageBox( (LPSTR)szBuf, "信息提示窗口", MB_OK | MB_ICONSTOP );
		return ;
	}
	for( DWORD dCount = 0;  dCount < dNumber;  dCount++ )
	{   
		HRASCONN hRasConn = ras[dCount].hrasconn;
		DWORD dwRet = RasHangUp( hRasConn );
		if ( dwRet != 0 )
		{
			char  szBuf[256];
			if ( RasGetErrorString( (UINT)dwRet, (LPSTR)szBuf, 256 ) != 0 )
				wsprintf( (LPSTR)szBuf, "Undefined RAS HangUp Error (%ld).", dwRet );
			MessageBox( (LPSTR)szBuf, "RasHangUp", MB_OK | MB_ICONSTOP );
		}
	}	
}
