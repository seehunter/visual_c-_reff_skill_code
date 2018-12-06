// MiniCAD2View.h : interface of the CMiniCAD2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MINICAD2VIEW_H__AADEDFAF_2C9C_4127_9B5F_87133EC2ABFD__INCLUDED_)
#define AFX_MINICAD2VIEW_H__AADEDFAF_2C9C_4127_9B5F_87133EC2ABFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum COMMAND{FILL_RECT=1,FILL_POLY,FILL_ELLIPSE,FILL_CIRCLE};

class CMiniCAD2View : public CView
{
protected: // create from serialization only
	CMiniCAD2View();
	DECLARE_DYNCREATE(CMiniCAD2View)

// Attributes
public:
	CMiniCAD2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMiniCAD2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL
public:
	COMMAND  m_CurCommand;//µ±Ç°ÃüÁî
	BOOL     m_bStartFillRect;
	POINT    m_LeftDownFirstPos;//
	POINT    m_LeftUpFirstPos;
	POINT    m_LeftMovePos;

	CBrush   m_Brush;//Ìî³äË¢×Ó
	int      m_nClickTime;
	POINT    m_PolyPoint[256];

// Implementation
public:
	virtual ~CMiniCAD2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMiniCAD2View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFillrectBtn();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnFillpolyBtn();
	afx_msg void OnFillellipseBtn();
	afx_msg void OnFillcircleBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MiniCAD2View.cpp
inline CMiniCAD2Doc* CMiniCAD2View::GetDocument()
   { return (CMiniCAD2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MINICAD2VIEW_H__AADEDFAF_2C9C_4127_9B5F_87133EC2ABFD__INCLUDED_)
