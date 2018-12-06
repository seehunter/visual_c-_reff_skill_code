// CursorView.cpp : implementation of the CCursorView class
//

#include "stdafx.h"
#include "Cursor.h"

#include "CursorDoc.h"
#include "CursorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCursorView

IMPLEMENT_DYNCREATE(CCursorView, CView)

BEGIN_MESSAGE_MAP(CCursorView, CView)
	//{{AFX_MSG_MAP(CCursorView)
	ON_WM_SETCURSOR()
	ON_COMMAND(IDM_GET_CURSOR_SIZE, OnGetCursorSize)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCursorView construction/destruction

CCursorView::CCursorView()
{
	// TODO: add construction code here

}

CCursorView::~CCursorView()
{
}
/////////////////////////////////////////////////////////////////////////////
//
BOOL CCursorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	//////////////////////////////////
	//加载标准的光标，IDC_UPARROW代表向上指的箭头光标
	HCURSOR hcursor=AfxGetApp()->LoadStandardCursor(IDC_UPARROW);
	//注册窗口类，并指定光标，CreateSolidBrush是指定画刷颜色为白色
	cs.lpszClass=AfxRegisterWndClass(CS_HREDRAW,hcursor,::CreateSolidBrush(RGB(255,255,255)));
	/////////////////////////////////
	return CView::PreCreateWindow(cs);
}
/////////////////////////////////////////////////////////////////////////////
// CCursorView drawing

void CCursorView::OnDraw(CDC* pDC)
{
	CCursorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CCursorView printing

BOOL CCursorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCursorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCursorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCursorView diagnostics

#ifdef _DEBUG
void CCursorView::AssertValid() const
{
	CView::AssertValid();
}

void CCursorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCursorDoc* CCursorView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCursorDoc)));
	return (CCursorDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCursorView message handlers
BOOL CCursorView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	/*HCURSOR hcursor=AfxGetApp()->LoadStandardCursor(IDC_UPARROW);//加载标准的光标，IDC_UPARROW代表向上指的箭头光标
	SetCursor(hcursor);//设置光标
	return TRUE;*/
	return CView::OnSetCursor(pWnd, nHitTest, message);
}
/////////////////////////////////////////////////////////////////////////////
//获取默认光标
void CCursorView::OnGetCursorSize() 
{
	CString str;
	str.Format("默认光标的大小为:宽度为%d，高度为%d",GetSystemMetrics(SM_CXCURSOR),GetSystemMetrics(SM_CYCURSOR));
	MessageBox(str,"提示",MB_OK);	
}
/////////////////////////////////////////////////////////////////////////////
//