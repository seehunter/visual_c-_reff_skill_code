// DDBView.cpp : implementation of the CDDBView class
//

#include "stdafx.h"
#include "DDB.h"

#include "DDBDoc.h"
#include "DDBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDDBView

IMPLEMENT_DYNCREATE(CDDBView, CView)

BEGIN_MESSAGE_MAP(CDDBView, CView)
	//{{AFX_MSG_MAP(CDDBView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDDBView construction/destruction

CDDBView::CDDBView()
{
	// TODO: add construction code here

}

CDDBView::~CDDBView()
{
}

BOOL CDDBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDDBView drawing

void CDDBView::OnDraw(CDC* pDC)
{
	CDDBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	CDC MemDC; //首先定义一个显示设备对象
	CBitmap MemBitmap;//定义一个位图对象
//	MemBitmap.LoadBitmap(IDB_BITMAP1);
	//随后建立与屏幕显示兼容的内存显示设备
	MemDC.CreateCompatibleDC(NULL);
	//这时还不能绘图，因为没有地方画
	MemBitmap.CreateCompatibleBitmap(pDC,48,48);
	//将位图选入到内存显示设备中
	//只有选入了位图的内存显示设备才有地方绘图，画到指定的位图上
	CBitmap *pOldBit=MemDC.SelectObject(&MemBitmap);
	//先用背景色将位图清除干净，这里我用的是白色作为背景
	//你也可以用自己应该用的颜色
	MemDC.FillSolidRect(0,0,48,48,RGB(255,255,255));
	//绘图
	MemDC.TextOut(0,0,"文明子");

	//将内存中的图拷贝到屏幕上进行显示
	pDC->BitBlt(0,0,48,48,&MemDC,0,0,SRCCOPY);
	//绘图完成后的清理
	MemBitmap.DeleteObject();
	MemDC.DeleteDC();

}

/////////////////////////////////////////////////////////////////////////////
// CDDBView printing

BOOL CDDBView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDDBView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDDBView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDDBView diagnostics

#ifdef _DEBUG
void CDDBView::AssertValid() const
{
	CView::AssertValid();
}

void CDDBView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDDBDoc* CDDBView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDDBDoc)));
	return (CDDBDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDDBView message handlers
