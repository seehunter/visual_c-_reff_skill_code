// ChangeViewSizeView.h : interface of the CChangeViewSizeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHANGEVIEWSIZEVIEW_H__52FCBCF6_7D15_4FD7_B5EE_BFB93DA7C56C__INCLUDED_)
#define AFX_CHANGEVIEWSIZEVIEW_H__52FCBCF6_7D15_4FD7_B5EE_BFB93DA7C56C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CChangeViewSizeView : public CView
{
protected: // create from serialization only
	CChangeViewSizeView();
	DECLARE_DYNCREATE(CChangeViewSizeView)

// Attributes
public:
	CChangeViewSizeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeViewSizeView)
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
	virtual ~CChangeViewSizeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CChangeViewSizeView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ChangeViewSizeView.cpp
inline CChangeViewSizeDoc* CChangeViewSizeView::GetDocument()
   { return (CChangeViewSizeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEVIEWSIZEVIEW_H__52FCBCF6_7D15_4FD7_B5EE_BFB93DA7C56C__INCLUDED_)
