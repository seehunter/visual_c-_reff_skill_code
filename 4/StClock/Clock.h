/************************************************************************/
/* 
/************************************************************************/
#if !defined(AFX_CLOCK_H__DED3D2C0_149E_47EF_B79E_C52A6ED4B70C__INCLUDED_)
#define AFX_CLOCK_H__DED3D2C0_149E_47EF_B79E_C52A6ED4B70C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CClock  
{
public:
	CClock();
	virtual ~CClock();
//Operation
public:
	int  Change(char ch);
	void MyFun(CString temp);                             //显示数字字符串
	void InitClock(CDialog *,int tnum,int tx,int ty,int tspace);//设置显示位置
//Attribute
public:
	CString  m_strTime;
	CStatic  *m_Pic[50];// 静态图 指针数组
	int      m_nNum;    // 静态图个数
	int      m_nStartX; // 起始X坐标
	int      m_nStartY; // 起始Y坐标
	int      m_nSpace;  // 各数码之间的间距
};
#endif // !defined(AFX_CLOCK_H__DED3D2C0_149E_47EF_B79E_C52A6ED4B70C__INCLUDED_)
