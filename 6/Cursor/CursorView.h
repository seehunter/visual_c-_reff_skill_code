// CursorView.h : interface of the CCursorView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CURSORVIEW_H__A541D7CF_30B8_4EF5_ABDD_170662CF0E6F__INCLUDED_)
#define AFX_CURSORVIEW_H__A541D7CF_30B8_4EF5_ABDD_170662CF0E6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCursorView : public CView
{
protected: // create from serialization only
	CCursorView();
	DECLARE_DYNCREATE(CCursorView)

// Attributes
public:
	CCursorDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCursorView)
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
	virtual ~CCursorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCursorView)
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnGetCursorSize();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CursorView.cpp
inline CCursorDoc* CCursorView::GetDocument()
   { return (CCursorDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CURSORVIEW_H__A541D7CF_30B8_4EF5_ABDD_170662CF0E6F__INCLUDED_)
