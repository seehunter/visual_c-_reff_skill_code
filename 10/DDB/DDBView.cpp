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
	
	CDC MemDC; //���ȶ���һ����ʾ�豸����
	CBitmap MemBitmap;//����һ��λͼ����
//	MemBitmap.LoadBitmap(IDB_BITMAP1);
	//���������Ļ��ʾ���ݵ��ڴ���ʾ�豸
	MemDC.CreateCompatibleDC(NULL);
	//��ʱ�����ܻ�ͼ����Ϊû�еط���
	MemBitmap.CreateCompatibleBitmap(pDC,48,48);
	//��λͼѡ�뵽�ڴ���ʾ�豸��
	//ֻ��ѡ����λͼ���ڴ���ʾ�豸���еط���ͼ������ָ����λͼ��
	CBitmap *pOldBit=MemDC.SelectObject(&MemBitmap);
	//���ñ���ɫ��λͼ����ɾ����������õ��ǰ�ɫ��Ϊ����
	//��Ҳ�������Լ�Ӧ���õ���ɫ
	MemDC.FillSolidRect(0,0,48,48,RGB(255,255,255));
	//��ͼ
	MemDC.TextOut(0,0,"������");

	//���ڴ��е�ͼ��������Ļ�Ͻ�����ʾ
	pDC->BitBlt(0,0,48,48,&MemDC,0,0,SRCCOPY);
	//��ͼ��ɺ������
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
