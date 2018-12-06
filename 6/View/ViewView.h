// ViewView.h : interface of the CViewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWVIEW_H__55A35BDF_58A6_40A4_BE1B_5BEC0E757056__INCLUDED_)
#define AFX_VIEWVIEW_H__55A35BDF_58A6_40A4_BE1B_5BEC0E757056__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CViewView : public CView
{
protected: // create from serialization only
	CViewView();
	DECLARE_DYNCREATE(CViewView)

// Attributes
public:
	CViewDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewView)
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
	virtual ~CViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CViewView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ViewView.cpp
inline CViewDoc* CViewView::GetDocument()
   { return (CViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWVIEW_H__55A35BDF_58A6_40A4_BE1B_5BEC0E757056__INCLUDED_)
