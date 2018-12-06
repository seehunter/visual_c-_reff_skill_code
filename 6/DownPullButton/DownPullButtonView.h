// DownPullButtonView.h : interface of the CDownPullButtonView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOWNPULLBUTTONVIEW_H__C9ACC9B5_C89A_4856_A0E3_40D17B7FE4BB__INCLUDED_)
#define AFX_DOWNPULLBUTTONVIEW_H__C9ACC9B5_C89A_4856_A0E3_40D17B7FE4BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDownPullButtonView : public CView
{
protected: // create from serialization only
	CDownPullButtonView();
	DECLARE_DYNCREATE(CDownPullButtonView)

// Attributes
public:
	CDownPullButtonDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownPullButtonView)
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
	virtual ~CDownPullButtonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDownPullButtonView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DownPullButtonView.cpp
inline CDownPullButtonDoc* CDownPullButtonView::GetDocument()
   { return (CDownPullButtonDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNPULLBUTTONVIEW_H__C9ACC9B5_C89A_4856_A0E3_40D17B7FE4BB__INCLUDED_)
