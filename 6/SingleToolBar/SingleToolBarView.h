// SingleToolBarView.h : interface of the CSingleToolBarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLETOOLBARVIEW_H__B90643D2_823C_4495_A164_8D7BD89B5015__INCLUDED_)
#define AFX_SINGLETOOLBARVIEW_H__B90643D2_823C_4495_A164_8D7BD89B5015__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSingleToolBarView : public CView
{
protected: // create from serialization only
	CSingleToolBarView();
	DECLARE_DYNCREATE(CSingleToolBarView)

// Attributes
public:
	CSingleToolBarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSingleToolBarView)
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
	virtual ~CSingleToolBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSingleToolBarView)
	afx_msg void OnSetTitle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SingleToolBarView.cpp
inline CSingleToolBarDoc* CSingleToolBarView::GetDocument()
   { return (CSingleToolBarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLETOOLBARVIEW_H__B90643D2_823C_4495_A164_8D7BD89B5015__INCLUDED_)
