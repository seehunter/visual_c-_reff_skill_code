// MiniCADView.h : interface of the CMiniCADView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MINICADVIEW_H__E386E2ED_69E5_42FF_916C_23CBB9E0B716__INCLUDED_)
#define AFX_MINICADVIEW_H__E386E2ED_69E5_42FF_916C_23CBB9E0B716__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMiniCADView : public CView
{
protected: // create from serialization only
	CMiniCADView();
	DECLARE_DYNCREATE(CMiniCADView)

// Attributes
public:
	CMiniCADDoc* GetDocument();
public:
	POINT   m_LeftMousePoint;
	POINT   m_PrePointLine;
	POINT   m_CurPointLine;
	POINT   m_RecFirstPoint;//矩形的第一个点
	POINT   m_ArcFirstPoint;
	POINT   m_ArcSecondPoint;
	POINT   m_nArcThirdPoint;
	POINT   m_EllipseFirstPoint;
	POINT   m_FirstCirCirlePoint;

	BOOL    m_bDrawPoint;//是否画点
	BOOL    m_bDrawRectangle;//是否画矩形
	BOOL    m_bDrawCircle;//是否画圆
	BOOL    m_bDrawArc;//是否画狐
	BOOL    m_bDrawPoly;//是否画折线
	BOOL    m_bDrawBezier;//画bizer
	BOOL    m_bDrawLine;//画线
	BOOL    m_bDrawEllipse;//画椭圆
	BOOL    m_bDrawPolyGon;//画多边形

	BOOL    m_bStartDrawLine;
	BOOL    m_bStartDrawRectangle;
	BOOL    m_bStartDrawArc;
	BOOL    m_bStartDrawEllipse;

	CRect   m_ArcRect;
	int     m_nClickTime;





void DrawArc(CDC* pDC, POINT StartPoint, POINT MidPoint, POINT EndPoint);
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMiniCADView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMiniCADView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMiniCADView)
	afx_msg void OnPointBtn();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLineBtn();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRectangleBtn();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnArcBtn();
	afx_msg void OnEllipseBtn();
	afx_msg void OnCircleBtn();
	afx_msg void OnFillrectBtn();
	afx_msg void OnPolygonBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MiniCADView.cpp
inline CMiniCADDoc* CMiniCADView::GetDocument()
   { return (CMiniCADDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MINICADVIEW_H__E386E2ED_69E5_42FF_916C_23CBB9E0B716__INCLUDED_)
