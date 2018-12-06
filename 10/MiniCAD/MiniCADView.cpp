// MiniCADView.cpp : implementation of the CMiniCADView class
//

#include "stdafx.h"
#include "MiniCAD.h"

#include "MiniCADDoc.h"
#include "MiniCADView.h"
#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMiniCADView

IMPLEMENT_DYNCREATE(CMiniCADView, CView)

BEGIN_MESSAGE_MAP(CMiniCADView, CView)
	//{{AFX_MSG_MAP(CMiniCADView)
	ON_COMMAND(ID_POINT_BTN, OnPointBtn)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_LINE_BTN, OnLineBtn)
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_RECTANGLE_BTN, OnRectangleBtn)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_ARC_BTN, OnArcBtn)
	ON_COMMAND(ID_ELLIPSE_BTN, OnEllipseBtn)
	ON_COMMAND(ID_CIRCLE_BTN, OnCircleBtn)
	ON_COMMAND(ID_FILLRECT_BTN, OnFillrectBtn)
	ON_COMMAND(ID_POLYGON_BTN, OnPolygonBtn)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMiniCADView construction/destruction

CMiniCADView::CMiniCADView()
{
   	m_bDrawPoint = FALSE;// «∑Òª≠µ„
	m_bDrawRectangle = FALSE;// «∑Òª≠æÿ–Œ
	m_bDrawCircle = FALSE;// «∑Òª≠‘≤
	m_bDrawArc = FALSE;// «∑Òª≠∫¸
	m_bDrawPoly = FALSE;// «∑Òª≠’€œﬂ
	m_bDrawBezier = FALSE;//ª≠bizer
	m_bDrawLine = FALSE;//ª≠œﬂ
	m_bDrawEllipse = FALSE;//ª≠Õ÷‘≤
	m_bDrawPolyGon = FALSE;//ª≠∂‡±ﬂ–Œ

	m_bStartDrawLine = FALSE;
	m_bStartDrawRectangle = FALSE;
	m_bStartDrawArc = FALSE;
	m_bStartDrawEllipse = FALSE;
	m_nClickTime = 0;
}

CMiniCADView::~CMiniCADView()
{
}

BOOL CMiniCADView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMiniCADView drawing

