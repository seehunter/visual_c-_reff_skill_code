// ADODlg.cpp : implementation file
//

#include "stdafx.h"
#include "ADO.h"
#include "ADODlg.h"

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
// CADODlg dialog

CADODlg::CADODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADODlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CADODlg)
	m_strName = _T("");
	m_strSex = _T("");
	m_nAge = 0;
	m_nGrade = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CADODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADODlg)
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_SEX, m_strSex);
	DDX_Text(pDX, IDC_AGE, m_nAge);
	DDX_Text(pDX, IDC_GRADE, m_nGrade);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CADODlg, CDialog)
	//{{AFX_MSG_MAP(CADODlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FIRST, OnFirst)
	ON_BN_CLICKED(IDC_PREV, OnPrev)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_LAST, OnLast)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADODlg message handlers

BOOL CADODlg::OnInitDialog()
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
	
	m_pConnection.CreateInstance(__uuidof(Connection));
	try         
	{ 
		// 打开本地Access库Demo.mdb 
		m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Db1.mdb","","",adModeUnknown); 
	} 
	catch(_com_error e) 
	{ 
		AfxMessageBox("数据库连接失败，确认数据库Db1.mdb是否在当前路径下!"); 
		return FALSE; 
	} 
	m_pRecordset.CreateInstance(__uuidof(Recordset)); 
	try 
	{ 
		m_pRecordset->Open("SELECT * FROM student",        // 查询DemoTable表中所有字段 
			m_pConnection.GetInterfacePtr(), // 获取库接库的IDispatch指针 
			adOpenDynamic, 
			adLockOptimistic, 
			adCmdText); 
	} 
	catch(_com_error *e) 
	{ 
		AfxMessageBox(e->ErrorMessage()); 
	}    


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CADODlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CADODlg::OnPaint() 
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
HCURSOR CADODlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CADODlg::OnFirst() 
{	
	_variant_t var; 
	
	if(!m_pRecordset->BOF) 
		m_pRecordset->MoveFirst(); 
	else 
	{ 
		AfxMessageBox("已经是第一个了"); 
		return; 
	} 	
	var = m_pRecordset->GetCollect("Name"); 
	if(var.vt != VT_NULL) 
	  m_strName	 = (LPCSTR)_bstr_t(var); 
	var = m_pRecordset->GetCollect("Sex"); 
	if(var.vt != VT_NULL) 
		m_strSex = (LPCSTR)_bstr_t(var);
	var = m_pRecordset->GetCollect("Age");
	if(var.vt != VT_NULL)
	{
		m_nAge = atoi(LPCTSTR(_bstr_t(var)));
	}
	var = m_pRecordset->GetCollect("Grade");
	if(var.vt != VT_NULL)
	{
		m_nGrade = atoi(LPCTSTR(_bstr_t(var)));
	}
	UpdateData(FALSE);  
}

void CADODlg::OnPrev() 
{
	_variant_t var; 
	if(m_pRecordset->BOF) 
	{ 
		AfxMessageBox("已经是最后一个了"); 
		return; 
	} 
	 m_pRecordset->MovePrevious();
   	if(m_pRecordset->BOF) 
	{ 
		AfxMessageBox("已经是第一个了"); 
		return; 
	} 
	else
	{
		var = m_pRecordset->GetCollect("Name"); 
		if(var.vt != VT_NULL) 
			m_strName	 = (LPCSTR)_bstr_t(var); 
		var = m_pRecordset->GetCollect("Sex"); 
		if(var.vt != VT_NULL) 
			m_strSex = (LPCSTR)_bstr_t(var);
		var = m_pRecordset->GetCollect("Age");
		if(var.vt != VT_NULL)
		{
			m_nAge = atoi(LPCTSTR(_bstr_t(var)));
		}
		var = m_pRecordset->GetCollect("Grade");
		if(var.vt != VT_NULL)
		{
			m_nGrade = atoi(LPCTSTR(_bstr_t(var)));
		}
		UpdateData(FALSE);  
	}
}

void CADODlg::OnNext() 
{
	_variant_t var; 
	if(m_pRecordset->adoEOF) 
	{ 
		AfxMessageBox("已经是最后一个了"); 
		return; 
	} 
    m_pRecordset->MoveNext();
   	if(m_pRecordset->adoEOF) 
	{ 
		AfxMessageBox("已经是最后一个了"); 
		return; 
	} 
	else
	{
	    
		var = m_pRecordset->GetCollect("Name"); 
		if(var.vt != VT_NULL) 
			m_strName	 = (LPCSTR)_bstr_t(var); 
		var = m_pRecordset->GetCollect("Sex"); 
		if(var.vt != VT_NULL) 
			m_strSex = (LPCSTR)_bstr_t(var);
		var = m_pRecordset->GetCollect("Age");
		if(var.vt != VT_NULL)
		{
			m_nAge = atoi(LPCTSTR(_bstr_t(var)));
		}
		var = m_pRecordset->GetCollect("Grade");
		if(var.vt != VT_NULL)
		{
			m_nGrade = atoi(LPCTSTR(_bstr_t(var)));
		}
		UpdateData(FALSE);  
	}
}

void CADODlg::OnLast() 
{	_variant_t var; 

	
	if(!m_pRecordset->adoEOF) 
		m_pRecordset->MoveLast(); 
	else 
	{ 
		AfxMessageBox("已经是最后一个了"); 
		return; 
	} 	
	var = m_pRecordset->GetCollect("Name"); 
	if(var.vt != VT_NULL) 
	  m_strName	 = (LPCSTR)_bstr_t(var); 
	var = m_pRecordset->GetCollect("Sex"); 
	if(var.vt != VT_NULL) 
		m_strSex = (LPCSTR)_bstr_t(var);
	var = m_pRecordset->GetCollect("Age");
	if(var.vt != VT_NULL)
	{
		m_nAge = atoi(LPCTSTR(_bstr_t(var)));
	}
	var = m_pRecordset->GetCollect("Grade");
	if(var.vt != VT_NULL)
	{
		m_nGrade = atoi(LPCTSTR(_bstr_t(var)));
	}
	UpdateData(FALSE);  	
}
