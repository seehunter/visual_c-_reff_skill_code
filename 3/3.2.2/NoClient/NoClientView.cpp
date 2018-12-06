// NoClientView.cpp : implementation of the CNoClientView class
//

#include "stdafx.h"
#include "NoClient.h"

#include "NoClientDoc.h"
#include "NoClientView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNoClientView

IMPLEMENT_DYNCREATE(CNoClientView, CView)

BEGIN_MESSAGE_MAP(CNoClientView, CView)
	//{{AFX_MSG_MAP(CNoClientView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_WM_NCMOUSEMOVE()
END_MESSAGE_MAP()

////////////////////////////////////////////
/////////////////////////////////
// CNoClientView construction/destruction

CNoClientView::CNoClientView()
{
	// TODO: add construction code here

}

CNoClientView::~CNoClientView()
{
}

BOOL CNoClientView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNoClientView drawing

void CNoClientView::OnDraw(CDC* pDC)
{
	CNoClientDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CNoClientView printing

BOOL CNoClientView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNoClientView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNoClientView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNoClientView diagnostics

#ifdef _DEBUG
void CNoClientView::AssertValid() const
{
	CView::AssertValid();
}

void CNoClientView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNoClientDoc* CNoClientView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNoClientDoc)));
	return (CNoClientDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNoClientView message handlers


     
void CNoClientView::OnNcMouseMove(UINT nHitTest, CPoint point) 
{
//	显示提示信息
	CRect rc;
    MessageBox("tst");
	CView::OnNcMouseMove(HTCAPTION, point);

}