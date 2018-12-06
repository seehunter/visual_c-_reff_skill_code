// BmpProgCtrl.cpp : implementation file
//
/*

*/
#include "stdafx.h"
#include "BmpProg.h"
#include "BmpProgCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBmpProgCtrl

CBmpProgCtrl::CBmpProgCtrl()
{
	m_nLower = 1;
	m_nUpper = 100;
	m_nStep = 1;
	m_nPos = 0;
	pDCBack = new CDC;
	pDCFore = new CDC;
	bmpBack.LoadBitmap(IDB_BACK);
	bmpFore.LoadBitmap(IDB_FORE);
}

CBmpProgCtrl::~CBmpProgCtrl()
{
	delete pDCBack;
	delete pDCFore;
}


BEGIN_MESSAGE_MAP(CBmpProgCtrl, CStatic)
	//{{AFX_MSG_MAP(CBmpProgCtrl)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpProgCtrl message handlers

void CBmpProgCtrl::SetRange(int nLower, int nUpper)
{
	if(nUpper > nLower)
	{
		m_nLower = nLower;
		m_nUpper = nUpper;
	}
	else
	{
		m_nLower = nUpper;
		m_nUpper = nLower;
	}
}

int CBmpProgCtrl::SetPos(int nPos)
{
	if(m_nLower <= nPos && m_nUpper >= nPos)
	{
		m_nPos = nPos;
		return 1;
	}
	return 0;
}

int CBmpProgCtrl::OffsetPos(int nPos)
{
	CRect tempRect = m_rect;
	tempRect.left = m_length*m_rect.Width();
	m_nPos += nPos;
	if(m_nPos>m_nUpper)
	{
		m_nPos = m_nUpper;
		InvalidateRect(&tempRect);
		return 0;
	}
	InvalidateRect(&tempRect);
	return 1;
	
}

int CBmpProgCtrl::SetStep(int nStep)
{
	if(nStep>0)
	{
		m_nStep = nStep;
		return 1;
	}
	return 0;
}

int CBmpProgCtrl::StepIt()
{	
	CRect tempRect = m_rect;
	tempRect.left = m_length*m_rect.Width();
	m_nPos += m_nStep;
	if(m_nPos>m_nUpper)
	{
		m_nPos = m_nUpper;
		InvalidateRect(&tempRect);
		return 0;
	}
		InvalidateRect(&tempRect);
	return 1;
}

void CBmpProgCtrl::OnPaint() 
{
	m_length = (float)m_nPos/(m_nUpper-m_nLower);
	CPaintDC dc(this);
	GetClientRect(&m_rect);
	pDCBack->CreateCompatibleDC(&dc);
	pDCFore->CreateCompatibleDC(&dc);

	bmpBack.GetBitmap(&bmback);
	bmpFore.GetBitmap(&bmfore);
	pDCBack->SelectObject(bmpBack);

	dc.StretchBlt(0,0,m_rect.Width(),m_rect.Height(),pDCBack,0,0,bmback.bmWidth,bmback.bmHeight,SRCCOPY);

	(CBitmap*)pDCFore->SelectObject(bmpFore);
	dc.StretchBlt(0,0,m_rect.Width()*m_length,m_rect.Height(),pDCFore,0,0,bmfore.bmWidth*m_length,bmfore.bmHeight,SRCCOPY);
	
	pDCBack->DeleteDC();
	pDCFore->DeleteDC();
}

int CBmpProgCtrl::GetPos()
{
	return m_nPos;
}

void CBmpProgCtrl::GetRange(int &lower, int &upper)
{
	lower = m_nLower;
	upper = m_nUpper;
}
