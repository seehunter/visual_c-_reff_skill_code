// MiniCAD2View.cpp : implementation of the CMiniCAD2View class
//

#include "stdafx.h"
#include "MiniCAD2.h"

#include "MiniCAD2Doc.h"
#include "MiniCAD2View.h"
#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMiniCAD2View

IMPLEMENT_DYNCREATE(CMiniCAD2View, CView)

BEGIN_MESSAGE_MAP(CMiniCAD2View, CView)
	//{{AFX_MSG_MAP(CMiniCAD2View)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_FILLRECT_BTN, OnFillrectBtn)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_FILLPOLY_BTN, OnFillpolyBtn)
	ON_COMMAND(ID_FILLELLIPSE_BTN, OnFillellipseBtn)
	ON_COMMAND(ID_FILLCIRCLE_BTN, OnFillcircleBtn)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMiniCAD2View construction/destruction

CMiniCAD2View::CMiniCAD2View()
{
	// TODO: add construction code here
    m_CurCommand = (COMMAND)0;
	m_bStartFillRect = FALSE;
	m_nClickTime = 0;
}

CMiniCAD2View::~CMiniCAD2View()
{
}

BOOL CMiniCAD2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMiniCAD2View drawing

void CMiniCAD2View::OnDraw(CDC* pDC)
{
	CMiniCAD2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CMiniCAD2View printing

BOOL CMiniCAD2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMiniCAD2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMiniCAD2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMiniCAD2View diagnostics

#ifdef _DEBUG
void CMiniCAD2View::AssertValid() const
{
	CView::AssertValid();
}

void CMiniCAD2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMiniCAD2Doc* CMiniCAD2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMiniCAD2Doc)));
	return (CMiniCAD2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMiniCAD2View message handlers

void CMiniCAD2View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	m_LeftDownFirstPos = point;
    switch(m_CurCommand)
	{
	case FILL_RECT:
		break;
	case FILL_POLY:
         SetPolyFillMode(dc.m_hDC,WINDING);
		CBrush brush(RGB(128,128,128));
		CBrush* oldBrush;
		oldBrush = dc.SelectObject(&brush);
		m_PolyPoint[m_nClickTime] = point;
		dc.Polygon(m_PolyPoint,m_nClickTime+1);
		m_nClickTime++;
		dc.SelectObject(oldBrush);
		break;
	}
	CView::OnLButtonDown(nFlags, point);
}

void CMiniCAD2View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	CBrush  brush(RGB(255,0,0));
	CBrush* oldBrush;
    m_LeftUpFirstPos = point;
	int rad;
	CRect rect(m_LeftDownFirstPos,m_LeftUpFirstPos);
	switch(m_CurCommand) 
	{
	case FILL_RECT:	
        dc.FillRect(&rect,&brush);
		break;
	case FILL_POLY:
		break;
	case FILL_ELLIPSE:
		oldBrush = dc.SelectObject(&brush);
		dc.Ellipse(&rect);
		dc.SelectObject(oldBrush);
		break;
	case FILL_CIRCLE:
		oldBrush = dc.SelectObject(&brush);
		rad = sqrt(pow(m_LeftDownFirstPos.x-m_LeftUpFirstPos.x,2)+pow(m_LeftDownFirstPos.y-m_LeftUpFirstPos.y,2));
		rect.left = m_LeftDownFirstPos.x - rad;
		rect.top = m_LeftDownFirstPos.y - rad;
		rect.right = m_LeftDownFirstPos.x + rad;
		rect.bottom = m_LeftDownFirstPos.y + rad;
		dc.Ellipse(&rect);
		dc.SelectObject(oldBrush);
		break;
		
	default:
		break;
	}
	CView::OnLButtonUp(nFlags, point);
}
/************************************************************************/
/* 
/************************************************************************/
void CMiniCAD2View::OnMouseMove(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	CBrush  brush(RGB(255,0,0));
	m_LeftMovePos = point;
	CRect rect(m_LeftDownFirstPos,m_LeftMovePos);
	switch(m_CurCommand)
	{
	case FILL_RECT:
      //  dc.FillRect(&rect,&brush);
		break;	
	}
//	Invalidate();
	CView::OnMouseMove(nFlags, point);
}
/************************************************************************/
/* 
/************************************************************************/
void CMiniCAD2View::OnFillrectBtn() 
{
   m_CurCommand = FILL_RECT;
}
/************************************************************************/
/* 
/************************************************************************/
void CMiniCAD2View::OnFillpolyBtn() 
{
  m_CurCommand = FILL_POLY;	
  m_nClickTime = 0;
}

void CMiniCAD2View::OnFillellipseBtn() 
{
  m_CurCommand = FILL_ELLIPSE;
}

void CMiniCAD2View::OnFillcircleBtn() 
{
	m_CurCommand = FILL_CIRCLE;
}
