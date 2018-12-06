// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Menu.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(IDM_MENU_ROW, OnMenuRow)
	ON_COMMAND(IDM_ADD, OnAdd)
	ON_COMMAND(IDM_DELETE, OnDelete)
	ON_COMMAND(IDM_GET_MENU_HIGHT, OnGetMenuHight)
	ON_UPDATE_COMMAND_UI(IDM_CHECK, OnUpdateCheck)
	ON_UPDATE_COMMAND_UI(IDM_RADIO, OnUpdateRadio)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	//////////////
	//设置菜单项图标
	m_Bitmap.LoadBitmap(IDB_BITMAP);//加载位图资源
	CMenu * pMenu=GetMenu();//获得主菜单指针
	CMenu * pSubMenu=pMenu->GetSubMenu(0);//获取指向弹出菜单的指针
	pSubMenu->SetMenuItemBitmaps(1,MF_BYPOSITION,&m_Bitmap,&m_Bitmap);//将指定标记的位图与菜单项关联
	//
	//////////////
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
//
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
    //////////////////////////////////////
	//取消标题栏右键系统菜单
	cs.style&=~WS_SYSMENU;
	//
	//////////////////////////////////////
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
//CMainFrame message handlers
//获取顶层菜单所占的菜单行数
void CMainFrame::OnMenuRow() 
{
	CRect rcFrame,rcClient; 
	GetWindowRect(rcFrame); 
	GetClientRect(rcClient); 
	int nRowCount=(rcFrame.Height()-rcClient.Height()-
		::GetSystemMetrics(SM_CYCAPTION)-(::GetSystemMetrics(SM_CYFRAME) *2))/
		::GetSystemMetrics(SM_CYMENU);
	CString str;
	str.Format("%d",nRowCount);
	AfxMessageBox(str);	
}
/////////////////////////////////////////////////////////////////////////////
//添加菜单项
void CMainFrame::OnAdd() 
{ 
	CMenu *mainmenu; 
	mainmenu=AfxGetMainWnd()->GetMenu();//获得主菜单指针
	(mainmenu->GetSubMenu(0))->AppendMenu(MF_SEPARATOR);//添加分隔符
	(mainmenu->GetSubMenu(0))->AppendMenu(MF_STRING,ID_APP_ABOUT,_T("新菜单项")); //添加新的菜单项
    mainmenu->Detach();//将窗口菜单与CMenu对象分离
	DrawMenuBar();//重画菜单	
}
/////////////////////////////////////////////////////////////////////////////
//删除菜单项
void CMainFrame::OnDelete() 
{
	CMenu *mainmenu; 
	mainmenu=AfxGetMainWnd()->GetMenu();//获得主菜单指针
	CString str ;
	for(int i=(mainmenu->GetSubMenu(0))->GetMenuItemCount()-1;i>=0;i--)//取得菜单的项数。
	{ 
		(mainmenu->GetSubMenu(0))->GetMenuString(i,str,MF_BYPOSITION); 
		//将指定菜单项的标签拷贝到指定的缓冲区
		if(str=="新菜单项")//如果是刚才我们增加的菜单项，则删除。
		{ 
			(mainmenu->GetSubMenu(0))->DeleteMenu(i,MF_BYPOSITION); 
			break; 
		}
	}	
	mainmenu->Detach();//将窗口菜单与CMenu对象分离
	DrawMenuBar();//重画菜单
}
/////////////////////////////////////////////////////////////////////////////
//获取菜单栏高度
void CMainFrame::OnGetMenuHight() 
{
	CMenu *pMenu; 
	pMenu=AfxGetMainWnd()->GetMenu();//获得主菜单指针

	NONCLIENTMETRICS ncm;
	HFONT hFontMenu; 
	SIZE size; 
	size.cy=size.cy=0; 
	memset(&ncm,0,sizeof(NONCLIENTMETRICS));
	ncm.cbSize=sizeof(NONCLIENTMETRICS); 
	if(SystemParametersInfo(SPI_GETNONCLIENTMETRICS,sizeof(NONCLIENTMETRICS),&ncm,0))
	{  
		hFontMenu=CreateFontIndirect(&ncm.lfMenuFont); 
		//获得菜单项的文本 
		char szText[_MAX_PATH]; 
		pMenu->GetMenuString(0,szText,_MAX_PATH,MF_BYPOSITION);
		//获得菜单项文本的高度 
		HFONT hFontOld; 
		HDC hDC; 
		hDC=::GetDC(NULL); 
		hFontOld=(HFONT)::SelectObject(hDC,hFontMenu);
		GetTextExtentPoint32(hDC,szText,lstrlen(szText),&size); 
		SelectObject(hDC,hFontOld); 
		::ReleaseDC(NULL,hDC);
	}
	CString str;
	str.Format("菜单栏的高度为：%d",size.cy);//size.cy即为高度
    AfxMessageBox(str);
}
/////////////////////////////////////////////////////////////////////////////
//添加单选标记
void CMainFrame::OnUpdateCheck(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck();
}
/////////////////////////////////////////////////////////////////////////////
//添加复选标记
void CMainFrame::OnUpdateRadio(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio();
}
