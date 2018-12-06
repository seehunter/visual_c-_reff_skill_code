// CloseStatusBarView.h : interface of the CCloseStatusBarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLOSESTATUSBARVIEW_H__D8554B37_2A09_4873_AD70_CF04F435378C__INCLUDED_)
#define AFX_CLOSESTATUSBARVIEW_H__D8554B37_2A09_4873_AD70_CF04F435378C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCloseStatusBarView : public CView
{
protected: // create from serialization only
	CCloseStatusBarView();
	DECLARE_DYNCREATE(CCloseStatusBarView)

// Attributes
public:
	CCloseStatusBarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCloseStatusBarView)
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
	virtual ~CCloseStatusBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCloseStatusBarView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CloseStatusBarView.cpp
inline CCloseStatusBarDoc* CCloseStatusBarView::GetDocument()
   { return (CCloseStatusBarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOSESTATUSBARVIEW_H__D8554B37_2A09_4873_AD70_CF04F435378C__INCLUDED_)
