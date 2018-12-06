// LockRectView.cpp : implementation of the CLockRectView class
//

#include "stdafx.h"
#include "LockRect.h"

#include "LockRectDoc.h"
#include "LockRectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLockRectView

IMPLEMENT_DYNCREATE(CLockRectView, CView)

BEGIN_MESSAGE_MAP(CLockRectView, CView)
	//{{AFX_MSG_MAP(CLockRectView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLockRectView construction/destruction

CLockRectView::CLockRectView()
{
	// TODO: add construction code here

}

CLockRectView::~CLockRectView()
{
}

BOOL CLockRectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLockRectView drawing

void CLockRectView::OnDraw(CDC* pDC)
{
	CLockRectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLockRectView printing

BOOL CLockRectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLockRectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLockRectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLockRectView diagnostics

#ifdef _DEBUG
void CLockRectView::AssertValid() const
{
	CView::AssertValid();
}

void CLockRectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLockRectDoc* CLockRectView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLockRectDoc)));
	return (CLockRectDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLockRectView message handlers

void CLockRectView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
    RECT Rect;
	BOOL bLock;
	Rect.left=10;//设置锁定区域大小；
	Rect.top=10;
	Rect.right=200;
	Rect.bottom=200;
	bLock=ClipCursor(&Rect); // 限制鼠标移动区域
	if (bLock)
		MessageBox("鼠标固定在指定区域!");

}
