// HoolFontView.h : interface of the CHoolFontView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOOLFONTVIEW_H__5861914B_4DA4_481E_AC17_EF705E4F31B5__INCLUDED_)
#define AFX_HOOLFONTVIEW_H__5861914B_4DA4_481E_AC17_EF705E4F31B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHoolFontView : public CView
{
protected: // create from serialization only
	CHoolFontView();
	DECLARE_DYNCREATE(CHoolFontView)

// Attributes
public:
	CHoolFontDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHoolFontView)
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
	virtual ~CHoolFontView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHoolFontView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HoolFontView.cpp
inline CHoolFontDoc* CHoolFontView::GetDocument()
   { return (CHoolFontDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOOLFONTVIEW_H__5861914B_4DA4_481E_AC17_EF705E4F31B5__INCLUDED_)
