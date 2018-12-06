// ViewView.cpp : implementation of the CViewView class
//

#include "stdafx.h"
#include "View.h"

#include "ViewDoc.h"
#include "ViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewView

IMPLEMENT_DYNCREATE(CViewView, CView)

BEGIN_MESSAGE_MAP(CViewView, CView)
	//{{AFX_MSG_MAP(CViewView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewView construction/destruction

CViewView::CViewView()
{
	// TODO: add construction code here

}

CViewView::~CViewView()
{
}

BOOL CViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CViewView drawing

void CViewView::OnDraw(CDC* pDC)
{
	CViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CViewView printing

BOOL CViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CViewView diagnostics

#ifdef _DEBUG
void CViewView::AssertValid() const
{
	CView::AssertValid();
}

void CViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CViewDoc* CViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CViewDoc)));
	return (CViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewView message handlers
