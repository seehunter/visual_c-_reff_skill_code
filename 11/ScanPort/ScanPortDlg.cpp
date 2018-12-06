// ScanPortDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ScanPort.h"
#include "ScanPortDlg.h"
#include ".\scanportdlg.h"

#include "afxsock.h"

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


// CScanPortDlg 对话框



CScanPortDlg::CScanPortDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScanPortDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScanPortDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CScanPortDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_SCAN, OnBnClickedScan)
END_MESSAGE_MAP()


// CScanPortDlg 消息处理程序

BOOL CScanPortDlg::OnInitDialog()
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

	// TODO: 在此添加额外的初始化代码

	AfxSocketInit();

	DWORD dwExStyle = LVS_EX_GRIDLINES ;
	m_ListCtrl.SetExtendedStyle(dwExStyle);

	m_ListCtrl.InsertColumn(0,"端口号",LVCFMT_CENTER,100);
	m_ListCtrl.InsertColumn(1,"关闭状态",LVCFMT_CENTER,100);
	
	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
}

void CScanPortDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CScanPortDlg::OnPaint() 
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
HCURSOR CScanPortDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CScanPortDlg::OnBnClickedScan()
{
	// TODO: 在此添加控件通知处理程序代码

	CString IP;
	CString staport, endport;

	GetDlgItem(IDC_IP)->GetWindowText(IP);
	GetDlgItem(IDC_STA)->GetWindowText(staport);
	GetDlgItem(IDC_END)->GetWindowText(endport);

	for( int j = atoi(staport), i = 0; i < atoi(endport) - atoi(staport); i++ ){

		BOOL flag = ScanPort(IP, j);
		if( flag ){
			int m_nCurrentSel = m_ListCtrl.InsertItem(0xffff,"");

			char port[10];
			itoa(j, port, 10);

			m_ListCtrl.SetItem( m_nCurrentSel, 0, LVIF_TEXT, ( CString )port, NULL, 0, 0, 0);

			m_ListCtrl.SetItem( m_nCurrentSel, 1, LVIF_TEXT, "开", NULL, 0, 0, 0);
		}else {

			int m_nCurrentSel = m_ListCtrl.InsertItem(0xffff,"");

			char port[10];
			itoa(j, port, 10);

			m_ListCtrl.SetItem( m_nCurrentSel, 0, LVIF_TEXT, ( CString )port, NULL, 0, 0, 0);

			m_ListCtrl.SetItem( m_nCurrentSel, 1, LVIF_TEXT, "关", NULL, 0, 0, 0);

		}

		j++;


	}

	/*WSACleanup();*/
}

BOOL CScanPortDlg::ScanPort(CString IP, int port)
{

	CSocket* pSocket;
	pSocket = new CSocket;

	BOOL flag = pSocket->Create();

	BOOL b = pSocket->Connect("127.0.0.1",80);
	if(!b)
		MessageBox("failed");
	else
		MessageBox("succeed");

	int error = ::GetLastError();
	if (!flag)
	{
		delete pSocket;
		pSocket = NULL;
		return FALSE;
	}
	//连接主机
	while (!pSocket->Connect(IP , port))
	{
		delete pSocket;
		pSocket = NULL;
		return FALSE;
	}
	//清除套接字
	pSocket->Close();
	delete pSocket;

	return TRUE;
}


