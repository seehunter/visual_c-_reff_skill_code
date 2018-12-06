// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "SingleToolBar.h"

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
	ON_COMMAND(ID_SET_BTN_CUE, OnSetBtnCue)
	ON_COMMAND(ID_CLOSE_BTN_CUE, OnCloseBtnCue)
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
	
	/*if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}*/
	//////////////////////////////
	//
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE 
		| /*CBRS_ALIGN_LEFT（将工具栏设置在左边）*/ CBRS_ALIGN_BOTTOM/*（将工具栏设置在底部）*/
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1; // fail to create
	}
	//
	/////////////////////////////
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	/*m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);*/
	//////////////////////////////////////
	//将工具栏设置在左边
	/*m_wndToolBar.EnableDocking(CBRS_ALIGN_LEFT);
	EnableDocking(CBRS_ALIGN_LEFT);*/
	//将工具栏设置在底部
    m_wndToolBar.EnableDocking(CBRS_ALIGN_BOTTOM);
	EnableDocking(CBRS_ALIGN_BOTTOM);
    //
	//////////////////////////////////////
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
    ////////////////////////////////////
	//|||
	//cs.style=WS_OVERLAPPED|WS_CAPTION|FWS_ADDTOTITLE|WS_THICKFRAME;
	//
	/////////////////////////////////////
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
//设置工具栏按钮提示
void CMainFrame::OnSetBtnCue() 
{
	DWORD dwStyle=m_wndToolBar.GetBarStyle();//获得工具栏的风格设置
	dwStyle|=CBRS_TOOLTIPS;//设置工具栏的风格
	m_wndToolBar.SetBarStyle(dwStyle);//修改工具栏的风格设置
}
/////////////////////////////////////////////////////////////////////////////
//关闭工具栏按钮提示
void CMainFrame::OnCloseBtnCue() 
{
	DWORD dwStyle=m_wndToolBar.GetBarStyle();//获得工具栏的风格设置
	dwStyle&=~CBRS_TOOLTIPS;//设置工具栏的风格
	m_wndToolBar.SetBarStyle(dwStyle);//修改工具栏的风格设置
}
/////////////////////////////////////////////////////////////////////////////
//