void CMiniCADView::OnDraw(CDC* pDC)
{
	CMiniCADDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMiniCADView printing

BOOL CMiniCADView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMiniCADView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMiniCADView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMiniCADView diagnostics

#ifdef _DEBUG
void CMiniCADView::AssertValid() const
{
	CView::AssertValid();
}

void CMiniCADView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMiniCADDoc* CMiniCADView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMiniCADDoc)));
	return (CMiniCADDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMiniCADView message handlers

void CMiniCADView::OnPointBtn() 
{
    m_bDrawPoint = TRUE;// «∑Òª≠µ„
	m_bDrawRectangle = FALSE;// «∑Òª≠æÿ–Œ
	m_bDrawCircle = FALSE;// «∑Òª≠‘≤
	m_bDrawArc = FALSE;// «∑Òª≠∫¸
	m_bDrawPoly = FALSE;// «∑Òª≠’€œﬂ
	m_bDrawBezier = FALSE;//ª≠bizer
	m_bDrawLine = FALSE;//ª≠œﬂ
	m_bDrawEllipse = FALSE;//ª≠Õ÷‘≤
	m_bDrawPolyGon = FALSE;//ª≠∂‡±ﬂ–Œ

	
	m_bStartDrawLine = FALSE;
	m_bStartDrawRectangle = FALSE;
	m_bStartDrawArc = FALSE;
	m_bStartDrawEllipse = FALSE;
	
}


void CMiniCADView::OnLButtonDown(UINT nFlags, CPoint point) 
{
   	m_LeftMousePoint = point;
	CClientDC dc(this);
	if(m_bDrawPoint)
		dc.SetPixel(m_LeftMousePoint,RGB(255,0,0));   
	else if(m_bDrawLine)
	{
		m_bStartDrawLine = TRUE;
		m_PrePointLine = point;
	}
	else if(m_bDrawRectangle)
	{ 
		m_RecFirstPoint = point;
	}
	else if(m_bDrawArc)
	{   
		m_nClickTime ++;
		if(m_nClickTime == 1)
		{
			m_ArcFirstPoint = point;
		}
		else if(m_nClickTime == 2)
		{
			m_ArcSecondPoint = point;
			dc.MoveTo(m_ArcFirstPoint);
			dc.LineTo(m_ArcSecondPoint);
		}
		else if(m_nClickTime == 3)
		{
			m_nArcThirdPoint = point; 
			DrawArc(&dc,m_ArcFirstPoint,m_ArcSecondPoint,m_nArcThirdPoint);
			m_nClickTime = 0;

		}
	}
	else if(m_bDrawEllipse)
	{
		m_EllipseFirstPoint = point;
		m_bStartDrawEllipse = TRUE;
	}
	else if(m_bDrawCircle)
	{
		m_FirstCirCirlePoint = point;
	}
	CView::OnLButtonDown(nFlags, point);
}

void CMiniCADView::OnLineBtn() 
{
	m_bDrawPoint = FALSE;// «∑Òª≠µ„
	m_bDrawRectangle = FALSE;// «∑Òª≠æÿ–Œ
	m_bDrawCircle = FALSE;// «∑Òª≠‘≤
	m_bDrawArc = FALSE;// «∑Òª≠∫¸
	m_bDrawPoly = FALSE;// «∑Òª≠’€œﬂ
	m_bDrawBezier = FALSE;//ª≠bizer
	m_bDrawLine = TRUE;//ª≠œﬂ
	m_bDrawEllipse = FALSE;//ª≠Õ÷‘≤
	m_bDrawPolyGon = FALSE;//ª≠∂‡±ﬂ–Œ
	
	
	m_bStartDrawLine = FALSE;
	m_bStartDrawRectangle = FALSE;
	m_bStartDrawArc = FALSE;
	m_bStartDrawEllipse = FALSE;
}
//
void CMiniCADView::OnMouseMove(UINT nFlags, CPoint point) 
{
    CClientDC dc(this);
	if(m_bStartDrawLine)
	{
		dc.MoveTo(m_PrePointLine);
		dc.LineTo(point);
		m_PrePointLine = point;
	}
	CView::OnMouseMove(nFlags, point);
}
//
void CMiniCADView::OnRButtonDown(UINT nFlags, CPoint point) 
{
    if(m_bStartDrawLine && m_bDrawLine)
	{
       if(IDOK == MessageBox("÷’÷πª≠œﬂ?","Ã· æ",MB_OKCANCEL))
	   {
		   m_bDrawLine = FALSE;
		   m_bStartDrawLine = FALSE;
	   }
	}
	CView::OnRButtonDown(nFlags, point);
}

void CMiniCADView::OnRectangleBtn() 
{
    m_bDrawPoint = FALSE;// «∑Òª≠µ„
	m_bDrawRectangle = TRUE;// «∑Òª≠æÿ–Œ
	m_bDrawCircle = FALSE;// «∑Òª≠‘≤
	m_bDrawArc = FALSE;// «∑Òª≠∫¸
	m_bDrawPoly = FALSE;// «∑Òª≠’€œﬂ
	m_bDrawBezier = FALSE;//ª≠bizer
	m_bDrawLine = FALSE;//ª≠œﬂ
	m_bDrawEllipse = FALSE;//ª≠Õ÷‘≤
	m_bDrawPolyGon = FALSE;//ª≠∂‡±ﬂ–Œ 	
		
    m_bStartDrawLine = FALSE;
	m_bStartDrawRectangle = FALSE;
	m_bStartDrawEllipse = FALSE;
}

void CMiniCADView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
    if(m_bDrawRectangle)
	{
		CRect rect(m_RecFirstPoint,point);
        dc.Rectangle(&rect);
	}
	else if(m_bStartDrawEllipse)
	{
		CRect rect(m_EllipseFirstPoint,point);
		dc.Ellipse(&rect);
		m_bStartDrawEllipse = FALSE;
	}
	else if(m_bDrawCircle)
	{
		int rad = sqrt(pow(point.x-m_FirstCirCirlePoint.x,2)+pow(point.y - m_FirstCirCirlePoint.y,2));
		CRect rect(point.x-rad,point.y-rad,point.x+rad,point.y+rad);
		dc.Ellipse(&rect);
	}
	CView::OnLButtonUp(nFlags, point);
}

void CMiniCADView::OnArcBtn() 
{
	m_bDrawPoint = FALSE;// «∑Òª≠µ„
	m_bDrawRectangle = FALSE;// «∑Òª≠æÿ–Œ
	m_bDrawCircle = FALSE;// «∑Òª≠‘≤
	m_bDrawArc = TRUE;// «∑Òª≠∫¸
	m_bDrawPoly = FALSE;// «∑Òª≠’€œﬂ
	m_bDrawBezier = FALSE;//ª≠bizer
	m_bDrawLine = FALSE;//ª≠œﬂ
	m_bDrawEllipse = FALSE;//ª≠Õ÷‘≤
	m_bDrawPolyGon = FALSE;//ª≠∂‡±ﬂ–Œ

	m_bStartDrawLine = FALSE;
	m_bStartDrawRectangle = FALSE;	
	m_bStartDrawArc = FALSE;
	m_bStartDrawEllipse = FALSE;
}
/************************************************************************/
/* 
/************************************************************************/

