// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "SystemButton.h"

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
/////////////////////////////////////////////////////////////////////////////
//使最小化按钮无效
//DEL void CMainFrame::OnMinDisuseable() 
//DEL {
//DEL 	//获得窗口风格
//DEL 	LONG style = ::GetWindowLong(m_hWnd,GWL_STYLE);
//DEL 	//设置新的风格
//DEL 	style &=  ~(WS_MINIMIZEBOX);
//DEL 	::SetWindowLong(m_hWnd,GWL_STYLE,style);
//DEL 	//重画窗口边框
//DEL 	CRect rc;
//DEL 	GetWindowRect(&rc);
//DEL 	::SetWindowPos(m_hWnd,HWND_NOTOPMOST,rc.left,rc.top,rc.Width(),rc.Height(),SWP_DRAWFRAME);
//DEL }
/////////////////////////////////////////////////////////////////////////////
//使最大化按钮无效
//DEL void CMainFrame::OnMaxDisuseable() 
//DEL {
//DEL 	//获得窗口风格
//DEL 	LONG style = ::GetWindowLong(m_hWnd,GWL_STYLE);
//DEL 	//设置新的风格
//DEL 	style &=  ~(WS_MAXIMIZEBOX);
//DEL 	::SetWindowLong(m_hWnd,GWL_STYLE,style);
//DEL 	//重画窗口边框
//DEL 	CRect rc;
//DEL 	GetWindowRect(&rc);
//DEL 	::SetWindowPos(m_hWnd,HWND_NOTOPMOST,rc.left,rc.top,rc.Width(),rc.Height(),SWP_DRAWFRAME);
//DEL }
/////////////////////////////////////////////////////////////////////////////
//使关闭按钮无效
//DEL void CMainFrame::OnCloseDisuseable() 
//DEL {
//DEL 	//获得系统菜单
//DEL 	CMenu *pSysMenu=GetSystemMenu(FALSE);
//DEL 	//获得关闭按钮的ID
//DEL 	int nCount=pSysMenu->GetMenuItemCount();
//DEL 	UINT nID=pSysMenu->GetMenuItemID(nCount-1);
//DEL 	//使关闭按钮无效
//DEL 	pSysMenu->EnableMenuItem(nID,MF_DISABLED);
//DEL }
/////////////////////////////////////////////////////////////////////////////
//
