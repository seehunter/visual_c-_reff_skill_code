// CloseStatusBarView.cpp : implementation of the CCloseStatusBarView class
//

#include "stdafx.h"
#include "CloseStatusBar.h"

#include "CloseStatusBarDoc.h"
#include "CloseStatusBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCloseStatusBarView

IMPLEMENT_DYNCREATE(CCloseStatusBarView, CView)

BEGIN_MESSAGE_MAP(CCloseStatusBarView, CView)
	//{{AFX_MSG_MAP(CCloseStatusBarView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCloseStatusBarView construction/destruction

CCloseStatusBarView::CCloseStatusBarView()
{
	// TODO: add construction code here

}

CCloseStatusBarView::~CCloseStatusBarView()
{
}

BOOL CCloseStatusBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCloseStatusBarView drawing

void CCloseStatusBarView::OnDraw(CDC* pDC)
{
	CCloseStatusBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CCloseStatusBarView printing

BOOL CCloseStatusBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCloseStatusBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCloseStatusBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCloseStatusBarView diagnostics

#ifdef _DEBUG
void CCloseStatusBarView::AssertValid() const
{
	CView::AssertValid();
}

void CCloseStatusBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCloseStatusBarDoc* CCloseStatusBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCloseStatusBarDoc)));
	return (CCloseStatusBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCloseStatusBarView message handlers
