// ToolBarView.h : interface of the CToolBarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLBARVIEW_H__A7296E95_67E0_4DE9_A347_6FF1BEC8A2C8__INCLUDED_)
#define AFX_TOOLBARVIEW_H__A7296E95_67E0_4DE9_A347_6FF1BEC8A2C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CToolBarView : public CView
{
protected: // create from serialization only
	CToolBarView();
	DECLARE_DYNCREATE(CToolBarView)

// Attributes
public:
	CToolBarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolBarView)
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
	virtual ~CToolBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CToolBarView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ToolBarView.cpp
inline CToolBarDoc* CToolBarView::GetDocument()
   { return (CToolBarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBARVIEW_H__A7296E95_67E0_4DE9_A347_6FF1BEC8A2C8__INCLUDED_)
