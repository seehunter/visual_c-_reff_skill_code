// SystemButtonView.cpp : implementation of the CSystemButtonView class
//

#include "stdafx.h"
#include "SystemButton.h"

#include "SystemButtonDoc.h"
#include "SystemButtonView.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSystemButtonView

IMPLEMENT_DYNCREATE(CSystemButtonView, CView)

BEGIN_MESSAGE_MAP(CSystemButtonView, CView)
	//{{AFX_MSG_MAP(CSystemButtonView)
	ON_COMMAND(IDM_CLOSE_DISUSEABLE, OnCloseDisuseable)
	ON_COMMAND(IDM_MAX_DISUSEABLE, OnMaxDisuseable)
	ON_COMMAND(IDM_MIN_DISUSEABLE, OnMinDisuseable)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSystemButtonView construction/destruction

CSystemButtonView::CSystemButtonView()
{
	m_strTitle = "";
}

CSystemButtonView::~CSystemButtonView()
{
}

BOOL CSystemButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSystemButtonView drawing

void CSystemButtonView::OnDraw(CDC* pDC)
{
	CSystemButtonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(400,250,m_strTitle);
}

/////////////////////////////////////////////////////////////////////////////
// CSystemButtonView printing

BOOL CSystemButtonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSystemButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSystemButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSystemButtonView diagnostics

#ifdef _DEBUG
void CSystemButtonView::AssertValid() const
{
	CView::AssertValid();
}

void CSystemButtonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSystemButtonDoc* CSystemButtonView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSystemButtonDoc)));
	return (CSystemButtonDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSystemButtonView message handlers

void CSystemButtonView::OnCloseDisuseable() 
{
	CMenu *pSysMenu=((CMainFrame*)AfxGetMainWnd())->GetSystemMenu(FALSE);
	//��ùرհ�ť��ID
	int nCount=pSysMenu->GetMenuItemCount();
	UINT nID=pSysMenu->GetMenuItemID(nCount-1);
	//ʹ�رհ�ť��Ч
	pSysMenu->EnableMenuItem(nID,MF_DISABLED);	
	m_strTitle = "�˳����ڵ�ϵͳ��ŦʧЧ";
    Invalidate(TRUE);
}

void CSystemButtonView::OnMaxDisuseable() 
{
	//��ô��ڷ��
	LONG style = ::GetWindowLong(m_hWnd,GWL_STYLE);
	//�����µķ��
	style &=  ~(WS_MAXIMIZEBOX);
	::SetWindowLong(m_hWnd,GWL_STYLE,style);
	//�ػ����ڱ߿�
	CRect rc;
	GetWindowRect(&rc);
	::SetWindowPos(m_hWnd,HWND_NOTOPMOST,rc.left,rc.top,rc.Width(),rc.Height(),SWP_DRAWFRAME);	
    m_strTitle = "��󻯴��ڵ�ϵͳ��ŦʧЧ";
    Invalidate(TRUE);

}

void CSystemButtonView::OnMinDisuseable() 
{
	//��ô��ڷ��
	LONG style = ::GetWindowLong(m_hWnd,GWL_STYLE);
	//�����µķ��
	style &=  ~(WS_MINIMIZEBOX);
	::SetWindowLong(m_hWnd,GWL_STYLE,style);
	//�ػ����ڱ߿�
	CRect rc;
	GetWindowRect(&rc);
	::SetWindowPos(m_hWnd,HWND_NOTOPMOST,rc.left,rc.top,rc.Width(),rc.Height(),SWP_DRAWFRAME);
	 m_strTitle = "��С�����ڵ�ϵͳ��ŦʧЧ";
    Invalidate(TRUE);

}
