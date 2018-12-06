// FontDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Font.h"
#include "FontDlg.h"

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
// CFontDlg dialog

CFontDlg::CFontDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFontDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFontDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFontDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFontDlg)
	DDX_Control(pDX, IDC_BROWE_FONT_ED, m_BrowerCtrl);
	DDX_Control(pDX, IDC_FONT_NO_LIST, m_FontNoList);
	DDX_Control(pDX, IDC_FONT_STYLE_LIST, m_FontStyleList);
	DDX_Control(pDX, IDC_WEST_COMBOX, m_WestCtrl);
	DDX_Control(pDX, IDC_CHINA_COMBOX, m_ChinaCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFontDlg, CDialog)
	//{{AFX_MSG_MAP(CFontDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_CHINA_COMBOX, OnSelchangeChinaCombox)
	ON_CBN_SELCHANGE(IDC_WEST_COMBOX, OnSelchangeWestCombox)
	ON_LBN_SELCHANGE(IDC_FONT_STYLE_LIST, OnSelchangeFontStyleList)
	ON_LBN_SELCHANGE(IDC_FONT_NO_LIST, OnSelchangeFontNoList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontDlg message handlers

BOOL CFontDlg::OnInitDialog()
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
	FillFont();
	FillFontStyle();
	FillFontNo();
	FillBrowerED();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFontDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFontDlg::OnPaint() 
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
HCURSOR CFontDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/************************************************************************/
/* 回调函数的实现
/************************************************************************/
int CALLBACK MyEnumFontProc(ENUMLOGFONTEX* lpelf,NEWTEXTMETRICEX* lpntm,DWORD nFontType,long lParam) 
{ 
     CFontDlg* pWnd=(CFontDlg*) lParam; 
     if(pWnd) 
     { 
		 if((lpelf->elfLogFont.lfFaceName[1]>='a' && lpelf->elfLogFont.lfFaceName[1] <='z')||
			 (lpelf->elfLogFont.lfFaceName[1]>='A'&&lpelf->elfLogFont.lfFaceName[1]<='Z'))
               pWnd->m_WestCtrl.AddString(lpelf->elfLogFont.lfFaceName);
		 else
            pWnd->m_ChinaCtrl.AddString(lpelf->elfLogFont.lfFaceName);
         return 1; 
     } 
     return 0; 
} 
/************************************************************************/
/* 填充字体类型
/************************************************************************/ 
void CFontDlg::FillFont()
{
	 int iCurCount; 
     CString strCurFont; 
     CString strPrevFont=""; 
     LOGFONT lf; 
     lf.lfCharSet=DEFAULT_CHARSET; 
     lf.lfFaceName[0]=NULL; 
     lf.lfPitchAndFamily=0; 
     m_ChinaCtrl.ResetContent(); 
     CClientDC dc(this); 
     ::EnumFontFamiliesEx((HDC) dc,&lf,(FONTENUMPROC) MyEnumFontProc,(LPARAM) this,0); 
     for (iCurCount=m_ChinaCtrl.GetCount();iCurCount > 0;iCurCount--) 
     { 
         m_ChinaCtrl.GetLBText((iCurCount-1),strCurFont); 
         if (strCurFont==strPrevFont) 
         { 
              m_ChinaCtrl.DeleteString((iCurCount-1)); 
         } 
         else 
         { 
              strPrevFont=strCurFont; 
         } 
     } 
	 for (iCurCount=m_WestCtrl.GetCount();iCurCount > 0;iCurCount--) 
     { 
         m_WestCtrl.GetLBText((iCurCount-1),strCurFont); 
         if (strCurFont==strPrevFont) 
         { 
              m_WestCtrl.DeleteString((iCurCount-1)); 
         } 
         else 
         { 
              strPrevFont=strCurFont; 
         } 
     }
	 CString strTmp("");
	 for(int i=0; i<m_ChinaCtrl.GetCount(); i++)
	 {
	    m_ChinaCtrl.GetLBText(i,strTmp);
		if(strTmp == "宋体")
		{
			m_ChinaCtrl.SetCurSel(i);
		}
	 }
	 for(i=0; i<m_WestCtrl.GetCount(); i++)
	 {
	    m_WestCtrl.GetLBText(i,strTmp);
		if(strTmp == "Times New Roman")
		{
			m_WestCtrl.SetCurSel(i);
		}
	 }
	 m_strFontName = "宋体";//初始化
}
/************************************************************************/
/* fill font style
/************************************************************************/
void CFontDlg::FillFontStyle()
{
   m_FontStyleList.AddString("常规");
   m_FontStyleList.AddString("倾斜");
   m_FontStyleList.AddString("加粗");
   m_FontStyleList.AddString("加粗 倾斜");
   SetDlgItemText(IDC_FONT_STYLE_ED,"常规");
   m_strFontStyle = "常规";
   m_nWeight = FW_NORMAL;

}
/************************************************************************/
/* fill font No
/************************************************************************/
void CFontDlg::FillFontNo()
{
	char   *strFontSize[]   =     
	{
		"初号","小初","一号","小一","二号","小二","三号","小三",   
	    "四号","小四","五号","小五","六号","小六","七号","八号","5",   
	    "5.5","6.5","7.5","8","9","10","10.5","11","12","14","16","18",   
	     "20","22","24","26","28","36","48","72"};   
	int   nFontSizes[]  =   
	{
	-56,-48,-35,-32,-29,-24,-21,-20,   
	-19,-16,-14,-12,-10,-9,-7,-6,-6,   
	-7,-9,-10,-11,-12,-13,-14,-15,-16,-19,-21,-24,   
	-27,-29,-32,-35,-37,-48,-64,-96}; 
	int n = sizeof(strFontSize)/sizeof(*strFontSize);
    CString strTmp = "";
    for(int i=0; i<n; i++)
	{
       m_FontNoList.AddString(strFontSize[i]);
	   m_MapStrToOb.SetAt(strFontSize[i],(CObject*)nFontSizes[i]);
	}
    SetDlgItemText(IDC_FONT_NO_ED,"小四");
	m_strFontNo = "小四";
	m_nHeight = -16;
}
/************************************************************************/
/* 填充预览
/************************************************************************/
void CFontDlg::FillBrowerED()
{
	SetDlgItemText(IDC_BROWE_FONT_ED,"飞扬卓越ABcdE");
}
/************************************************************************/
/* 设置字体
/************************************************************************/
void CFontDlg::SetMyFont()
{
	m_Font.Detach();
	m_Font.CreateFont(m_nHeight,
		0,0,0,m_nWeight,
		m_bItalic,
		0,
		0,
		DEFAULT_CHARSET,
		OUT_CHARACTER_PRECIS,
		CLIP_CHARACTER_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH|FF_DONTCARE,
		m_strFontName); 
	m_BrowerCtrl.SetFont(&m_Font); 	
}
/************************************************************************/
/* 
/************************************************************************/
void CFontDlg::OnSelchangeChinaCombox() 
{
   m_ChinaCtrl.GetLBText(m_ChinaCtrl.GetCurSel(),m_strFontName);
   SetMyFont();
}
/************************************************************************/
/* 
/************************************************************************/
void CFontDlg::OnSelchangeWestCombox() 
{
   m_WestCtrl.GetLBText(m_WestCtrl.GetCurSel(),m_strFontName);
   SetMyFont();
}
/************************************************************************/
/* 
/************************************************************************/
void CFontDlg::OnSelchangeFontStyleList() 
{
    m_FontStyleList.GetText(m_FontStyleList.GetCurSel(),m_strFontStyle);
	SetDlgItemText(IDC_FONT_STYLE_ED,m_strFontStyle);
	if(m_strFontStyle == "常规")
	{
		m_nWeight = FW_NORMAL;
		m_bItalic = 0;
	}
	else if(m_strFontStyle == "加粗")
	{
		m_nWeight = FW_BOLD;
		m_bItalic = 0;
	}
	else if(m_strFontStyle == "倾斜")
	{
		m_bItalic = 1;
		m_nWeight = FW_NORMAL;
	}
	else if(m_strFontStyle == "加粗 倾斜")
	{
		m_nWeight = FW_BOLD;
		m_bItalic = 1;
	}
	SetMyFont();
}

void CFontDlg::OnSelchangeFontNoList() 
{
    m_FontNoList.GetText(m_FontNoList.GetCurSel(),m_strFontNo);
	SetDlgItemText(IDC_FONT_NO_ED,m_strFontNo);
    m_MapStrToOb.Lookup(m_strFontNo,(CObject*&)m_nHeight);
	SetMyFont();
	
}
