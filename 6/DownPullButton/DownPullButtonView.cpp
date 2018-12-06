// DownPullButtonView.cpp : implementation of the CDownPullButtonView class
//

#include "stdafx.h"
#include "DownPullButton.h"

#include "DownPullButtonDoc.h"
#include "DownPullButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDownPullButtonView

IMPLEMENT_DYNCREATE(CDownPullButtonView, CView)

BEGIN_MESSAGE_MAP(CDownPullButtonView, CView)
	//{{AFX_MSG_MAP(CDownPullButtonView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDownPullButtonView construction/destruction

CDownPullButtonView::CDownPullButtonView()
{
	// TODO: add construction code here

}

CDownPullButtonView::~CDownPullButtonView()
{
}

BOOL CDownPullButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDownPullButtonView drawing

void CDownPullButtonView::OnDraw(CDC* pDC)
{
	CDownPullButtonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDownPullButtonView printing

BOOL CDownPullButtonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDownPullButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDownPullButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDownPullButtonView diagnostics

#ifdef _DEBUG
void CDownPullButtonView::AssertValid() const
{
	CView::AssertValid();
}

void CDownPullButtonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDownPullButtonDoc* CDownPullButtonView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDownPullButtonDoc)));
	return (CDownPullButtonDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDownPullButtonView message handlers
