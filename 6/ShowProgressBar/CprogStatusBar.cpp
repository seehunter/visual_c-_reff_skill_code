#include "StdAfx.h"
#include "CprogStatusBar.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CProgStatusBar, CStatusBar)

BEGIN_MESSAGE_MAP(CProgStatusBar, CStatusBar)
   ON_WM_CREATE()
   ON_WM_SIZE()
END_MESSAGE_MAP()
////////////////////////////////////////////////////////////////
CProgStatusBar::CProgStatusBar()
{
}

CProgStatusBar::~CProgStatusBar()
{
}
////////////////////////////////////////创建状态条时也创建进程条
int CProgStatusBar::OnCreate(LPCREATESTRUCT lpcs)
{
	lpcs->style |= WS_CLIPCHILDREN;
	VERIFY(CStatusBar::OnCreate(lpcs)==0);
	VERIFY(m_wndProgBar.Create(WS_CHILD, CRect(), this, 1));
	m_wndProgBar.SetRange(0,100); //设置进程条的范围；
	return 0;
}
////////////////////////////////////////////////////使进程度条的尺寸与状态条的尺寸同步变化；
void CProgStatusBar::OnSize(UINT nType, int cx, int cy)
{
	CStatusBar::OnSize(nType, cx, cy); 
	CRect rc; 
	GetItemRect(0, &rc); 
	m_wndProgBar.MoveWindow(&rc,FALSE);
}
////////////////////////////////////////////////////////////根据pct的当前值对进程条进行设置
void CProgStatusBar::OnProgress(UINT pct)
{
	CProgressCtrl& pc = m_wndProgBar;
	DWORD dwOldStyle = pc.GetStyle();
	DWORD dwNewStyle = dwOldStyle;
	if(pct>0) //如果pct>0，将显示进度条
		dwNewStyle |= WS_VISIBLE;
	else //否则隐藏进度条；
		dwNewStyle &= ~WS_VISIBLE;
	if(dwNewStyle != dwOldStyle) 
	{
		SetWindowText(NULL); //显示进度条前清空状态条；
		SetWindowLong(pc.m_hWnd, GWL_STYLE, dwNewStyle); 
		//设置进度条处于显示状态；
	}
	// 设置进度条的当前位置；
	pc.SetPos(pct);
	if(pct==0)// 如果pct等于0，通知主框架窗口显示空闲信息；//
		GetParent()->PostMessage(WM_SETMESSAGESTRING, AFX_IDS_IDLEMESSAGE);
}
