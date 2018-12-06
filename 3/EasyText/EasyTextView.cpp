// EasyTextView.cpp : implementation of the CEasyTextView class
//

#include "stdafx.h"
#include "EasyText.h"

#include "EasyTextDoc.h"
#include "EasyTextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEasyTextView

IMPLEMENT_DYNCREATE(CEasyTextView, CView)

BEGIN_MESSAGE_MAP(CEasyTextView, CView)
	//{{AFX_MSG_MAP(CEasyTextView)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEasyTextView construction/destruction

CEasyTextView::CEasyTextView()
{
	// TODO: add construction code here
    m_strPre = "";
	m_prePoint.x = 0;
	m_prePoint.y = 0;
}

CEasyTextView::~CEasyTextView()
{
}

BOOL CEasyTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEasyTextView drawing

void CEasyTextView::OnDraw(CDC* pDC)
{
	CEasyTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CBrush bkBrush(RGB(0,0,255));
	CRect rt;
	GetClientRect(&rt);
	CBrush* oldBrush = pDC->SelectObject(&bkBrush); 
    pDC->FillRect(rt,&bkBrush);
	pDC->SelectObject(oldBrush);
	
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEasyTextView printing

BOOL CEasyTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEasyTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEasyTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEasyTextView diagnostics

#ifdef _DEBUG
void CEasyTextView::AssertValid() const
{
	CView::AssertValid();
}

void CEasyTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEasyTextDoc* CEasyTextView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEasyTextDoc)));
	return (CEasyTextDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEasyTextView message handlers

void CEasyTextView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{

	if(nChar != 13)
    {	
		CClientDC  dc(this);
		CBrush     bkbrush(RGB(255,255,255));
		CBrush     brush(RGB(0,0,255));
		CString strTemp = "";
		TEXTMETRIC TxtMetric;
		
		::GetTextMetrics(dc.m_hDC ,&TxtMetric);
		if(nChar != 8)
		{
			strTemp.Format("%c",nChar);
			m_strPre = m_strPre+strTemp;
			SetCaretPos(CPoint((TxtMetric.tmMaxCharWidth)*m_strPre.GetLength(),m_prePoint.y));			
			dc.TextOut(m_prePoint.x,m_prePoint.y,m_strPre);
		}
		else
		{
			POINT  pBottom;
			pBottom.x = m_prePoint.x + TxtMetric.tmMaxCharWidth*m_strPre.GetLength();
			pBottom.y = m_prePoint.y + TxtMetric.tmHeight;
			dc.FillRect(CRect(m_prePoint,pBottom),&brush);	
			m_strPre = m_strPre.Left(m_strPre.GetLength()-1);
			SetCaretPos(CPoint((TxtMetric.tmMaxCharWidth)*(m_strPre.GetLength()),m_prePoint.y));
			dc.TextOut(m_prePoint.x,m_prePoint.y,m_strPre);		
			pBottom.x = m_prePoint.x + TxtMetric.tmMaxCharWidth*m_strPre.GetLength();
			pBottom.y = m_prePoint.y + TxtMetric.tmHeight;
			DrawText(dc.m_hDC,m_strPre,m_strPre.GetLength(),CRect(m_prePoint,pBottom),0);
		}
	}
	else
	{
		m_prePoint.x = 0;
		m_prePoint.y += 20;
		m_strPre = "";
		SetCaretPos(m_prePoint);
	}
	CView::OnChar(nChar, nRepCnt, nFlags);

}

void CEasyTextView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
//	LoadCursor(theApp.m_hInstance,MAKEINTRESOURCE(IDI_ICON1))	;
//	HBITMAP hBitmap = ::LoadBitmap(theApp.m_hInstance,MAKEINTRESOURCE(IDB_BITMAP1));
	
//	CreateCaret(CBitmap::FromHandle(hBitmap));
//	ShowCaret();
}
