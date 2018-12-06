// OpenSetComDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "OpenSetCom.h"
#include "OpenSetComDlg.h"
#include ".\opensetcomdlg.h"

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


// COpenSetComDlg 对话框



COpenSetComDlg::COpenSetComDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COpenSetComDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpenSetComDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COpenSetComDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_SET, OnBnClickedSet)
END_MESSAGE_MAP()


// COpenSetComDlg 消息处理程序

BOOL COpenSetComDlg::OnInitDialog()
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
	
	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
}

void COpenSetComDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COpenSetComDlg::OnPaint() 
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
HCURSOR COpenSetComDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void COpenSetComDlg::OnBnClickedSet()
{
	// TODO: 在此添加控件通知处理程序代码

	COMMTIMEOUTS TimeOuts;

	CString port = "";

	GetDlgItem(IDC_PORT)->GetWindowText(port);

	m_hCom=CreateFile(port, GENERIC_READ | GENERIC_WRITE, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 
		NULL); // 重叠方式

	if(m_hCom==INVALID_HANDLE_VALUE)
		return ;

	SetupComm(m_hCom,MAXBLOCK,MAXBLOCK);
	SetCommMask(m_hCom, EV_RXCHAR);

	
	// 把间隔超时设为最大
	TimeOuts.ReadIntervalTimeout=MAXDWORD; 
	TimeOuts.ReadTotalTimeoutMultiplier=0; 
	TimeOuts.ReadTotalTimeoutConstant=0; 

	
	TimeOuts.WriteTotalTimeoutMultiplier=50;
	TimeOuts.WriteTotalTimeoutConstant=2000;

	SetCommTimeouts(m_hCom, &TimeOuts);

	DCB dcb;

	if(!GetCommState(m_hCom, &dcb))
		return ;

	dcb.fBinary = TRUE;
	CString rate = "";
	GetDlgItem(IDC_RATE)->GetWindowText(rate);
	if( rate == "" ){
		MessageBox("请输入数据传输速率！", "信息提示窗口", MB_OK);
		return;
	}
	dcb.BaudRate = atoi(rate); // 数据传输速率

	CString bit = "";
	GetDlgItem(IDC_BIT)->GetWindowText(bit);
	if( bit == "" ){
		MessageBox("请输入数据传输速率！", "信息提示窗口", MB_OK);
		return;
	}
	dcb.ByteSize = atoi(bit); // 每字节位数
	dcb.fParity = TRUE;

	CString parity = "";
	GetDlgItem(IDC_BAUD)->GetWindowText(parity);
	if( parity == "" ){
		MessageBox("请输入校验位！", "信息提示窗口", MB_OK);
		return ;
	}

	switch(atoi(parity)) // 校验设置
	{
	case 0: 
		dcb.Parity = NOPARITY;
		break;

	case 1: 
		dcb.Parity=EVENPARITY;
		break;

	case 2: 
		dcb.Parity=ODDPARITY;
		break;

	default:;
	}

	CString stop = "";
	GetDlgItem(IDC_STOP)->GetWindowText(stop);
	if( stop == "" ){
		MessageBox("请输入校验位！", "信息提示窗口", MB_OK);
		return ;
	}

	switch(atoi(stop)) // 停止位
	{
	case 0: 
		dcb.StopBits=ONESTOPBIT;
		break;

	case 1: 
		dcb.StopBits=ONE5STOPBITS;
		break;

	case 2:
		dcb.StopBits=TWOSTOPBITS;
		break;

	default:;
	}

	// 硬件流控制设置
	dcb.fOutxCtsFlow = TRUE;
	dcb.fRtsControl = TRUE;

	// XON/XOFF流控制设置
	dcb.fInX=dcb.fOutX = TRUE;
	dcb.XonChar = XON;
	dcb.XoffChar = XOFF;
	dcb.XonLim = 50;
	dcb.XoffLim = 50;

	BOOL flag = SetCommState(m_hCom, &dcb);

	if( flag ){
		MessageBox("串口打开并配置成功！", "信息提示窗口", MB_OK);
		CloseHandle(m_hCom);
		return;
	}else {
		MessageBox("串口操作失败！", "信息提示窗口", MB_OK);
		CloseHandle(m_hCom);
		return;
	}

	return;
}
