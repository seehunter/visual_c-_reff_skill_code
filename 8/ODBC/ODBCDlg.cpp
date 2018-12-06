// ODBCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ODBC.h"
#include "ODBCDlg.h"
#include <Odbcinst.h>

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
// CODBCDlg dialog

CODBCDlg::CODBCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CODBCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CODBCDlg)
	m_strUserName = _T("");
	m_strPassword = _T("");
	m_strDescript = _T("");
	m_strDataSource = _T("");
	m_strDBName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CODBCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CODBCDlg)
	DDX_Control(pDX, IDC_LIST, m_List);
	DDX_Text(pDX, IDC_USER_NAME_ED, m_strUserName);
	DDX_Text(pDX, IDC_PASSWORD_ED, m_strPassword);
	DDX_Text(pDX, IDC_DESCRIPT_ED, m_strDescript);
	DDX_Text(pDX, IDC_DATA_SOURCE_ED, m_strDataSource);
	DDX_Text(pDX, IDC_DB_NAME_ED, m_strDBName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CODBCDlg, CDialog)
	//{{AFX_MSG_MAP(CODBCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CREATE_BTN, OnCreateBtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBCDlg message handlers

BOOL CODBCDlg::OnInitDialog()
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

void CODBCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CODBCDlg::OnPaint() 
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
HCURSOR CODBCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CODBCDlg::OnCreateBtn() 
{
   UpdateData();
   char  szDest[1024];
   MystrCpy(szDest,LPCTSTR(m_strDataSource),LPCTSTR("Local"),LPCTSTR(m_strDBName),LPCTSTR(m_strDescript));
   BOOL bSucceed = SQLConfigDataSource(NULL,ODBC_ADD_SYS_DSN,(LPCSTR)"SQL Server\0",(LPCSTR)szDest);
   if(bSucceed)
   {
	   CString strTemp = "";
	   strTemp.Format("%s 创建成功",m_strDataSource);// + "";
	   m_List.AddString(strTemp);
   }
   else
   {
	   CString strTemp = "";
	   strTemp.Format("%s 创建失败",m_strDataSource);// + "";
	   m_List.AddString(strTemp);
   }

   
}
////////////////////////////////////////////////////////////////////
//合并字符串 字符串之间以'\0'为间隔
void CODBCDlg::MystrCpy(char* dest,const char* source,const char* source1,const char* source2,const char* source3)
{
	int   len   =   strlen(source);   
    while(   len   >   0   )   
	{   
		*dest   =   *source;   
		source++;   
		dest++;   
		len--;   
	}  
    *dest++ = '\0';
	len   =   strlen(source1);   
    while(   len   >   0   )   
	{   
		*dest   =   *source1;   
		source1++;   
		dest++;   
		len--;   
	}  
	*dest++ = '\0';
	len   =   strlen(source2);   
    while(   len   >   0   )   
	{   
		*dest   =   *source2;   
		source2++;   
		dest++;   
		len--;   
	} 
	*dest++ = '\0';
    len   =   strlen(source3);   
    while(   len   >   0   )   
	{   
		*dest   =   *source3;   
		source3++;   
		dest++;   
		len--;   
	}  
}
