// ChanColorTextView.h : interface of the CChanColorTextView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHANCOLORTEXTVIEW_H__39969CFA_8B47_43CC_9AC7_A32FF1AF6E16__INCLUDED_)
#define AFX_CHANCOLORTEXTVIEW_H__39969CFA_8B47_43CC_9AC7_A32FF1AF6E16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CChanColorTextView : public CView
{
protected: // create from serialization only
	CChanColorTextView();
	DECLARE_DYNCREATE(CChanColorTextView)

// Attributes
public:
	CChanColorTextDoc* GetDocument();
public:
	COLORREF     m_TextColor;
	int          m_RColor;
	int          m_GColor;
	int          m_bColor;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChanColorTextView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChanColorTextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CChanColorTextView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ChanColorTextView.cpp
inline CChanColorTextDoc* CChanColorTextView::GetDocument()
   { return (CChanColorTextDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANCOLORTEXTVIEW_H__39969CFA_8B47_43CC_9AC7_A32FF1AF6E16__INCLUDED_)
