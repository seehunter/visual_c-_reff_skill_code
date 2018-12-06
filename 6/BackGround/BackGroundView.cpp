// BackGroundView.cpp : implementation of the CBackGroundView class
//

#include "stdafx.h"
#include "BackGround.h"

#include "BackGroundDoc.h"
#include "BackGroundView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBackGroundView

IMPLEMENT_DYNCREATE(CBackGroundView, CView)

BEGIN_MESSAGE_MAP(CBackGroundView, CView)
	//{{AFX_MSG_MAP(CBackGroundView)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBackGroundView construction/destruction

CBackGroundView::CBackGroundView()
{
	// TODO: add construction code here

}

CBackGroundView::~CBackGroundView()
{
}

BOOL CBackGroundView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBackGroundView drawing

void CBackGroundView::OnDraw(CDC* pDC)
{
	CBackGroundDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBackGroundView printing

BOOL CBackGroundView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBackGroundView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBackGroundView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBackGroundView diagnostics

#ifdef _DEBUG
void CBackGroundView::AssertValid() const
{
	CView::AssertValid();
}

void CBackGroundView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBackGroundDoc* CBackGroundView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBackGroundDoc)));
	return (CBackGroundDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBackGroundView message handlers
BOOL CBackGroundView::OnEraseBkgnd(CDC* pDC) 
{
	CRect rect;
	GetClientRect(&rect);//��ÿͻ���������
	CBrush brush;
	brush.CreateSolidBrush(RGB(255,118,110));//���ñ�����ˢ��ɫ
	pDC->GetClipBox(&rect);//������Ҫ��������
	pDC->FillRect(&rect,&brush);//�����õĻ�ˢ����������
	return TRUE;
    /*CBrush brush(RGB(255,18,12));//���ñ�����ˢ��ɫ
    CBrush* pOldBrush=pDC->SelectObject(&brush);//����ɻ�ˢ
    CRect rect;
    pDC->GetClipBox(&rect);//������Ҫ��������
    pDC->PatBlt(rect.left,rect.top,rect.Width(),rect.Height(),PATCOPY);
    pDC->SelectObject(pOldBrush);
    return TRUE;*/
}


