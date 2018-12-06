// SystemButtonView.h : interface of the CSystemButtonView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYSTEMBUTTONVIEW_H__527C1AEF_52DF_4AFA_8971_9F06DA90F8CA__INCLUDED_)
#define AFX_SYSTEMBUTTONVIEW_H__527C1AEF_52DF_4AFA_8971_9F06DA90F8CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSystemButtonView : public CView
{
protected: // create from serialization only
	CSystemButtonView();
	DECLARE_DYNCREATE(CSystemButtonView)
public:
	CString  m_strTitle;
// Attributes
public:
	CSystemButtonDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSystemButtonView)
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
	virtual ~CSystemButtonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSystemButtonView)
	afx_msg void OnCloseDisuseable();
	afx_msg void OnMaxDisuseable();
	afx_msg void OnMinDisuseable();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SystemButtonView.cpp
inline CSystemButtonDoc* CSystemButtonView::GetDocument()
   { return (CSystemButtonDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTEMBUTTONVIEW_H__527C1AEF_52DF_4AFA_8971_9F06DA90F8CA__INCLUDED_)
