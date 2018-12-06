// BackGroundView.h : interface of the CBackGroundView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BACKGROUNDVIEW_H__68DF757C_2868_4D65_9174_9382A699AAA2__INCLUDED_)
#define AFX_BACKGROUNDVIEW_H__68DF757C_2868_4D65_9174_9382A699AAA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBackGroundView : public CView
{
protected: // create from serialization only
	CBackGroundView();
	DECLARE_DYNCREATE(CBackGroundView)

// Attributes
public:
	CBackGroundDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackGroundView)
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
	virtual ~CBackGroundView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBackGroundView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BackGroundView.cpp
inline CBackGroundDoc* CBackGroundView::GetDocument()
   { return (CBackGroundDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKGROUNDVIEW_H__68DF757C_2868_4D65_9174_9382A699AAA2__INCLUDED_)
