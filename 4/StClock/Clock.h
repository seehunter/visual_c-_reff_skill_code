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
	void MyFun(CString temp);                             //��ʾ�����ַ���
	void InitClock(CDialog *,int tnum,int tx,int ty,int tspace);//������ʾλ��
//Attribute
public:
	CString  m_strTime;
	CStatic  *m_Pic[50];// ��̬ͼ ָ������
	int      m_nNum;    // ��̬ͼ����
	int      m_nStartX; // ��ʼX����
	int      m_nStartY; // ��ʼY����
	int      m_nSpace;  // ������֮��ļ��
};
#endif // !defined(AFX_CLOCK_H__DED3D2C0_149E_47EF_B79E_C52A6ED4B70C__INCLUDED_)
