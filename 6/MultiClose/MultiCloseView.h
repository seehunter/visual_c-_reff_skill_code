// MultiCloseView.h : interface of the CMultiCloseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTICLOSEVIEW_H__1945DC97_4EDE_4A54_8C4E_E4403ED8174B__INCLUDED_)
#define AFX_MULTICLOSEVIEW_H__1945DC97_4EDE_4A54_8C4E_E4403ED8174B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultiCloseView : public CView
{
protected: // create from serialization only
	CMultiCloseView();
	DECLARE_DYNCREATE(CMultiCloseView)

// Attributes
public:
	CMultiCloseDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiCloseView)
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
	virtual ~CMultiCloseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultiCloseView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MultiCloseView.cpp
inline CMultiCloseDoc* CMultiCloseView::GetDocument()
   { return (CMultiCloseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTICLOSEVIEW_H__1945DC97_4EDE_4A54_8C4E_E4403ED8174B__INCLUDED_)
