// MyStatic.cpp : implementation file
//

#include "stdafx.h"
#include "3DStatic.h"
#include "MyStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyStatic

CMyStatic::CMyStatic()
{
    m_TxtColor = 	RGB(30,30,30);
	m_ShdowColor = 	RGB(200,80,80);
	m_BkColor = RGB(0,0,0);
}

CMyStatic::~CMyStatic()
{
}


BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	//{{AFX_MSG_MAP(CMyStatic)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyStatic message handlers
/************************************************************************/
/* 
/************************************************************************/
void CMyStatic::Set3DText(int nHeight, int nWidth, int nEscapement, int nOrientation, int nWeight, 
						  BYTE bItalic, BYTE bUnderline, BYTE cStrikeOut, BYTE nCharSet, 
						  BYTE nOutPrecision, BYTE nClipPrecision, BYTE nQuality, 
						  BYTE nPitchAndFamily, LPCTSTR lpszFacename,COLORREF  colorTxt,COLORREF  colorShdow )
{
		m_font.CreateFont(
		nHeight,                        // nHeight
		nWidth,                         // nWidth
		nEscapement,                         // nEscapement
		nOrientation,                         // nOrientation
		nWeight,                 // nWeight
		bItalic,                     // bItalic
		bUnderline,                     // bUnderline
		cStrikeOut,                         // cStrikeOut
		nCharSet,              // nCharSet
		nOutPrecision,        // nOutPrecision
		nClipPrecision,       // nClipPrecision
		nQuality,           // nQuality
		nPitchAndFamily,  // nPitchAndFamily
		_T(lpszFacename));                 
	   SetFont(&m_font);
       m_TxtColor = colorTxt;
	   m_ShdowColor = colorShdow;
       GetWindowText(m_strCap);
}
/************************************************************************/
/* 
/************************************************************************/
void CMyStatic::SetCtrlBkGr(COLORREF color)
{
	m_BkColor = color;
}
void CMyStatic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	dc.SetBkColor(m_BkColor);

//	此段代码为3D效果的代码
	
	CFont* oldFont =  dc.SelectObject(&m_font);
	CRect rect;
	GetClientRect(&rect);
	dc.SetTextColor(m_TxtColor);    //字体颜色   
	//dc.SetBkMode(TRANSPARENT);
	
	dc.DrawText(m_strCap,rect,LVCFMT_LEFT);

	rect.top = rect.top - 3;
	rect.left = rect.left - 3;
	dc.SetTextColor(m_ShdowColor);    //字体颜色

	dc.DrawText(m_strCap,rect,LVCFMT_LEFT);
    dc.SelectObject(oldFont);

 
}
/************************************************************************/
/* 
/************************************************************************/
void CMyStatic::SetCtrlBitmap(HBITMAP HBitmap)
{
  ModifyStyle(0, SS_BITMAP|WS_VISIBLE|WS_CHILD); 
  m_hBitmap = HBitmap;
  SetBitmap(m_hBitmap);
}
/************************************************************************/
/* 
/************************************************************************/
void CMyStatic::SetCtrlIcon(HICON HIcon)
{
  SetIcon(HIcon);
}