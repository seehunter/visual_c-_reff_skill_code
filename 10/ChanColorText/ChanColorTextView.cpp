// ChanColorTextView.cpp : implementation of the CChanColorTextView class
//

#include "stdafx.h"
#include "ChanColorText.h"

#include "ChanColorTextDoc.h"
#include "ChanColorTextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChanColorTextView

IMPLEMENT_DYNCREATE(CChanColorTextView, CView)

BEGIN_MESSAGE_MAP(CChanColorTextView, CView)
	//{{AFX_MSG_MAP(CChanColorTextView)
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChanColorTextView construction/destruction

CChanColorTextView::CChanColorTextView()
{
	m_RColor = 0;
	m_GColor = 0;
	m_bColor = 0;
}

CChanColorTextView::~CChanColorTextView()
{
}

BOOL CChanColorTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CChanColorTextView drawing

void CChanColorTextView::OnDraw(CDC* pDC)
{
	CChanColorTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//------------------------------------------------------
	pDC->SetTextColor(m_TextColor);
	pDC->TextOut(100,100,"字体渐变文本演示");
	



}

/////////////////////////////////////////////////////////////////////////////
// CChanColorTextView printing

BOOL CChanColorTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CChanColorTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CChanColorTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CChanColorTextView diagnostics

#ifdef _DEBUG
void CChanColorTextView::AssertValid() const
{
	CView::AssertValid();
}

void CChanColorTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChanColorTextDoc* CChanColorTextView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChanColorTextDoc)));
	return (CChanColorTextDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChanColorTextView message handlers

void CChanColorTextView::OnTimer(UINT nIDEvent) 
{
	m_RColor++;
//	m_GColor++;
//	m_bColor++;
	if(m_RColor>255)
	{
		m_RColor=0;
	}
	if(m_GColor>255)
	{
		m_GColor = 0;
	}
	if(m_bColor>255)
	{
		m_GColor=0;
	}
  	m_TextColor = RGB(m_RColor,m_GColor,m_bColor);
	Invalidate();
	CView::OnTimer(nIDEvent);
}

void CChanColorTextView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
//	static CBrush brush(RGB(128,128,128));
 //   SetClassLong(this->m_hWnd,GCL_HBRBACKGROUND,(LONG)(HBRUSH)brush);

    SetTimer(1,100,NULL);	
}

BOOL CChanColorTextView::OnEraseBkgnd(CDC* pDC) 
{

	CView::OnEraseBkgnd(pDC);

	return TRUE;
}
