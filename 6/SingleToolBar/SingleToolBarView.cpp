// SingleToolBarView.cpp : implementation of the CSingleToolBarView class
//

#include "stdafx.h"
#include "SingleToolBar.h"

#include "SingleToolBarDoc.h"
#include "SingleToolBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSingleToolBarView

IMPLEMENT_DYNCREATE(CSingleToolBarView, CView)

BEGIN_MESSAGE_MAP(CSingleToolBarView, CView)
	//{{AFX_MSG_MAP(CSingleToolBarView)
	ON_COMMAND(ID_SET_TITLE, OnSetTitle)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSingleToolBarView construction/destruction

CSingleToolBarView::CSingleToolBarView()
{
	// TODO: add construction code here

}

CSingleToolBarView::~CSingleToolBarView()
{
}

BOOL CSingleToolBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSingleToolBarView drawing

void CSingleToolBarView::OnDraw(CDC* pDC)
{
	CSingleToolBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSingleToolBarView printing

BOOL CSingleToolBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSingleToolBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSingleToolBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSingleToolBarView diagnostics

#ifdef _DEBUG
void CSingleToolBarView::AssertValid() const
{
	CView::AssertValid();
}

void CSingleToolBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSingleToolBarDoc* CSingleToolBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingleToolBarDoc)));
	return (CSingleToolBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSingleToolBarView message handlers
//设置工具栏的标题
void CSingleToolBarView::OnSetTitle() 
{
	CToolBar * pToolBar=(CToolBar *)AfxGetMainWnd()->GetDescendantWindow(AFX_IDW_TOOLBAR); 
	pToolBar->SetWindowText("设置的工具栏标题");	
	MessageBox("工具栏标题设置成功，请查看！");	
}
