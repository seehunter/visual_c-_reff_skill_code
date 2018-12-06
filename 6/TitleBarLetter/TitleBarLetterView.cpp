// TitleBarLetterView.cpp : implementation of the CTitleBarLetterView class
//

#include "stdafx.h"
#include "TitleBarLetter.h"

#include "TitleBarLetterDoc.h"
#include "TitleBarLetterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTitleBarLetterView

IMPLEMENT_DYNCREATE(CTitleBarLetterView, CView)

BEGIN_MESSAGE_MAP(CTitleBarLetterView, CView)
	//{{AFX_MSG_MAP(CTitleBarLetterView)
	ON_COMMAND(ID_SET_TITLE_LETTER, OnSetTitleLetter)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTitleBarLetterView construction/destruction

CTitleBarLetterView::CTitleBarLetterView()
{
	// TODO: add construction code here

}

CTitleBarLetterView::~CTitleBarLetterView()
{
}

BOOL CTitleBarLetterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTitleBarLetterView drawing

void CTitleBarLetterView::OnDraw(CDC* pDC)
{
	CTitleBarLetterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTitleBarLetterView printing

BOOL CTitleBarLetterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTitleBarLetterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTitleBarLetterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTitleBarLetterView diagnostics

#ifdef _DEBUG
void CTitleBarLetterView::AssertValid() const
{
	CView::AssertValid();
}

void CTitleBarLetterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTitleBarLetterDoc* CTitleBarLetterView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTitleBarLetterDoc)));
	return (CTitleBarLetterDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTitleBarLetterView message handlers
void CTitleBarLetterView::OnSetTitleLetter() 
{
	AfxGetMainWnd()->SetWindowText("自定义标题");
}
