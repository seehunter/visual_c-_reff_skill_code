// PageSetupDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PageSetup.h"
#include "PageSetupDlg.h"
#include ".\pagesetupdlg.h"

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


// CPageSetupDlg 对话框



CPageSetupDlg::CPageSetupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPageSetupDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPageSetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PORTRAIT, M_Way);
}

BEGIN_MESSAGE_MAP(CPageSetupDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_PAGESETUP, OnBnClickedPagesetup)
END_MESSAGE_MAP()


// CPageSetupDlg 消息处理程序

BOOL CPageSetupDlg::OnInitDialog()
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

void CPageSetupDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPageSetupDlg::OnPaint() 
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
HCURSOR CPageSetupDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPageSetupDlg::OnBnClickedPagesetup()
{
	// TODO: 在此添加控件通知处理程序代码

	CPageSetupDialog PageDlg;

	PageDlg.m_psd.rtMargin.bottom = 100;
	PageDlg.m_psd.rtMargin.left = 100;

	if(PageDlg.DoModal()==IDOK)
	{
		//用户单击确定后，可以通过PageDlg来调用其成员函数来获得用户选择的页面信息。

		CWnd* pWnd = NULL;

		pWnd = GetDlgItem(IDC_DEVICE_NAME);//获得打印机名字

		if( pWnd != NULL ){

			pWnd->SetWindowText( PageDlg.GetDeviceName() );
		}


		LPDEVMODE mode = NULL;

		mode = PageDlg.GetDevMode();

		pWnd = NULL;

		pWnd = GetDlgItem(IDC_LARGE);//获得所选纸张型号

		if( pWnd != NULL ){

			CString name = ( CString )mode->dmFormName;

			pWnd->SetWindowText(name);

		}

		if( mode->dmDefaultSource == 7 ){//设置纸张来源

			GetDlgItem(IDC_SOURCE)->SetWindowText("自动选择");
		}else {

			GetDlgItem(IDC_SOURCE)->SetWindowText("手动送纸");

		}

		if( mode->dmOrientation == 1 ){//设置纸张打印方向
			( ( CButton* )GetDlgItem(IDC_ROW) )->SetCheck(FALSE);
			( ( CButton* )GetDlgItem(IDC_PORTRAIT) )->SetCheck(TRUE);
		}else {

			( ( CButton* )GetDlgItem(IDC_ROW) )->SetCheck(TRUE);
			( ( CButton* )GetDlgItem(IDC_PORTRAIT) )->SetCheck(FALSE);
		}

		RECT rect1;
		RECT rect2;

		PageDlg.GetMargins(&rect1, &rect2);//获得用户输入的页边距

		char len[10];
		itoa(rect1.left * 0.01, len, 10);
		CString marge = len;
		
		GetDlgItem(IDC_LEFT)->SetWindowText( marge );
		itoa(rect1.bottom * 0.01, len, 10);
		marge = len;
		GetDlgItem(IDC_DOWN)->SetWindowText( marge );
		itoa(rect1.right * 0.01, len, 10);
		marge = len;
		GetDlgItem(IDC_RIGHT)->SetWindowText( marge );
		itoa(rect1.top * 0.01, len, 10);
		marge = len;
		GetDlgItem(IDC_UP)->SetWindowText( marge );

		int error = ::GetLastError();

		UpdateData(FALSE);
	}

}
