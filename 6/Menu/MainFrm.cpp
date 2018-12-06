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
	//���ò˵���ͼ��
	m_Bitmap.LoadBitmap(IDB_BITMAP);//����λͼ��Դ
	CMenu * pMenu=GetMenu();//������˵�ָ��
	CMenu * pSubMenu=pMenu->GetSubMenu(0);//��ȡָ�򵯳��˵���ָ��
	pSubMenu->SetMenuItemBitmaps(1,MF_BYPOSITION,&m_Bitmap,&m_Bitmap);//��ָ����ǵ�λͼ��˵������
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
	//ȡ���������Ҽ�ϵͳ�˵�
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
//��ȡ����˵���ռ�Ĳ˵�����
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
//��Ӳ˵���
void CMainFrame::OnAdd() 
{ 
	CMenu *mainmenu; 
	mainmenu=AfxGetMainWnd()->GetMenu();//������˵�ָ��
	(mainmenu->GetSubMenu(0))->AppendMenu(MF_SEPARATOR);//��ӷָ���
	(mainmenu->GetSubMenu(0))->AppendMenu(MF_STRING,ID_APP_ABOUT,_T("�²˵���")); //����µĲ˵���
    mainmenu->Detach();//�����ڲ˵���CMenu�������
	DrawMenuBar();//�ػ��˵�	
}
/////////////////////////////////////////////////////////////////////////////
//ɾ���˵���
void CMainFrame::OnDelete() 
{
	CMenu *mainmenu; 
	mainmenu=AfxGetMainWnd()->GetMenu();//������˵�ָ��
	CString str ;
	for(int i=(mainmenu->GetSubMenu(0))->GetMenuItemCount()-1;i>=0;i--)//ȡ�ò˵���������
	{ 
		(mainmenu->GetSubMenu(0))->GetMenuString(i,str,MF_BYPOSITION); 
		//��ָ���˵���ı�ǩ������ָ���Ļ�����
		if(str=="�²˵���")//����Ǹղ��������ӵĲ˵����ɾ����
		{ 
			(mainmenu->GetSubMenu(0))->DeleteMenu(i,MF_BYPOSITION); 
			break; 
		}
	}	
	mainmenu->Detach();//�����ڲ˵���CMenu�������
	DrawMenuBar();//�ػ��˵�
}
/////////////////////////////////////////////////////////////////////////////
//��ȡ�˵����߶�
void CMainFrame::OnGetMenuHight() 
{
	CMenu *pMenu; 
	pMenu=AfxGetMainWnd()->GetMenu();//������˵�ָ��

	NONCLIENTMETRICS ncm;
	HFONT hFontMenu; 
	SIZE size; 
	size.cy=size.cy=0; 
	memset(&ncm,0,sizeof(NONCLIENTMETRICS));
	ncm.cbSize=sizeof(NONCLIENTMETRICS); 
	if(SystemParametersInfo(SPI_GETNONCLIENTMETRICS,sizeof(NONCLIENTMETRICS),&ncm,0))
	{  
		hFontMenu=CreateFontIndirect(&ncm.lfMenuFont); 
		//��ò˵�����ı� 
		char szText[_MAX_PATH]; 
		pMenu->GetMenuString(0,szText,_MAX_PATH,MF_BYPOSITION);
		//��ò˵����ı��ĸ߶� 
		HFONT hFontOld; 
		HDC hDC; 
		hDC=::GetDC(NULL); 
		hFontOld=(HFONT)::SelectObject(hDC,hFontMenu);
		GetTextExtentPoint32(hDC,szText,lstrlen(szText),&size); 
		SelectObject(hDC,hFontOld); 
		::ReleaseDC(NULL,hDC);
	}
	CString str;
	str.Format("�˵����ĸ߶�Ϊ��%d",size.cy);//size.cy��Ϊ�߶�
    AfxMessageBox(str);
}
/////////////////////////////////////////////////////////////////////////////
//��ӵ�ѡ���
void CMainFrame::OnUpdateCheck(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck();
}
/////////////////////////////////////////////////////////////////////////////
//��Ӹ�ѡ���
void CMainFrame::OnUpdateRadio(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio();
}
