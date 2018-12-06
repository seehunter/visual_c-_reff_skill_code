// NoClientView.h : interface of the CNoClientView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOCLIENTVIEW_H__1788BCD4_CCC8_4919_81D1_B82CD9760985__INCLUDED_)
#define AFX_NOCLIENTVIEW_H__1788BCD4_CCC8_4919_81D1_B82CD9760985__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNoClientView : public CView
{
protected: // create from serialization only
	CNoClientView();
	DECLARE_DYNCREATE(CNoClientView)

// Attributes
public:
	CNoClientDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoClientView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);

// Implementation
public:
	virtual ~CNoClientView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNoClientView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in NoClientView.cpp
inline CNoClientDoc* CNoClientView::GetDocument()
   { return (CNoClientDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOCLIENTVIEW_H__1788BCD4_CCC8_4919_81D1_B82CD9760985__INCLUDED_)
