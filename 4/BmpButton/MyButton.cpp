// MyButton.cpp : implementation file
//

#include "stdafx.h"
#include "BmpButton.h"
#include "MyButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyButton

CMyButton::CMyButton()
{
//	
}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
	//{{AFX_MSG_MAP(CMyButton)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyButton message handlers
void CMyButton::SetBtnBitmap(HBITMAP hBitmap1,HBITMAP hBitmap2)
{
	m_hBmp1 = hBitmap1;
	m_hBmp2 = hBitmap2;
	ModifyStyle(0,BS_BITMAP);
}


void CMyButton::OnMouseMove(UINT nFlags, CPoint point) 
{
    CRect rect;
	GetWindowRect(&rect);
	ScreenToClient(&rect);
    if(rect.PtInRect(point))
	{
	    SetBitmap(m_hBmp1);
	}
	else
	{
    	SetBitmap(m_hBmp2);
	}
	CButton::OnMouseMove(nFlags, point);
}
