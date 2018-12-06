// MyEdit.cpp : implementation file
//

#include "stdafx.h"
#include "CatchPic.h"
#include "MyEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyEdit

CMyEdit::CMyEdit()
{
	m_bMove = TRUE;
}

CMyEdit::~CMyEdit()
{
}


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	//{{AFX_MSG_MAP(CMyEdit)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyEdit message handlers

HBRUSH CMyEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// TODO: Change any attributes of the DC here
	pDC->SetBkColor(TRANSPARENT);
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return NULL;
}

int CMyEdit::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CEdit::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CMyEdit::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	GetWindowRect(&rect);

	int xScreen = GetSystemMetrics(SM_CXSCREEN);//获取屏幕的X的分辨率

   	if(m_bMove)		//移动到左上角
	{
		MoveWindow(10,10,rect.Width(),rect.Height());
		m_bMove=FALSE;
	}
	else//移动到右上角
	{
		MoveWindow(xScreen-180,10,rect.Width(),rect.Height());
		m_bMove=TRUE;
	}


	CEdit::OnMouseMove(nFlags, point);
}

BOOL CMyEdit::OnEraseBkgnd(CDC* pDC) 
{
	//取消文字复选
	this->SetSel(0,0);
	
	//设置位图背景
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);

	BITMAP bmp;
	bitmap.GetBitmap(&bmp);

	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);

	dcCompatible.SelectObject(&bitmap);

	CRect rect;
	GetClientRect(&rect);
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&dcCompatible,0,0,SRCCOPY);
	return TRUE;	
	return CEdit::OnEraseBkgnd(pDC);
}

void CMyEdit::OnSetFocus(CWnd* pOldWnd) 
{
	CEdit::OnSetFocus(pOldWnd);
	this->HideCaret();
	// TODO: Add your message handler code here
	
}
