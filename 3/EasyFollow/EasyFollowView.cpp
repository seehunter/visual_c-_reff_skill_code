// EasyFollowView.cpp : implementation of the CEasyFollowView class
//

#include "stdafx.h"
#include "EasyFollow.h"

#include "EasyFollowDoc.h"
#include "EasyFollowView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEasyFollowView

IMPLEMENT_DYNCREATE(CEasyFollowView, CView)

BEGIN_MESSAGE_MAP(CEasyFollowView, CView)
	//{{AFX_MSG_MAP(CEasyFollowView)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEasyFollowView construction/destruction

CEasyFollowView::CEasyFollowView()
{
	// TODO: add construction code here

}

CEasyFollowView::~CEasyFollowView()
{
}

BOOL CEasyFollowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEasyFollowView drawing

void CEasyFollowView::OnDraw(CDC* pDC)
{
	CEasyFollowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CString strTmp;
	strTmp.Format("X:%d,Y:%d",m_CurPoint.x,m_CurPoint.y);
	pDC->TextOut(m_CurPoint.x,m_CurPoint.y,strTmp);
}

/////////////////////////////////////////////////////////////////////////////
// CEasyFollowView printing

BOOL CEasyFollowView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEasyFollowView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEasyFollowView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEasyFollowView diagnostics

#ifdef _DEBUG
void CEasyFollowView::AssertValid() const
{
	CView::AssertValid();
}

void CEasyFollowView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEasyFollowDoc* CEasyFollowView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEasyFollowDoc)));
	return (CEasyFollowDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEasyFollowView message handlers

void CEasyFollowView::OnMouseMove(UINT nFlags, CPoint point) 
{
    CClientDC dc(this);
	CString strTmp = "";
	m_CurPoint.x = point.x;
	m_CurPoint.y = point.y;
	strTmp.Format("X:%d,Y:%d",point.x,point.y);
	dc.TextOut(point.x,point.y,strTmp);
	Invalidate(TRUE);
	CView::OnMouseMove(nFlags, point);
}

