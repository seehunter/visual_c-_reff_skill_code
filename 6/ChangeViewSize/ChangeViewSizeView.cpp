// ChangeViewSizeView.cpp : implementation of the CChangeViewSizeView class
//

#include "stdafx.h"
#include "ChangeViewSize.h"

#include "ChangeViewSizeDoc.h"
#include "ChangeViewSizeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChangeViewSizeView

IMPLEMENT_DYNCREATE(CChangeViewSizeView, CView)

BEGIN_MESSAGE_MAP(CChangeViewSizeView, CView)
	//{{AFX_MSG_MAP(CChangeViewSizeView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangeViewSizeView construction/destruction

CChangeViewSizeView::CChangeViewSizeView()
{
	// TODO: add construction code here

}

CChangeViewSizeView::~CChangeViewSizeView()
{
}

BOOL CChangeViewSizeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CChangeViewSizeView drawing

void CChangeViewSizeView::OnDraw(CDC* pDC)
{
	CChangeViewSizeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CChangeViewSizeView printing

BOOL CChangeViewSizeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CChangeViewSizeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CChangeViewSizeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CChangeViewSizeView diagnostics

#ifdef _DEBUG
void CChangeViewSizeView::AssertValid() const
{
	CView::AssertValid();
}

void CChangeViewSizeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChangeViewSizeDoc* CChangeViewSizeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChangeViewSizeDoc)));
	return (CChangeViewSizeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChangeViewSizeView message handlers
