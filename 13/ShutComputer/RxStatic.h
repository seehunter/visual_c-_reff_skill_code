#if !defined(AFX_RXSTATIC_H__134230C6_AAD7_4461_B1FE_2A796909C386__INCLUDED_)
#define AFX_RXSTATIC_H__134230C6_AAD7_4461_B1FE_2A796909C386__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RxStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRxStatic window

class CRxStatic : public CStatic
{
#define CHINESE GB2312_CHARSET
#define ENGLISH DEFAULT_CHARSET 
#define CLARITY -1 

// Construction
public:
	CRxStatic();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRxStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetShadow(bool bShadow=true,COLORREF cShadowColor=RGB(244,0,0),int nInterval=2,int nAngle=30);
	void SetFontStyle(bool bItalic=false,bool bBold=false,bool bUnderline=false);
	void SetBkColor(COLORREF dwColor=CLARITY);
	void SetTextColor(COLORREF dwColor);
	void SetFontSize(int nSize);
	void SetFont(CString sFontName,DWORD lpLanguage=CHINESE);
	virtual ~CRxStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRxStatic)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	CString m_lpFont;   //��������
	int m_nSize;    //�����С
	COLORREF m_FontColor;  //ǰ��ɫ
 	COLORREF m_BkColor;    //����ɫ
	bool m_bItalic;   //�Ƿ�Ϊб��
	bool m_bBold;    //�Ƿ�Ϊ����
	bool m_bUnderline;    //�Ƿ����»���
	DWORD m_dwCharacter;
	bool m_bIsShadow;
	COLORREF m_ShadowColor;
	int m_nInterval;
	int m_nAngle;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RXSTATIC_H__134230C6_AAD7_4461_B1FE_2A796909C386__INCLUDED_)
