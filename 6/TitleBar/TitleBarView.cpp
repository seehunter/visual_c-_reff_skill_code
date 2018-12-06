// TitleBarView.cpp : implementation of the CTitleBarView class
//

#include "stdafx.h"
#include "TitleBar.h"

#include "TitleBarDoc.h"
#include "TitleBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTitleBarView

IMPLEMENT_DYNCREATE(CTitleBarView, CView)

BEGIN_MESSAGE_MAP(CTitleBarView, CView)
	//{{AFX_MSG_MAP(CTitleBarView)
	ON_COMMAND(IDM_GET_TITLE_HEIGHT, OnGetTitleHeight)
	ON_COMMAND(IDM_GET_TITLE_COLOUR, OnGetTitleColour)
	ON_COMMAND(IDM_SET_TITLE_COLOUR, OnSetTitleColour)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTitleBarView construction/destruction

CTitleBarView::CTitleBarView()
{
	// TODO: add construction code here

}

CTitleBarView::~CTitleBarView()
{
}

BOOL CTitleBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTitleBarView drawing

void CTitleBarView::OnDraw(CDC* pDC)
{
	CTitleBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTitleBarView printing

BOOL CTitleBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTitleBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTitleBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTitleBarView diagnostics

#ifdef _DEBUG
void CTitleBarView::AssertValid() const
{
	CView::AssertValid();
}

void CTitleBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTitleBarDoc* CTitleBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTitleBarDoc)));
	return (CTitleBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTitleBarView message handlers
//获取标题栏的高度
void CTitleBarView::OnGetTitleHeight() 
{
	CString strTitleHeight;
	strTitleHeight.Format("标题栏的高度为: %d",GetSystemMetrics(SM_CYCAPTION));
	MessageBox(strTitleHeight,"提示",MB_OK);
}
/////////////////////////////////////////////////////////////////////////////
//获取标题栏的颜色
void CTitleBarView::OnGetTitleColour() 
{
	DWORD Color=GetSysColor(COLOR_CAPTIONTEXT);//获得标题栏颜色值
	CString strColor;
	strColor.Format("标题栏的颜色值为：RGB(%d，%d，%d)",GetRValue(Color),GetGValue(Color),GetBValue(Color));
	MessageBox(strColor,"提示",MB_OK);
}
/////////////////////////////////////////////////////////////////////////////
//设置标题栏的颜色
void CTitleBarView::OnSetTitleColour() 
{
	int nElement[2]={COLOR_CAPTIONTEXT,//活动标题栏文字
                     COLOR_INACTIVECAPTIONTEXT};//不活动标题栏文字
	DWORD dwColor[2]={RGB(0,0,0),//文字颜色为黑色
					 RGB(255,0,0)};//文字颜色为红色
	SetSysColors(2,nElement,&dwColor[1]);//设置标题栏的颜色
}
/////////////////////////////////////////////////////////////////////////////
//