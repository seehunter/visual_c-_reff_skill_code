// EasyFollowView.h : interface of the CEasyFollowView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EASYFOLLOWVIEW_H__69186E50_7DF4_49C5_A849_434FC0AD5A44__INCLUDED_)
#define AFX_EASYFOLLOWVIEW_H__69186E50_7DF4_49C5_A849_434FC0AD5A44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEasyFollowView : public CView
{
protected: // create from serialization only
	CEasyFollowView();
	DECLARE_DYNCREATE(CEasyFollowView)

// Attributes
public:
	CEasyFollowDoc* GetDocument();
CPoint  m_CurPoint;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEasyFollowView)
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
	virtual ~CEasyFollowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEasyFollowView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in EasyFollowView.cpp
inline CEasyFollowDoc* CEasyFollowView::GetDocument()
   { return (CEasyFollowDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EASYFOLLOWVIEW_H__69186E50_7DF4_49C5_A849_434FC0AD5A44__INCLUDED_)
