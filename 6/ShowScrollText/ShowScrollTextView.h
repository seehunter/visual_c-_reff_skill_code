// ShowScrollTextView.h : interface of the CShowScrollTextView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWSCROLLTEXTVIEW_H__746D2FCC_B5A1_4257_917E_50CC63DB6A75__INCLUDED_)
#define AFX_SHOWSCROLLTEXTVIEW_H__746D2FCC_B5A1_4257_917E_50CC63DB6A75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowScrollTextView : public CView
{
protected: // create from serialization only
	CShowScrollTextView();
	DECLARE_DYNCREATE(CShowScrollTextView)

// Attributes
public:
	CShowScrollTextDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowScrollTextView)
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
	virtual ~CShowScrollTextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowScrollTextView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ShowScrollTextView.cpp
inline CShowScrollTextDoc* CShowScrollTextView::GetDocument()
   { return (CShowScrollTextDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWSCROLLTEXTVIEW_H__746D2FCC_B5A1_4257_917E_50CC63DB6A75__INCLUDED_)
