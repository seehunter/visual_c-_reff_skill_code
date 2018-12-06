// CircleTextView.cpp : implementation of the CCircleTextView class
//

#include "stdafx.h"
#include "CircleText.h"

#include "CircleTextDoc.h"
#include "CircleTextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCircleTextView

IMPLEMENT_DYNCREATE(CCircleTextView, CView)

BEGIN_MESSAGE_MAP(CCircleTextView, CView)
	//{{AFX_MSG_MAP(CCircleTextView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCircleTextView construction/destruction

CCircleTextView::CCircleTextView()
{
	// TODO: add construction code here

}

CCircleTextView::~CCircleTextView()
{
}

BOOL CCircleTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCircleTextView drawing

void CCircleTextView::OnDraw(CDC* pDC)
{
	CCircleTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CFont rotateFont[30];

	for ( int i =0; i< 30; i++)
	{
		rotateFont[i].CreateFont ( 27, 0, i*120, 0,400, FALSE,FALSE,0,0,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH|FF_ROMAN, "Arial");
		
		CFont* pOldFont = (CFont *)pDC->SelectObject ( & rotateFont[i] );

		pDC->TextOut ( 180, 180, "旋转字体实例");

		pDC->SelectObject ( pOldFont );
	}
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CCircleTextView printing

BOOL CCircleTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCircleTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCircleTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCircleTextView diagnostics

#ifdef _DEBUG
void CCircleTextView::AssertValid() const
{
	CView::AssertValid();
}

void CCircleTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCircleTextDoc* CCircleTextView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCircleTextDoc)));
	return (CCircleTextDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCircleTextView message handlers

void CCircleTextView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	m_Angle = 10;
	m_Font.CreateFont(18,
		0,
		10,
		0,
		FW_BLACK,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		"宋体");

}
