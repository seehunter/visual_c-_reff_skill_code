// TitleBarLetterView.h : interface of the CTitleBarLetterView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TITLEBARLETTERVIEW_H__5B0C2A83_EB2A_4EFB_B7CE_AF46214048DC__INCLUDED_)
#define AFX_TITLEBARLETTERVIEW_H__5B0C2A83_EB2A_4EFB_B7CE_AF46214048DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTitleBarLetterView : public CView
{
protected: // create from serialization only
	CTitleBarLetterView();
	DECLARE_DYNCREATE(CTitleBarLetterView)

// Attributes
public:
	CTitleBarLetterDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTitleBarLetterView)
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
	virtual ~CTitleBarLetterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTitleBarLetterView)
	afx_msg void OnSetTitleLetter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TitleBarLetterView.cpp
inline CTitleBarLetterDoc* CTitleBarLetterView::GetDocument()
   { return (CTitleBarLetterDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TITLEBARLETTERVIEW_H__5B0C2A83_EB2A_4EFB_B7CE_AF46214048DC__INCLUDED_)
