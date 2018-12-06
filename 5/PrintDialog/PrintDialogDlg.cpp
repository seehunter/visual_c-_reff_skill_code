// PrintDialogDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PrintDialog.h"
#include "PrintDialogDlg.h"
#include ".\printdialogdlg.h"

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


// CPrintDialogDlg 对话框



CPrintDialogDlg::CPrintDialogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintDialogDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPrintDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPrintDialogDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_PRINT_SETUP, OnBnClickedPrintSetup)
	ON_BN_CLICKED(IDC_PRINT, OnBnClickedPrint)
END_MESSAGE_MAP()


// CPrintDialogDlg 消息处理程序

BOOL CPrintDialogDlg::OnInitDialog()
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

void CPrintDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPrintDialogDlg::OnPaint() 
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
HCURSOR CPrintDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPrintDialogDlg::OnBnClickedPrintSetup()
{
	// TODO: 在此添加控件通知处理程序代码

	CPrintDialog dlg(TRUE, PD_PAGENUMS | PD_USEDEVMODECOPIES);
	dlg.m_pd.nMinPage = dlg.m_pd.nFromPage = 1;//设置打印对话框的初始打印页
	dlg.m_pd.nMaxPage = dlg.m_pd.nToPage = 10;//设置打印对话框的结束打印页
	if( dlg.DoModal() == IDOK ){
		//根据用户的选择进行打印

		LPDEVMODE  mode = dlg.GetDevMode();

		CString large = ( CString )mode->dmFormName;

		GetDlgItem(IDC_LARGE)->SetWindowText(large);

		if( mode->dmDefaultSource == 7 ){

			GetDlgItem(IDC_SOURCE)->SetWindowText("自动选择");

		}else {

			GetDlgItem(IDC_SOURCE)->SetWindowText("手动送纸");

		}

		if( mode->dmOrientation == 1 ){//设置纸张打印方向
			( ( CButton* )GetDlgItem(IDC_COL) )->SetCheck(FALSE);
			( ( CButton* )GetDlgItem(IDC_ROW) )->SetCheck(TRUE);
		}else {

			( ( CButton* )GetDlgItem(IDC_COL) )->SetCheck(TRUE);
			( ( CButton* )GetDlgItem(IDC_ROW) )->SetCheck(FALSE);
		}


		int error = ::GetLastError();
	}

}

void CPrintDialogDlg::OnBnClickedPrint()
{
	// TODO: 在此添加控件通知处理程序代码

	CPrintDialog dlg(FALSE, PD_PAGENUMS | PD_USEDEVMODECOPIES);
	dlg.m_pd.nMinPage = dlg.m_pd.nFromPage = 1;//设置打印对话框的初始打印页
	dlg.m_pd.nMaxPage = dlg.m_pd.nToPage = 100;//设置打印对话框的结束打印页
	if( dlg.DoModal() == IDOK ){
		//根据用户的选择进行打印

		LPDEVMODE  mode = dlg.GetDevMode();

		char copy[10];//示例程序，实际应用中不能使用常数

		itoa(mode->dmCopies, copy, 10);

		CString copies = copy;

		GetDlgItem(IDC_SOME)->SetWindowText(copies);

		if( dlg.PrintAll()!= 0 ){

			( ( CButton* )GetDlgItem(IDC_ALL) )->SetCheck(TRUE);
			( ( CButton* )GetDlgItem(IDC_RANGE) )->SetCheck(FALSE);
			( ( CButton* )GetDlgItem(IDC_SELECT) )->SetCheck(FALSE);

			GetDlgItem(IDC_START)->SetWindowText("");
			GetDlgItem(IDC_END)->SetWindowText("");

		}else if( dlg.PrintSelection() != 0 ){

			( ( CButton* )GetDlgItem(IDC_ALL) )->SetCheck(FALSE);
			( ( CButton* )GetDlgItem(IDC_RANGE) )->SetCheck(FALSE);
			( ( CButton* )GetDlgItem(IDC_SELECT) )->SetCheck(TRUE);

			GetDlgItem(IDC_START)->SetWindowText("");
			GetDlgItem(IDC_END)->SetWindowText("");


		}else {

			( ( CButton* )GetDlgItem(IDC_ALL) )->SetCheck(FALSE);
			( ( CButton* )GetDlgItem(IDC_RANGE) )->SetCheck(TRUE);
			( ( CButton* )GetDlgItem(IDC_SELECT) )->SetCheck(FALSE);

			char range[10];//实际应用不建议使用常数

			itoa(dlg.GetFromPage(), range, 10);

			CString ranges  = range;

			GetDlgItem(IDC_START)->SetWindowText(ranges);
			
			itoa(dlg.GetToPage(), range, 10);
			ranges = range;
			GetDlgItem(IDC_END)->SetWindowText(ranges);

		}

		int error = ::GetLastError();

		MessageBox("哈哈，不能打印，这只是演示！", "信息提示窗口", MB_OK);
	}
}
