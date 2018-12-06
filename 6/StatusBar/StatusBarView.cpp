// StatusBarView.cpp : implementation of the CStatusBarView class
//

#include "stdafx.h"
#include "StatusBar.h"

#include "StatusBarDoc.h"
#include "StatusBarView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatusBarView

IMPLEMENT_DYNCREATE(CStatusBarView, CView)

BEGIN_MESSAGE_MAP(CStatusBarView, CView)
	//{{AFX_MSG_MAP(CStatusBarView)
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatusBarView construction/destruction

CStatusBarView::CStatusBarView()
{
	// TODO: add construction code here
    
}

CStatusBarView::~CStatusBarView()
{
}

BOOL CStatusBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStatusBarView drawing

void CStatusBarView::OnDraw(CDC* pDC)
{
	CStatusBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CStatusBarView printing

BOOL CStatusBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStatusBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStatusBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStatusBarView diagnostics

#ifdef _DEBUG
void CStatusBarView::AssertValid() const
{
	CView::AssertValid();
}

void CStatusBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStatusBarDoc* CStatusBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStatusBarDoc)));
	return (CStatusBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStatusBarView message handlers
void CStatusBarView::OnMouseMove(UINT nFlags, CPoint point) 
{
	////////////////////////////////////////////////
	//在状态栏上显示鼠标位置
	CString strCurrentPos;
	strCurrentPos.Format("X:%d,Y:%d",point.x,point.y);
	CStatusBar*pStatusBar=(CStatusBar*)AfxGetMainWnd()->GetDescendantWindow(AFX_IDW_STATUS_BAR);
	pStatusBar->SetPaneInfo(1,6002,SBPS_STRETCH,65);
	pStatusBar->SetPaneText(1,strCurrentPos);
	//
	////////////////////////////////////////////////
	CView::OnMouseMove(nFlags, point);
}
//////////////////////////////////////////////////////////////////////////////
//
void CStatusBarView::OnTimer(UINT nIDEvent) 
{
	CView::OnTimer(nIDEvent);
}