void CMiniCADView::DrawArc(CDC* pDC, POINT StartPoint, POINT MidPoint, POINT EndPoint)
{

	POINT OriginPoint;

	double originX;
	double originY;
	double k1;
	double k2;
	double mid1X;
	double mid1Y;
	double mid2X;
	double mid2Y;

	RECT rect;
	long Radius;
	long x1, y1, x2, y2;

	//…Ë÷√≤ªÃÓ≥‰◊¥Ã¨


	if(StartPoint.y == MidPoint.y)
		k1 = 1000000.0;
	else 
		k1 = (- (double)(StartPoint.x - MidPoint.x) / (double)(StartPoint.y - MidPoint.y));

	if(EndPoint.y == MidPoint.y)
		k2 = 1000000.0;
	else 
		k2 =  (- (double)(EndPoint.x - MidPoint.x) / (double)(EndPoint.y - MidPoint.y));

	mid1X = (double)(StartPoint.x + MidPoint.x) / 2.0;
	mid1Y = (double)(StartPoint.y + MidPoint.y) / 2.0;

	mid2X = (double)(EndPoint.x + MidPoint.x) / 2.0;
	mid2Y = (double)(EndPoint.y + MidPoint.y) / 2.0;

	if(k1 == k2)
		return;
	
	if(k1 == 1000000.0)
	{
		originX = mid1X;
		originY = k2 * (originX - mid2X) + mid2Y;
	}
	else
	if(k2 == 1000000.0)
	{
		originX = mid2X;
		originY = k1 * (originX - mid1X) + mid1Y;
	}
	else
	{
		originX = ((k2 * mid2X - k1 * mid1X) - (mid2Y - mid1Y)) / (k2 - k1);
		originY = k2 * (originX - mid2X) + mid2Y;
	}

	Radius = (long)sqrt(pow((double)(originX - StartPoint.x), 2) + pow((double)(originY - StartPoint.y), 2));

	OriginPoint.x = (long)originX;
	OriginPoint.y = (long)originY ;

	rect.left = OriginPoint.x - Radius;
	rect.top = OriginPoint.y - Radius;
	rect.right = OriginPoint.x + Radius;
	rect.bottom = OriginPoint.y + Radius;

    x1 = MidPoint.x - StartPoint.x;
	y1 = MidPoint.y - StartPoint.y;

	x2 = EndPoint.x - StartPoint.x;
	y2 = EndPoint.y - StartPoint.y;

    if(x1*y2 - x2*y1 < 0)
		pDC->Arc(&rect, StartPoint, EndPoint);
	else
		pDC->Arc(&rect, EndPoint, StartPoint);

}

void CMiniCADView::OnEllipseBtn() 
{
  	m_bDrawPoint = FALSE;// «∑Òª≠µ„
	m_bDrawRectangle = FALSE;// «∑Òª≠æÿ–Œ
	m_bDrawCircle = FALSE;// «∑Òª≠‘≤
	m_bDrawArc = FALSE;// «∑Òª≠∫¸
	m_bDrawPoly = FALSE;// «∑Òª≠’€œﬂ
	m_bDrawBezier = FALSE;//ª≠bizer
	m_bDrawLine = FALSE;//ª≠œﬂ
	m_bDrawEllipse = TRUE;//ª≠Õ÷‘≤
	m_bDrawPolyGon = FALSE;//ª≠∂‡±ﬂ–Œ
	m_bStartDrawLine = FALSE;
	m_bStartDrawRectangle = FALSE;	
	m_bStartDrawArc = FALSE;
}

void CMiniCADView::OnCircleBtn() 
{
   	m_bDrawPoint = FALSE;// «∑Òª≠µ„
	m_bDrawRectangle = FALSE;// «∑Òª≠æÿ–Œ
	m_bDrawCircle = TRUE;// «∑Òª≠‘≤
	m_bDrawArc = FALSE;// «∑Òª≠∫¸
	m_bDrawPoly = FALSE;// «∑Òª≠’€œﬂ
	m_bDrawBezier = FALSE;//ª≠bizer
	m_bDrawLine = FALSE;//ª≠œﬂ
	m_bDrawEllipse = FALSE;//ª≠Õ÷‘≤
	m_bDrawPolyGon = FALSE;//ª≠∂‡±ﬂ–Œ
	m_bStartDrawLine = FALSE;
	m_bStartDrawRectangle = FALSE;	
	m_bStartDrawArc = FALSE;
}

void CMiniCADView::OnFillrectBtn() 
{
   	
}

void CMiniCADView::OnPolygonBtn() 
{
   	
}
