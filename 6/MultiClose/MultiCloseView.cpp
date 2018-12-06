// MultiCloseView.cpp : implementation of the CMultiCloseView class
//

#include "stdafx.h"
#include "MultiClose.h"

#include "MultiCloseDoc.h"
#include "MultiCloseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiCloseView

IMPLEMENT_DYNCREATE(CMultiCloseView, CView)

BEGIN_MESSAGE_MAP(CMultiCloseView, CView)
	//{{AFX_MSG_MAP(CMultiCloseView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiCloseView construction/destruction

CMultiCloseView::CMultiCloseView()
{
	// TODO: add construction code here

}

CMultiCloseView::~CMultiCloseView()
{
}

BOOL CMultiCloseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMultiCloseView drawing

void CMultiCloseView::OnDraw(CDC* pDC)
{
	CMultiCloseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMultiCloseView printing

BOOL CMultiCloseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMultiCloseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMultiCloseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMultiCloseView diagnostics

#ifdef _DEBUG
void CMultiCloseView::AssertValid() const
{
	CView::AssertValid();
}

void CMultiCloseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMultiCloseDoc* CMultiCloseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiCloseDoc)));
	return (CMultiCloseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultiCloseView message handlers
