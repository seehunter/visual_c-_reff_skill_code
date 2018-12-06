// DataExchangeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DataExchange.h"
#include "DataExchangeDlg.h"

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
// CDataExchangeDlg dialog

CDataExchangeDlg::CDataExchangeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDataExchangeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataExchangeDlg)
	m_mAge = 0;
	m_nGrade = 0;
	m_strName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDataExchangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataExchangeDlg)
	DDX_Text(pDX, IDC_AGE_ED, m_mAge);
	DDX_Text(pDX, IDC_GRADE_ED, m_nGrade);
	DDX_Text(pDX, IDC_STU_NAME_ED, m_strName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDataExchangeDlg, CDialog)
	//{{AFX_MSG_MAP(CDataExchangeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BTN, OnAddBtn)
	ON_BN_CLICKED(IDC_PRE_BTN, OnPreBtn)
	ON_BN_CLICKED(IDC_NEXT_BTN, OnNextBtn)
	ON_BN_CLICKED(IDC_INPUT, OnInput)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataExchangeDlg message handlers

BOOL CDataExchangeDlg::OnInitDialog()
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
	m_stu.SetSize(16,8);
	m_nIndex = 0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDataExchangeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDataExchangeDlg::OnPaint() 
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
HCURSOR CDataExchangeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDataExchangeDlg::OnAddBtn() 
{
   	UpdateData(TRUE);//数据映射函数
	stu  tempstu;
	tempstu.strName = m_strName;
	tempstu.nAge = m_mAge;
	tempstu.nGrade = m_nGrade;
	m_stu.SetAt(m_nIndex,tempstu);
	m_nIndex++;
    m_strName = "";
    m_mAge = 0;
	m_nGrade = 0;
	UpdateData(FALSE);
}

void CDataExchangeDlg::OnPreBtn() 
{
    m_nIndex--;
	if(m_nIndex<0)
	{
		MessageBox("向上没有了");
		return ;
	}
    m_strName = m_stu.GetAt(m_nIndex).strName;
    m_mAge = m_stu.GetAt(m_nIndex).nAge;
	m_nGrade = m_stu.GetAt(m_nIndex).nGrade;
	UpdateData(FALSE);
}

void CDataExchangeDlg::OnNextBtn() 
{
	if(m_nIndex<m_stu.GetSize())
	{
		m_nIndex++;
	}
	else if(m_nIndex>=m_stu.GetSize())
	{
       MessageBox("向下没有了");
	}
    m_strName = m_stu.GetAt(m_nIndex).strName;
    m_mAge = m_stu.GetAt(m_nIndex).nAge;
	m_nGrade = m_stu.GetAt(m_nIndex).nGrade;
	UpdateData(FALSE);	
}

void CDataExchangeDlg::OnInput() 
{
	
}
