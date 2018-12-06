// AppendSystemMenuView.cpp : implementation of the CAppendSystemMenuView class
//

#include "stdafx.h"
#include "AppendSystemMenu.h"

#include "AppendSystemMenuDoc.h"
#include "AppendSystemMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAppendSystemMenuView

IMPLEMENT_DYNCREATE(CAppendSystemMenuView, CView)

BEGIN_MESSAGE_MAP(CAppendSystemMenuView, CView)
	//{{AFX_MSG_MAP(CAppendSystemMenuView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAppendSystemMenuView construction/destruction

CAppendSystemMenuView::CAppendSystemMenuView()
{
	// TODO: add construction code here

}

CAppendSystemMenuView::~CAppendSystemMenuView()
{
}

BOOL CAppendSystemMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAppendSystemMenuView drawing

void CAppendSystemMenuView::OnDraw(CDC* pDC)
{
	CAppendSystemMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CAppendSystemMenuView printing

BOOL CAppendSystemMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAppendSystemMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAppendSystemMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAppendSystemMenuView diagnostics

#ifdef _DEBUG
void CAppendSystemMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CAppendSystemMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAppendSystemMenuDoc* CAppendSystemMenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAppendSystemMenuDoc)));
	return (CAppendSystemMenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAppendSystemMenuView message handlers
