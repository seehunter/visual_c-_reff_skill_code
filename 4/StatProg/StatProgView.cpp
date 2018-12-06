// StatProgView.cpp : CStatProgView 类的实现
//

#include "stdafx.h"
#include "StatProg.h"

#include "StatProgDoc.h"
#include "StatProgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStatProgView

IMPLEMENT_DYNCREATE(CStatProgView, CView)

BEGIN_MESSAGE_MAP(CStatProgView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CStatProgView 构造/析构

CStatProgView::CStatProgView()
{
	// TODO: 在此处添加构造代码

}

CStatProgView::~CStatProgView()
{
}

BOOL CStatProgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或
	// 样式

	return CView::PreCreateWindow(cs);
}

// CStatProgView 绘制

void CStatProgView::OnDraw(CDC* /*pDC*/)
{
	CStatProgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CStatProgView 打印

BOOL CStatProgView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CStatProgView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 打印前添加额外的初始化
}

void CStatProgView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 打印后添加清除过程
}


// CStatProgView 诊断

#ifdef _DEBUG
void CStatProgView::AssertValid() const
{
	CView::AssertValid();
}

void CStatProgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStatProgDoc* CStatProgView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStatProgDoc)));
	return (CStatProgDoc*)m_pDocument;
}
#endif //_DEBUG


// CStatProgView 消息处理程序
