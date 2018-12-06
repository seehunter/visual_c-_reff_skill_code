// IconEddyView.cpp : implementation of the CIconEddyView class
//

#include "stdafx.h"
#include "IconEddy.h"

#include "IconEddyDoc.h"
#include "IconEddyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIconEddyView

IMPLEMENT_DYNCREATE(CIconEddyView, CView)

BEGIN_MESSAGE_MAP(CIconEddyView, CView)
	//{{AFX_MSG_MAP(CIconEddyView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIconEddyView construction/destruction

CIconEddyView::CIconEddyView()
{
	// TODO: add construction code here

}

CIconEddyView::~CIconEddyView()
{
}

BOOL CIconEddyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CIconEddyView drawing

void CIconEddyView::OnDraw(CDC* pDC)
{
	CIconEddyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CIconEddyView printing

BOOL CIconEddyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CIconEddyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CIconEddyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CIconEddyView diagnostics

#ifdef _DEBUG
void CIconEddyView::AssertValid() const
{
	CView::AssertValid();
}

void CIconEddyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIconEddyDoc* CIconEddyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIconEddyDoc)));
	return (CIconEddyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIconEddyView message handlers
