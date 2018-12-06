// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "IconEddy.h"

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
	ON_WM_TIMER()
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
    ////////////////////////////////////
	//启动定时器
	SetTimer(0,300,NULL);
	//
	////////////////////////////////////
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
//加载新的图标
void CMainFrame::LoadNewIcon(UINT nIconID)
{
	HICON hIconNew=AfxGetApp()->LoadIcon(nIconID);
	HICON hIconOld=(HICON)GetClassLong(m_hWnd,GCL_HICON);
	ASSERT(hIconNew);
	ASSERT(hIconOld);
	if(hIconNew!=hIconOld)
	{
		DestroyIcon(hIconOld);
		SetClassLong(m_hWnd,GCL_HICON,(long)hIconNew);
		RedrawWindow(NULL,NULL,RDW_FRAME|RDW_ERASE|RDW_INVALIDATE);
	}
}
/////////////////////////////////////////////////////////////////////////////
//定时器
void CMainFrame::OnTimer(UINT nIDEvent) 
{
	CTime time=CTime::GetCurrentTime();//获得当前系统时间
	m_timeNow=time;
	CTimeSpan ts=m_timeNow-m_timeStart;
	if(ts.GetTotalSeconds()>=6)
		m_timeStart=m_timeNow;
	static int nIcons[]={IDI_ICON1,IDI_ICON2,IDI_ICON3,IDI_ICON4};
	static long lIndex=0;
	if(ts.GetTotalSeconds()<=3)
		LoadNewIcon(nIcons[lIndex++%4]);
	else
		LoadNewIcon(IDR_MAINFRAME);	
	
	CFrameWnd::OnTimer(nIDEvent);
}
/////////////////////////////////////////////////////////////////////////////
//
