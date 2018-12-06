// DrawButtonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DrawButton.h"
#include "DrawButtonDlg.h"

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
// CDrawButtonDlg dialog

CDrawButtonDlg::CDrawButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDrawButtonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDrawButtonDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrawButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDrawButtonDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDrawButtonDlg, CDialog)
	//{{AFX_MSG_MAP(CDrawButtonDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawButtonDlg message handlers

BOOL CDrawButtonDlg::OnInitDialog()
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
	
	int aiElements[3] = {COLOR_ACTIVEBORDER, //边界颜色
                     COLOR_ACTIVECAPTION, //标题颜色
                     COLOR_WINDOW}; //窗口背景颜色

    // array of RGB values 
	DWORD aColors[3]; 
	// Define the new colors. 
	aColors[0] = RGB(0x80, 0x00, 0x80);  // dark purple 
	aColors[1] = RGB(0x00, 0x80, 0x80);  // dark cyan 
	aColors[2] = RGB(0xC0, 0xC0, 0xC0);  // light gray 	
	// Set the window elements in aiElements to the colors 
	// specified in aColors. 
	
	SetSysColors(3, aiElements, aColors); 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDrawButtonDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDrawButtonDlg::OnPaint() 
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
HCURSOR CDrawButtonDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/************************************************************************/
/* 
/************************************************************************/
void CDrawButtonDlg::DrawMyButton()
{


	//显示一个按钮。
	//设置按钮背景颜色。
	CClientDC  dc(this);
	RECT rcText;         
	rcText.left = 30; 
	rcText.top = 30;   
	rcText.right = 120;
	rcText.bottom = 120;	
	HBRUSH hbrush = CreateSolidBrush(GetSysColor(COLOR_3DFACE));	//立体显示的元件的表面的颜色.
	FillRect(dc.m_hDC,&rcText,hbrush);
	DeleteObject(hbrush);
	
	//
	HPEN hLight = CreatePen(PS_SOLID,1,
		GetSysColor(COLOR_3DHIGHLIGHT));//立体元件高亮显示时的颜色
	HPEN hShdaow = CreatePen(PS_SOLID,1,
		GetSysColor(COLOR_3DDKSHADOW));//立体显示的元件的阴影的颜色
	
	//
	//移到指定位置.
	POINT ptLeftTop;
	ptLeftTop.x = 30;
	ptLeftTop.y = 30;
	MoveToEx(dc.m_hDC,ptLeftTop.x,ptLeftTop.y,NULL);
	
	//显示白线。
	HGDIOBJ hOldPen = SelectObject(dc.m_hDC,hLight);
	
	ptLeftTop.x = 30;
	ptLeftTop.y = 120;
	LineTo(dc.m_hDC,ptLeftTop.x,ptLeftTop.y);
	
	ptLeftTop.x = 30;
	ptLeftTop.y = 30;
	MoveToEx(dc.m_hDC,ptLeftTop.x,ptLeftTop.y,NULL);
	ptLeftTop.x = 120;
	ptLeftTop.y = 30;
	LineTo(dc.m_hDC,ptLeftTop.x,ptLeftTop.y);
	
	//显示黑色线。
	SelectObject(dc.m_hDC,hShdaow);
	ptLeftTop.x = 120;
	ptLeftTop.y = 120;
	LineTo(dc.m_hDC,ptLeftTop.x,ptLeftTop.y);
	
	ptLeftTop.x = 30;
	ptLeftTop.y = 120;
	LineTo(dc.m_hDC,ptLeftTop.x,ptLeftTop.y);
    	
	//
	SelectObject(dc.m_hDC,hOldPen);
	DeleteObject(hLight);
	DeleteObject(hShdaow);
	
	int nOldMode = SetBkMode(dc.m_hDC,TRANSPARENT);
	//输出文字。
	CString  strTxt = "按钮";
	DrawText(dc.m_hDC,strTxt,strTxt.GetLength(),&rcText,
		DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS); 
	
	SetBkMode(dc.m_hDC,nOldMode);
}

void CDrawButtonDlg::OnOK() 
{
	// TODO: Add extra validation here
	DrawMyButton();
	//CDialog::OnOK();
}
