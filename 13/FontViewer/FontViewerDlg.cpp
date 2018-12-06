// FontViewerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FontViewer.h"
#include "FontViewerDlg.h"

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
// CFontViewerDlg dialog

CFontViewerDlg::CFontViewerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFontViewerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFontViewerDlg)
	m_strEngFont = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strFontName = "";
	m_strFontStyle = "";
	m_strFontNo = "";
	m_bItalic = 0;//
	m_bBold = 0;//
	m_nWeight = FW_NORMAL;
	m_strFontName = "";
	m_nFontNo = 30;
}

void CFontViewerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFontViewerDlg)
	DDX_Control(pDX, IDC_FONT_NO_LIST, m_FontNoList);
	DDX_Control(pDX, IDC_FONT_STYLE_LIST, m_FontStyleCtrl);
	DDX_Control(pDX, IDC_FONT_ENG_COMBOX, m_EngFontCtrl);
	DDX_Control(pDX, IDC_PREVIEW_ED, m_PreViewCtrl);
	DDX_Control(pDX, IDC_FONT_CHINA_COMBOX, m_ComBoxCtrl);
	DDX_CBString(pDX, IDC_FONT_ENG_COMBOX, m_strEngFont);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFontViewerDlg, CDialog)
	//{{AFX_MSG_MAP(CFontViewerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_FONT_CHINA_COMBOX, OnSelchangeFontChinaCombox)
	ON_CBN_SELCHANGE(IDC_FONT_ENG_COMBOX, OnSelchangeFontEngCombox)
	ON_LBN_SELCHANGE(IDC_FONT_STYLE_LIST, OnSelchangeFontStyleList)
	ON_LBN_SELCHANGE(IDC_FONT_NO_LIST, OnSelchangeFontNoList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontViewerDlg message handlers

BOOL CFontViewerDlg::OnInitDialog()
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
	
    InitFont();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFontViewerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFontViewerDlg::OnPaint() 
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
HCURSOR CFontViewerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/************************************************************************/
/* 回调函数的实现
/************************************************************************/
int CALLBACK MyEnumFontProc(ENUMLOGFONTEX* lpelf,NEWTEXTMETRICEX* lpntm,DWORD nFontType,long lParam)
{
	 CFontViewerDlg* pWnd=(CFontViewerDlg*) lParam; 
     if(pWnd) 
     { 
		 if((lpelf->elfLogFont.lfFaceName[1]<'z' && lpelf->elfLogFont.lfFaceName[1]>'a')||
              (lpelf->elfLogFont.lfFaceName[1]<'Z' && lpelf->elfLogFont.lfFaceName[1]>'A')
			 )
			 pWnd->m_EngFontCtrl.AddString(lpelf->elfLogFont.lfFaceName);
		 else
			 pWnd->m_ComBoxCtrl.AddString(lpelf->elfLogFont.lfFaceName);
         return 1; 
     } 
     return 0; 

}
/************************************************************************/
/* 
/************************************************************************/
void CFontViewerDlg::FillFontList(void) 
{ 
     int iCurCount; 
     CString strCurFont; 
     CString strPrevFont=""; 
     LOGFONT lf; 
     lf.lfCharSet=DEFAULT_CHARSET; 
     lf.lfFaceName[0]=NULL; 
     lf.lfPitchAndFamily=0; 
     m_ComBoxCtrl.ResetContent(); 
     CClientDC dc(this); 
     ::EnumFontFamiliesEx((HDC) dc,&lf,(FONTENUMPROC) MyEnumFontProc,(LPARAM) this,0); 	
     for (iCurCount=m_ComBoxCtrl.GetCount();iCurCount > 0;iCurCount--) 
     { 
         m_ComBoxCtrl.GetLBText((iCurCount-1),strCurFont);
         if (strCurFont==strPrevFont) 
         { 
             m_ComBoxCtrl.DeleteString((iCurCount-1)); 
         } 
         else 
         { 
              strPrevFont=strCurFont; 
         } 
     }
     for(iCurCount = 0; iCurCount < m_ComBoxCtrl.GetCount();iCurCount++)
	 {
	    m_ComBoxCtrl.GetLBText((iCurCount),strCurFont);
        if(strCurFont == "宋体")
		{
			m_ComBoxCtrl.SetCurSel(iCurCount);
		}
		m_strFontName = "宋体";
	 }

	  for (iCurCount=m_EngFontCtrl.GetCount();iCurCount > 0;iCurCount--) 
     { 
         m_EngFontCtrl.GetLBText((iCurCount-1),strCurFont);
         if (strCurFont==strPrevFont) 
         { 
             m_EngFontCtrl.DeleteString((iCurCount-1)); 
         } 
         else 
         { 
              strPrevFont=strCurFont; 
         } 
     }
     for(iCurCount = 0; iCurCount < m_EngFontCtrl.GetCount();iCurCount++)
	 {
	    m_EngFontCtrl.GetLBText((iCurCount),strCurFont);
        if(strCurFont == "Times New Roman")
		{
			m_EngFontCtrl.SetCurSel(iCurCount);
		}
	    m_strFontName = "Times New Roman";
	 }
} 
/************************************************************************/
/* 
/************************************************************************/
void CFontViewerDlg::SetMyFont(void) 
{ 

     if(m_strFontName.GetLength()>0) 
     { 
         m_FontStyle.Detach(); 
          m_FontStyle.CreateFont(m_nFontNo,
          			0,
					0,
					0,
					m_nWeight,
          			m_bItalic,
          			m_bBold,
          			0,
          			DEFAULT_CHARSET,
				OUT_CHARACTER_PRECIS,
				CLIP_CHARACTER_PRECIS,
				DEFAULT_QUALITY,
				DEFAULT_PITCH|FF_DONTCARE,
				m_strFontName); 
         m_PreViewCtrl.SetFont(&m_FontStyle); 
     } 
} 



void CFontViewerDlg::OnSelchangeFontChinaCombox() 
{
    UpdateData();
	m_ComBoxCtrl.GetLBText(m_ComBoxCtrl.GetCurSel(),m_strFontName);
	SetMyFont();
	
}

void CFontViewerDlg::OnSelchangeFontEngCombox() 
{
	UpdateData();
	m_EngFontCtrl.GetLBText(m_EngFontCtrl.GetCurSel(),m_strFontName);
	SetMyFont();
}
/************************************************************************/
/* 
/************************************************************************/
void CFontViewerDlg::InitFont()
{
	FillFontList();
	::SetDlgItemText(m_hWnd,IDC_PREVIEW_ED,"飞扬示例AbcdEf");
	m_FontStyleCtrl.AddString("常规");
	m_FontStyleCtrl.AddString("倾斜");
	m_FontStyleCtrl.AddString("加粗");
	m_FontStyleCtrl.AddString("加粗 倾斜");
    MapFontNo();	
}

void CFontViewerDlg::OnSelchangeFontStyleList() 
{
   m_FontStyleCtrl.GetText(m_FontStyleCtrl.GetCurSel(),m_strFontStyle);	
   SetDlgItemText(IDC_FONT_STYLE_ED,m_strFontStyle);
   if(m_strFontStyle == "常规")
   {
	   m_bItalic = 0;
	   m_bBold = 0;
   }
   else if(m_strFontStyle == "斜体")
   {
        m_bItalic = 1;
		m_bBold = 0;

   }
   else if(m_strFontStyle == "加粗")
   {
       m_nWeight = FW_BOLD;
	   m_bItalic = 0;
   }
   else if(m_strFontStyle == "加粗 倾斜")
   {
	   m_bItalic = 1;
       m_nWeight = FW_BOLD;
   }
   SetMyFont();
}
/************************************************************************/
/* 
/************************************************************************/
void CFontViewerDlg::MapFontNo()
{
  char   *strFontSize[]   =     
  {"初号","小初","一号","小一","二号","小二","三号","小三",   
   "四号","小四","五号","小五","六号","小六","七号","八号",
   "5",   "5.5",  "6.5","7.5",  "8",   "9",   "10",  "10.5",
   "11",  "12",   "14",  "16",  "18",  "20",  "22",  "24",
   "26",   "28",  "36",  "48",  "72"};   
 int   nFontSizes[]   =   
  {-56, -48,-35,-32,-29,-24,-21,-20,   
   -19, -16,-14,-12,-10,-9,  -7 , -6,  
   -6,  -7, -9,-10, -11,-12,-13, -14,
   -15, -16,-19,-21,-24,-27,-29, -32,
   -35, -37,-48, -64,-96
 }; 
  int nNum = sizeof(nFontSizes)/sizeof(int);
  for(int i=0; i<nNum; i++)
  {
      m_FontNoList.AddString(strFontSize[i]);
	  m_MapStrToInt.SetAt(strFontSize[i],(CObject*)nFontSizes[i]);
  }
}

void CFontViewerDlg::OnSelchangeFontNoList() 
{

   m_FontNoList.GetText(m_FontNoList.GetCurSel(),m_strFontNo);	
   SetDlgItemText(IDC_FONT_NO_ED,m_strFontNo);
   m_MapStrToInt.Lookup(m_strFontNo,(CObject*&)m_nFontNo);
   SetMyFont();
}
