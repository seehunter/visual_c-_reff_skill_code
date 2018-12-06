// CpuUseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CpuUse.h"
#include "CpuUseDlg.h"
#include "public.h"
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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCpuUseDlg dialog

CCpuUseDlg::CCpuUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCpuUseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCpuUseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
		m_iRefreshInterval = 10;
	m_fNewUsges        = 40;
	m_ForeFontColor    = RGB(255, 0, 0);
	m_ForeColor        = RGB(0, 150, 0);
	m_BackColor        = RGB(0, 0, 0);	
	m_FreeColor		   = RGB(0, 80, 0);
	m_UsedColor        = RGB(0, 140, 0);
	m_LableColor       = RGB(255, 255, 0);
	m_iGridHeight      = 0;
	m_iGridCount       = 50;
	m_liOldIdleTime.QuadPart   = 0;
    m_liOldSystemTime.QuadPart = 0;
}

void CCpuUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCpuUseDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCpuUseDlg, CDialog)
	//{{AFX_MSG_MAP(CCpuUseDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GET_BTN, OnGetBtn)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCpuUseDlg message handlers

BOOL CCpuUseDlg::OnInitDialog()
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
	SetTimer(60000,1000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCpuUseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
/************************************************************************/
/* 
/************************************************************************/
void CCpuUseDlg::OnPaint() 
{
	DrawCpuUsges();
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
HCURSOR CCpuUseDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/************************************************************************/
/* 
/************************************************************************/
void CCpuUseDlg::GetCpuUsgesNt()
{
	SYSTEM_PERFORMANCE_INFORMATION SysPerfInfo;
    SYSTEM_TIME_INFORMATION        SysTimeInfo;
    SYSTEM_BASIC_INFORMATION       SysBaseInfo;
    double                         dbIdleTime;
    double                         dbSystemTime;
    LONG                           status;
    typedef LONG (WINAPI *PROCNTQSI)(UINT,PVOID,ULONG,PULONG);
    PROCNTQSI NtQuerySystemInformation;

    NtQuerySystemInformation = (PROCNTQSI)GetProcAddress(
                                          GetModuleHandle("ntdll"),
                                         "NtQuerySystemInformation"
                                         );

    if (!NtQuerySystemInformation)
	{
        return;
	}

    // get number of processors in the system
    status = NtQuerySystemInformation(SystemBasicInformation,
		                              &SysBaseInfo,sizeof(SysBaseInfo),NULL);

    if (status != NO_ERROR)
	{
        return;
	}

	 status = NtQuerySystemInformation(SystemTimeInformation,
		                               &SysTimeInfo,sizeof(SysTimeInfo),0);
     if (status!=NO_ERROR)
	 {
          return;
	 }

     // get new CPU's idle time
     status = NtQuerySystemInformation(SystemPerformanceInformation,
		                               &SysPerfInfo,sizeof(SysPerfInfo),NULL);

     if (status != NO_ERROR)
	 {
          return;
	 }

     // if it's a first call - skip it
     if (m_liOldIdleTime.QuadPart != 0)
     {
         // CurrentValue = NewValue - OldValue
         dbIdleTime = Li2Double(SysPerfInfo.liIdleTime) - Li2Double(m_liOldIdleTime);
         dbSystemTime = Li2Double(SysTimeInfo.liKeSystemTime) - Li2Double(m_liOldSystemTime);

          // CurrentCpuIdle = IdleTime / SystemTime
          dbIdleTime = dbIdleTime / dbSystemTime;

          // CurrentCpuUsage% = 100 - (CurrentCpuIdle * 100) / NumberOfProcessors
          dbIdleTime = 100.0 - dbIdleTime * 100.0 / (double)SysBaseInfo.bKeNumberProcessors + 0.5;

          m_fNewUsges = (UINT)dbIdleTime;
     }

     // store new CPU's idle and system time
     m_liOldIdleTime = SysPerfInfo.liIdleTime;
     m_liOldSystemTime = SysTimeInfo.liKeSystemTime;
}

void CCpuUseDlg::OnGetBtn() 
{

}

void CCpuUseDlg::DrawCpuUsges()
{
   	CDC memDC;
	CString strLable;
	CBitmap memBitmap;
	CBitmap* pOldBmp = NULL;	
	CString strUsges;
	CPen BackFreePen;
	CPen BackUsedPen;
	CPen *pOldPen    = NULL;
	CPen *pOldMemPen = NULL;
	CRect rectClient;

	CPaintDC dc(this);

	GetClientRect(&rectClient);
	m_iGridHeight = rectClient.Height() / m_iGridCount;

	//draw cpu free usges
	BackFreePen.CreatePen(PS_SOLID, m_iGridHeight - 2, m_FreeColor);

	memDC.CreateCompatibleDC(&dc);
	pOldMemPen = memDC.SelectObject(&BackFreePen);
	memBitmap.CreateCompatibleBitmap(&dc, rectClient.right, rectClient.bottom);
	pOldBmp = memDC.SelectObject(&memBitmap);

	memDC.FillSolidRect(rectClient, m_BackColor);

	for(int i = 0; i < 50 - (int)(m_fNewUsges / 2); i ++)   
	{
		memDC.MoveTo(rectClient.left + 12,  rectClient.top + i * m_iGridHeight + 12);
		memDC.LineTo(rectClient.right - 12, rectClient.top + i * m_iGridHeight + 12);
	}

	//draw cpu used usges
	BackUsedPen.CreatePen(PS_SOLID, m_iGridHeight - 2, m_UsedColor);
	memDC.SelectObject(&BackUsedPen);

	for(int j = 0; j < (int)(m_fNewUsges / 2); j ++)	   //fill used percent
	{
		memDC.MoveTo(rectClient.left + 12,  rectClient.bottom - j * m_iGridHeight - 12);
		memDC.LineTo(rectClient.right - 12, rectClient.bottom - j * m_iGridHeight - 12);
	}

	strLable = _T("cpu");
	memDC.SetBkMode(TRANSPARENT);
	memDC.SetTextAlign(TA_LEFT | TA_CENTER);
	memDC.SetTextColor(m_LableColor);
	memDC.TextOut(rectClient.left + 40, rectClient.top + 30, strLable);

	strUsges.Format("%d", (int)m_fNewUsges);
	strUsges += "%";
	memDC.SetTextColor(m_ForeFontColor);
	memDC.TextOut(rectClient.left + rectClient.Width() / 2 - 10, rectClient.bottom - 60, strUsges);

	dc.BitBlt(rectClient.left, rectClient.top, rectClient.right, rectClient.bottom, &memDC, 0, 0, SRCCOPY);

	memDC.SelectObject(pOldBmp);
	memDC.SelectObject(pOldMemPen);
	memDC.DeleteDC();
	memBitmap.DeleteObject();
}

void CCpuUseDlg::OnTimer(UINT nIDEvent) 
{
   	GetCpuUsgesNt();
	Invalidate();
	CDialog::OnTimer(nIDEvent);
}
BOOL CCpuUseDlg::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}