// AutoStartDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AutoStart.h"
#include "AutoStartDlg.h"

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
// CAutoStartDlg dialog

CAutoStartDlg::CAutoStartDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutoStartDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAutoStartDlg)
	m_filename = _T("");
	m_strTitle = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutoStartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutoStartDlg)
	DDX_Text(pDX, IDC_FILE_PATH, m_filename);
	DDX_Text(pDX, IDC_TITLE_ED, m_strTitle);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAutoStartDlg, CDialog)
	//{{AFX_MSG_MAP(CAutoStartDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BROWER_BTN, OnBrowerBtn)
	ON_BN_CLICKED(IDC_REG_BTN, OnRegBtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoStartDlg message handlers

BOOL CAutoStartDlg::OnInitDialog()
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

void CAutoStartDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAutoStartDlg::OnPaint() 
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
HCURSOR CAutoStartDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/************************************************************************/
/* 
/************************************************************************/
void CAutoStartDlg::OnBrowerBtn() 
{
	// TODO: Add your control notification handler code here 
	UpdateData(TRUE);
	CFileDialog  fildDlg(TRUE,_T("exe"),_T("*.exe"),OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,(_T("EXE 文件 (*.exe) |*.exe ||")));
	if(fildDlg.DoModal()==IDOK)//当操作者选择OK时，程序，取得选择文//件的全路径名（包括文件的路径及文件名称），并将相应的数值传输给相//关的控件变量。 
	{ 
		m_filename=fildDlg.GetPathName();//m_filename是EDIT BOX控件的相应的变量。 
		UpdateData(FALSE);//向将变量中的数值传输给控件显示出来。 
	} 

}
/************************************************************************/
/* 
/************************************************************************/
void CAutoStartDlg::OnRegBtn() 
{
	UpdateData(TRUE);
	if(m_strTitle == _T(""))
	{
		MessageBox("子项标题为空");
		return ;
	}

   	if(m_filename == _T(""))
	{
		MessageBox("自启动路径为空, 请检查!");
		return ;
	}
	HKEY hKey; 
	LPCTSTR data_Set="Software\\Microsoft\\Windows\\CurrentVersion\\Run";//设置注册表中相关的路径 
	LONG nRet=(::RegOpenKeyEx(HKEY_LOCAL_MACHINE,data_Set,0,KEY_WRITE,&hKey));//打开注册表中的相应项 
	if(nRet = ERROR_SUCCESS) 
	{ 
		MessageBox("错误0"); 
	} 
	else
	{
		int nLen = m_filename.GetLength();
		BYTE* lpBuff = new BYTE[nLen];
		memset(lpBuff,0,sizeof(BYTE)*nLen);
		memcpy(lpBuff,m_filename.GetBuffer(nLen),nLen);
		long ret1=(::RegSetValueEx(hKey,m_strTitle,NULL,REG_SZ,lpBuff,nLen));//将相关的信息写入注册表。 
		if(ret1!=ERROR_SUCCESS)//判断系统的相关注册是否成功？ 
		{ 
			MessageBox("写注册表错误!"); 
		} 
		delete lpBuff; 
		::RegCloseKey(hKey);//关闭注册表中的相应的项 
	} 
}
