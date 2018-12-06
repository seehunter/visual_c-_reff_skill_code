// DynamicAddMenuView.cpp : implementation of the CDynamicAddMenuView class
//

#include "stdafx.h"
#include "DynamicAddMenu.h"

#include "DynamicAddMenuDoc.h"
#include "DynamicAddMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynamicAddMenuView

IMPLEMENT_DYNCREATE(CDynamicAddMenuView, CView)

BEGIN_MESSAGE_MAP(CDynamicAddMenuView, CView)
	//{{AFX_MSG_MAP(CDynamicAddMenuView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynamicAddMenuView construction/destruction

CDynamicAddMenuView::CDynamicAddMenuView()
{
	// TODO: add construction code here

}

CDynamicAddMenuView::~CDynamicAddMenuView()
{
}

BOOL CDynamicAddMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDynamicAddMenuView drawing

void CDynamicAddMenuView::OnDraw(CDC* pDC)
{
	CDynamicAddMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDynamicAddMenuView printing

BOOL CDynamicAddMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDynamicAddMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDynamicAddMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDynamicAddMenuView diagnostics

#ifdef _DEBUG
void CDynamicAddMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CDynamicAddMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDynamicAddMenuDoc* CDynamicAddMenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDynamicAddMenuDoc)));
	return (CDynamicAddMenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynamicAddMenuView message handlers
