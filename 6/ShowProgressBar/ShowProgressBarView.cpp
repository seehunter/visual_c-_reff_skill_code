// ShowProgressBarView.cpp : implementation of the CShowProgressBarView class
//

#include "stdafx.h"
#include "ShowProgressBar.h"

#include "ShowProgressBarDoc.h"
#include "ShowProgressBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowProgressBarView

IMPLEMENT_DYNCREATE(CShowProgressBarView, CEditView)

BEGIN_MESSAGE_MAP(CShowProgressBarView, CEditView)
	//{{AFX_MSG_MAP(CShowProgressBarView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowProgressBarView construction/destruction

CShowProgressBarView::CShowProgressBarView()
{
	// TODO: add construction code here

}

CShowProgressBarView::~CShowProgressBarView()
{
}

BOOL CShowProgressBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CShowProgressBarView drawing

void CShowProgressBarView::OnDraw(CDC* pDC)
{
	CShowProgressBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CShowProgressBarView printing

BOOL CShowProgressBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CShowProgressBarView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing.
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CShowProgressBarView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CShowProgressBarView diagnostics

#ifdef _DEBUG
void CShowProgressBarView::AssertValid() const
{
	CEditView::AssertValid();
}

void CShowProgressBarView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CShowProgressBarDoc* CShowProgressBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShowProgressBarDoc)));
	return (CShowProgressBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowProgressBarView message handlers
