// TitleBarView.h : interface of the CTitleBarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TITLEBARVIEW_H__7A6037CF_6A66_4363_8643_FF23D7AF7F4B__INCLUDED_)
#define AFX_TITLEBARVIEW_H__7A6037CF_6A66_4363_8643_FF23D7AF7F4B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTitleBarView : public CView
{
protected: // create from serialization only
	CTitleBarView();
	DECLARE_DYNCREATE(CTitleBarView)

// Attributes
public:
	CTitleBarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTitleBarView)
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
	virtual ~CTitleBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTitleBarView)
	afx_msg void OnGetTitleHeight();
	afx_msg void OnGetTitleColour();
	afx_msg void OnSetTitleColour();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TitleBarView.cpp
inline CTitleBarDoc* CTitleBarView::GetDocument()
   { return (CTitleBarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TITLEBARVIEW_H__7A6037CF_6A66_4363_8643_FF23D7AF7F4B__INCLUDED_)
