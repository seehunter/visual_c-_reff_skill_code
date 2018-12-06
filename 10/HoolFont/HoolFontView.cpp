// HoolFontView.cpp : implementation of the CHoolFontView class
//

#include "stdafx.h"
#include "HoolFont.h"

#include "HoolFontDoc.h"
#include "HoolFontView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHoolFontView

IMPLEMENT_DYNCREATE(CHoolFontView, CView)

BEGIN_MESSAGE_MAP(CHoolFontView, CView)
	//{{AFX_MSG_MAP(CHoolFontView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHoolFontView construction/destruction

CHoolFontView::CHoolFontView()
{
	// TODO: add construction code here

}

CHoolFontView::~CHoolFontView()
{
}

BOOL CHoolFontView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHoolFontView drawing

void CHoolFontView::OnDraw(CDC* pDC)
{
	CHoolFontDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	LOGFONT lf;
	pDC->GetCurrentFont()->GetLogFont(&lf);
	CFont font;
	CFont *pOldFont; // �����豸���������ʹ�õ��������
	lf.lfCharSet=134;
	lf.lfHeight=-150;
	lf.lfHeight=-150;
	lf.lfWidth=0;
	strcpy(lf.lfFaceName, "����");
	font.CreateFontIndirect(&lf);
	pOldFont=pDC->SelectObject(&font);
	pDC->SetBkMode(TRANSPARENT); // ���ĵ�ǰ����
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *pOldPen;
	pOldPen=pDC->SelectObject(&pen); // ��ʼ����·�� 
	pDC->BeginPath();
	pDC->TextOut(10, 10, "��ʾ��������");
	pDC->EndPath(); // ·��������� 
	//pDC->StrokePath(); 
	pDC->StrokeAndFillPath();//���·������
	//������pDC->StrokeAndFillPath()���������棬�ú����뺯��StrokePath�Ĳ�ͬ���ڻ�ʹ�õ�ǰˢ�����·�����ڲ���
	pDC->SelectObject(pOldFont);
	pDC->SelectObject(pOldPen);
}

/////////////////////////////////////////////////////////////////////////////
// CHoolFontView printing

BOOL CHoolFontView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHoolFontView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHoolFontView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHoolFontView diagnostics

#ifdef _DEBUG
void CHoolFontView::AssertValid() const
{
	CView::AssertValid();
}

void CHoolFontView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHoolFontDoc* CHoolFontView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHoolFontDoc)));
	return (CHoolFontDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHoolFontView message handlers
