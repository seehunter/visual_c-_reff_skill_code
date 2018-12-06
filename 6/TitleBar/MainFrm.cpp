// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "TitleBar.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
    /////////////////////////////////////////////
	//
    //ModifyStyle(WS_SYSMENU,0);
    //
	////////////////////////////////////////////
	//
	/*CMenu* pMenu=GetSystemMenu(FALSE);
    pMenu->DeleteMenu(SC_MINIMIZE,MF_BYCOMMAND|MF_GRAYED);   
    pMenu->DeleteMenu(SC_MOVE,MF_BYCOMMAND|MF_GRAYED);   
    pMenu->DeleteMenu(SC_SIZE,MF_BYCOMMAND|MF_GRAYED);
	pMenu->DeleteMenu(SC_MAXIMIZE,MF_BYCOMMAND|MF_GRAYED);
	pMenu->DeleteMenu(SC_CLOSE,MF_BYCOMMAND|MF_GRAYED);
	pMenu->DeleteMenu(SC_RESTORE,MF_BYCOMMAND|MF_GRAYED);*/
/*	CMenu* pSysMenu=GetSystemMenu(FALSE);   
	if(pSysMenu!=NULL)   
	{   
		pSysMenu->EnableMenuItem(0,MF_GRAYED);   
	}*/
	/*NONCLIENTMETRICS   nm;
	SystemParametersInfo(SPI_GETNONCLIENTMETRICS,sizeof(nm),&nm,0);
//	SystemParametersInfo(SPI_SETNONCLIENTMETRICS,sizeof(nm),&nm,0);
   SystemParametersInfo(SPI_SETDOUBLECLKHEIGHT,sizeof(nm),&nm,100);*/
	//::SendMessage(this->m_hWnd,WM_SETICON,ICON_SMALL,(LPARAM)GetIcon(FALSE));
    //////////////////////////////////////////
	//
    /*LONG style=::GetWindowLong(m_hWnd,GWL_STYLE);
	style&=-(WS_MINIMIZEBOX);
	::SetWindowLong(m_hWnd,GWL_STYLE,style);
    CRect rc;
	GetWindowRect(&rc);
	::SetWindowPos(m_hWnd,HWND_NOTOPMOST,rc.left,rc.top,rc.Width(),rc.Height(),SWP_DRAWFRAME);*/
    //////////////////////////////////////////
	//
    /*LONG stylemax=::GetWindowLong(m_hWnd,GWL_STYLE);
	stylemax&=-(WS_MAXIMIZEBOX);
	::SetWindowLong(m_hWnd,GWL_STYLE,stylemax);
    CRect rcmax;
	GetWindowRect(&rcmax);
	::SetWindowPos(m_hWnd,HWND_NOTOPMOST,rcmax.left,rcmax.top,rcmax.Width(),rcmax.Height(),SWP_DRAWFRAME);*/
    //////////////////////////////////////////
	//
	/*CMenu* pSysMenu=GetSystemMenu(FALSE); 
    int nClosePos=pSysMenu->GetMenuItemCount();
	UINT pCloseID=pSysMenu->GetMenuItemID(nClosePos-1);
	pSysMenu->EnableMenuItem(pCloseID,MF_DISABLED);*/
    //////////////////////////////////////////
	//
	/*SystemParametersInfo(SPI_GETNONCLIENTMETRICS,sizeof(NM),@NM,0);   
    SystemParametersInfo(SPI_GETICONTITLELOGFONT,sizeof(hFont),@hFont,0);   
    hFont.lfFaceName:='Fixedsys';   
    NM.cbSize:=sizeof(nm);   
    NM.lfMenuFont:=hFont;   
    NM.lfMessageFont:=hFont;   
    SystemParametersInfo(SPI_SETNONCLIENTMETRICS,sizeof(NM),@NM,SPIF_UPDATEINIFILE);*/
   /* long style=GetWindowLong(m_hWnd,GWL_STYLE);
	style&=-WS_SYSMENU;
	SetWindowLong(m_hWnd,GWL_STYLE,style);*/
    
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
