// AdapersDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Adapers.h"
#include "AdapersDlg.h"
#include ".\adapersdlg.h"

#include "Iphlpapi.h"

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


// CAdapersDlg 对话框



CAdapersDlg::CAdapersDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdapersDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdapersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAdapersDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_GETADA, OnBnClickedGetada)
END_MESSAGE_MAP()


// CAdapersDlg 消息处理程序

BOOL CAdapersDlg::OnInitDialog()
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

void CAdapersDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAdapersDlg::OnPaint() 
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
HCURSOR CAdapersDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAdapersDlg::OnBnClickedGetada()
{
	// TODO: 在此添加控件通知处理程序代码

	GetInfo();
}


int CAdapersDlg::GetInfo()
{
    PIP_ADAPTER_INFO pinfo=NULL;
	unsigned long len=0;

	if (pinfo!=NULL)
		delete (pinfo);
	unsigned  long nError;

	//获得本地计算机的网络信息

	CString m_getIPMask = "";
	nError	=	GetAdaptersInfo(pinfo,&len);
	if (nError==0)
	{
		m_getIPMask.Format("%s",pinfo->IpAddressList.IpMask.String);
		UpdateData(FALSE);
	}
	if (nError==ERROR_NO_DATA)
	{
		AfxMessageBox("No adapter information exists for the local computer");
	}
	if (nError==ERROR_NOT_SUPPORTED)
	{
		AfxMessageBox("GetAdaptersInfo is not supported by the operating system running on the local computer");
	}
	if (nError==ERROR_BUFFER_OVERFLOW)
	{
		pinfo= (PIP_ADAPTER_INFO)malloc(len);
		nError	=	GetAdaptersInfo(pinfo,&len);
		if (nError==0)
		{
			m_getIPMask.Format("%s",pinfo->IpAddressList.IpMask.String);
			UpdateData(FALSE);
		}
	}

	GetDlgItem(IDC_EDIT1)->SetWindowText(m_getIPMask);

	if (pinfo!=NULL)
		delete (pinfo);
	return 0;
}
