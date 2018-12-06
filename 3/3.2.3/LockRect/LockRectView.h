// LockRectView.h : interface of the CLockRectView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOCKRECTVIEW_H__67B6799A_2D65_4EFA_8D22_0EC8857877AD__INCLUDED_)
#define AFX_LOCKRECTVIEW_H__67B6799A_2D65_4EFA_8D22_0EC8857877AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLockRectView : public CView
{
protected: // create from serialization only
	CLockRectView();
	DECLARE_DYNCREATE(CLockRectView)

// Attributes
public:
	CLockRectDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLockRectView)
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
	virtual ~CLockRectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLockRectView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LockRectView.cpp
inline CLockRectDoc* CLockRectView::GetDocument()
   { return (CLockRectDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOCKRECTVIEW_H__67B6799A_2D65_4EFA_8D22_0EC8857877AD__INCLUDED_)
