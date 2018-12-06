// MultipleDocumentView.h : interface of the CMultipleDocumentView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTIPLEDOCUMENTVIEW_H__FA27AE0C_271D_4AFA_B499_F859BCA00E75__INCLUDED_)
#define AFX_MULTIPLEDOCUMENTVIEW_H__FA27AE0C_271D_4AFA_B499_F859BCA00E75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultipleDocumentView : public CView
{
protected: // create from serialization only
	CMultipleDocumentView();
	DECLARE_DYNCREATE(CMultipleDocumentView)

// Attributes
public:
	CMultipleDocumentDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultipleDocumentView)
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
	virtual ~CMultipleDocumentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultipleDocumentView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MultipleDocumentView.cpp
inline CMultipleDocumentDoc* CMultipleDocumentView::GetDocument()
   { return (CMultipleDocumentDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIPLEDOCUMENTVIEW_H__FA27AE0C_271D_4AFA_B499_F859BCA00E75__INCLUDED_)
