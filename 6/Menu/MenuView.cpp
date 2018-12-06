// MenuView.cpp : implementation of the CMenuView class
//

#include "stdafx.h"
#include "Menu.h"

#include "MenuDoc.h"
#include "MenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuView

IMPLEMENT_DYNCREATE(CMenuView, CView)

BEGIN_MESSAGE_MAP(CMenuView, CView)
	//{{AFX_MSG_MAP(CMenuView)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDM_HIDE_MENU, OnHideMenu)
	ON_COMMAND(IDM_SHOW_MENU, OnShowMenu)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuView construction/destruction

CMenuView::CMenuView()
{
	// TODO: add construction code here

}

CMenuView::~CMenuView()
{
}

BOOL CMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMenuView drawing

void CMenuView::OnDraw(CDC* pDC)
{
	CMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMenuView printing

BOOL CMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMenuView diagnostics

#ifdef _DEBUG
void CMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenuDoc* CMenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenuDoc)));
	return (CMenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenuView message handlers
/////////////////////////////////////////////////////////////////////////////
//右键弹出菜单
void CMenuView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CRect rc;
	GetWindowRect(&rc);
	point.x=rc.left+point.x;
	point.y=rc.left+point.y;
	CMenu * pPopMenu=new CMenu;
    pPopMenu->LoadMenu(IDR_MENU);//加载菜单资源
    CMenu * pMenu=pPopMenu->GetSubMenu(0);//获取指向弹出菜单的指针
    pMenu->TrackPopupMenu(TPM_LEFTBUTTON|TPM_RIGHTBUTTON,point.x,point.y,this);//在指定的位置显示浮动菜单，并跟踪弹出菜单的选择项
	delete pPopMenu;//删除pPopMenu
	CView::OnRButtonDown(nFlags, point);
}
/////////////////////////////////////////////////////////////////////////////
//隐藏菜单
void CMenuView::OnHideMenu() 
{
	CWnd *pWnd=AfxGetMainWnd();//获得主窗口指针
	pWnd->SetMenu(NULL);//设置菜单为空
	pWnd->DrawMenuBar();//重画菜单
}
/////////////////////////////////////////////////////////////////////////////
//显示菜单
void CMenuView::OnShowMenu() 
{
	CWnd *pWnd=AfxGetMainWnd();//获得主窗口指针
	CMenu menu;
	menu.LoadMenu(IDR_MAINFRAME);//加载菜单资源
	pWnd->SetMenu(&menu);//设置当前菜单
	pWnd->DrawMenuBar();//重画菜单条
	menu.Detach();//将窗口菜单与CMenu对象分离，并返回这个句柄
}
/////////////////////////////////////////////////////////////////////////////
//
