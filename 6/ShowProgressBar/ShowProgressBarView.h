// ShowProgressBarView.h : interface of the CShowProgressBarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWPROGRESSBARVIEW_H__FF0A85AA_0C96_4233_A9CD_496BE710EE77__INCLUDED_)
#define AFX_SHOWPROGRESSBARVIEW_H__FF0A85AA_0C96_4233_A9CD_496BE710EE77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowProgressBarView : public CEditView
{
protected: // create from serialization only
	CShowProgressBarView();
	DECLARE_DYNCREATE(CShowProgressBarView)

// Attributes
public:
	CShowProgressBarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowProgressBarView)
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
	virtual ~CShowProgressBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowProgressBarView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ShowProgressBarView.cpp
inline CShowProgressBarDoc* CShowProgressBarView::GetDocument()
   { return (CShowProgressBarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWPROGRESSBARVIEW_H__FF0A85AA_0C96_4233_A9CD_496BE710EE77__INCLUDED_)
