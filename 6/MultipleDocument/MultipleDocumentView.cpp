// MultipleDocumentView.cpp : implementation of the CMultipleDocumentView class
//

#include "stdafx.h"
#include "MultipleDocument.h"

#include "MultipleDocumentDoc.h"
#include "MultipleDocumentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultipleDocumentView

IMPLEMENT_DYNCREATE(CMultipleDocumentView, CView)

BEGIN_MESSAGE_MAP(CMultipleDocumentView, CView)
	//{{AFX_MSG_MAP(CMultipleDocumentView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultipleDocumentView construction/destruction

CMultipleDocumentView::CMultipleDocumentView()
{
	// TODO: add construction code here

}

CMultipleDocumentView::~CMultipleDocumentView()
{
}

BOOL CMultipleDocumentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMultipleDocumentView drawing

void CMultipleDocumentView::OnDraw(CDC* pDC)
{
	CMultipleDocumentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMultipleDocumentView printing

BOOL CMultipleDocumentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMultipleDocumentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMultipleDocumentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMultipleDocumentView diagnostics

#ifdef _DEBUG
void CMultipleDocumentView::AssertValid() const
{
	CView::AssertValid();
}

void CMultipleDocumentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMultipleDocumentDoc* CMultipleDocumentView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultipleDocumentDoc)));
	return (CMultipleDocumentDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultipleDocumentView message handlers
