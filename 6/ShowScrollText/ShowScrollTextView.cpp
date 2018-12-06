// ShowScrollTextView.cpp : implementation of the CShowScrollTextView class
//

#include "stdafx.h"
#include "ShowScrollText.h"

#include "ShowScrollTextDoc.h"
#include "ShowScrollTextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowScrollTextView

IMPLEMENT_DYNCREATE(CShowScrollTextView, CView)

BEGIN_MESSAGE_MAP(CShowScrollTextView, CView)
	//{{AFX_MSG_MAP(CShowScrollTextView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowScrollTextView construction/destruction

CShowScrollTextView::CShowScrollTextView()
{
	// TODO: add construction code here

}

CShowScrollTextView::~CShowScrollTextView()
{
}

BOOL CShowScrollTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShowScrollTextView drawing

void CShowScrollTextView::OnDraw(CDC* pDC)
{
	CShowScrollTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CShowScrollTextView printing

BOOL CShowScrollTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CShowScrollTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CShowScrollTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CShowScrollTextView diagnostics

#ifdef _DEBUG
void CShowScrollTextView::AssertValid() const
{
	CView::AssertValid();
}

void CShowScrollTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShowScrollTextDoc* CShowScrollTextView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShowScrollTextDoc)));
	return (CShowScrollTextDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowScrollTextView message handlers
