// StatProgView.cpp : CStatProgView ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CStatProgView ����/����

CStatProgView::CStatProgView()
{
	// TODO: �ڴ˴���ӹ������

}

CStatProgView::~CStatProgView()
{
}

BOOL CStatProgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ������
	// ��ʽ

	return CView::PreCreateWindow(cs);
}

// CStatProgView ����

void CStatProgView::OnDraw(CDC* /*pDC*/)
{
	CStatProgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CStatProgView ��ӡ

BOOL CStatProgView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CStatProgView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��ӡǰ��Ӷ���ĳ�ʼ��
}

void CStatProgView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��ӡ������������
}


// CStatProgView ���

#ifdef _DEBUG
void CStatProgView::AssertValid() const
{
	CView::AssertValid();
}

void CStatProgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStatProgDoc* CStatProgView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStatProgDoc)));
	return (CStatProgDoc*)m_pDocument;
}
#endif //_DEBUG


// CStatProgView ��Ϣ�������
