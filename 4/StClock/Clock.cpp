// Clock.cpp: implementation of the CClock class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StClock.h"
#include "Clock.h"
#include "StClockDlg.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CClock::CClock()
{
	m_strTime = _T("");
	m_nNum = 0;
}
/************************************************************************/
/* 
/************************************************************************/
CClock::~CClock()
{
	for(int i=0; i<m_nNum; i++)
		delete *(m_Pic+i);
}
/************************************************************************/
/* 
/************************************************************************/
int  CClock::Change(char ch)
{
	switch(ch) 
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':return ch-'0';
		break;
	case ' ':return 10;
		break;
	case 'A':return 11;
		break;
	case 'P':return 12;
		break;
	case '.':return 13;
		break;
	case '|':return 14;
		break;
	case ':':return 15;
		break;
	case '-':return 16;
		break;
	default: return 10;
	}
}
/************************************************************************/
/* 
/************************************************************************/
void CClock::MyFun(CString temp)                             
{
	m_strTime=temp;
	int mynum = m_strTime.GetLength();
	
	for(int k=0;k<m_nNum-mynum;k++)//添加前面空图标显示
	{
		CImageList m_imgList;
		m_imgList.Create(IDB_BMPTIME,12, 1, RGB(255,255,255));//创建位图链 每个位图12像素
		HICON myico= m_imgList.ExtractIcon(10);	//取出图标
		m_Pic[k]->SetIcon(myico);//设置显示的图标		
	}
	for(int i=k;i<m_nNum;i++)//添加数字图标显示
	{
		CImageList m_imgList;
		m_imgList.Create(IDB_BMPTIME,12, 1, RGB(255,255,255));
		HICON myico= m_imgList.ExtractIcon(Change(m_strTime[i-k]));	
		m_Pic[i]->SetIcon(myico);	
	}	
}
/************************************************************************/
/* 
/************************************************************************/
void CClock::InitClock(CDialog *parent,int tnum,int tx,int ty,int tspace)
{
	CStClockDlg *pDlg=(CStClockDlg*)parent;
	for(int i=0;i<m_nNum;i++)// 删除以前分配的
		delete *(m_Pic+i);
	// 设置各成员变量
	m_nNum = tnum;
	m_nStartX = tx;
	m_nStartY = ty;
	m_nSpace = tspace;
	for(int j=0;j<m_nNum;j++)//重新分配
		m_Pic[j]=new CStatic;

	for(int k=0;k<m_nNum;k++)
	{
		//确定显示位置
		CRect rt(m_nStartX+k*(m_nSpace+12),m_nStartY,40+m_nStartX+k*(m_nSpace+12),40+m_nStartY);
		m_Pic[k]->Create(NULL,SS_ICON,rt,pDlg,1);// 创建静态图标控件
		m_Pic[k]->ShowWindow(true);
	}
}