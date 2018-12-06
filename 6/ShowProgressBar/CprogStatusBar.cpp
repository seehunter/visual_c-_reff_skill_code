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
////////////////////////////////////////����״̬��ʱҲ����������
int CProgStatusBar::OnCreate(LPCREATESTRUCT lpcs)
{
	lpcs->style |= WS_CLIPCHILDREN;
	VERIFY(CStatusBar::OnCreate(lpcs)==0);
	VERIFY(m_wndProgBar.Create(WS_CHILD, CRect(), this, 1));
	m_wndProgBar.SetRange(0,100); //���ý������ķ�Χ��
	return 0;
}
////////////////////////////////////////////////////ʹ���̶����ĳߴ���״̬���ĳߴ�ͬ���仯��
void CProgStatusBar::OnSize(UINT nType, int cx, int cy)
{
	CStatusBar::OnSize(nType, cx, cy); 
	CRect rc; 
	GetItemRect(0, &rc); 
	m_wndProgBar.MoveWindow(&rc,FALSE);
}
////////////////////////////////////////////////////////////����pct�ĵ�ǰֵ�Խ�������������
void CProgStatusBar::OnProgress(UINT pct)
{
	CProgressCtrl& pc = m_wndProgBar;
	DWORD dwOldStyle = pc.GetStyle();
	DWORD dwNewStyle = dwOldStyle;
	if(pct>0) //���pct>0������ʾ������
		dwNewStyle |= WS_VISIBLE;
	else //�������ؽ�������
		dwNewStyle &= ~WS_VISIBLE;
	if(dwNewStyle != dwOldStyle) 
	{
		SetWindowText(NULL); //��ʾ������ǰ���״̬����
		SetWindowLong(pc.m_hWnd, GWL_STYLE, dwNewStyle); 
		//���ý�����������ʾ״̬��
	}
	// ���ý������ĵ�ǰλ�ã�
	pc.SetPos(pct);
	if(pct==0)// ���pct����0��֪ͨ����ܴ�����ʾ������Ϣ��//
		GetParent()->PostMessage(WM_SETMESSAGESTRING, AFX_IDS_IDLEMESSAGE);
}
