// AppendSystemMenuView.h : interface of the CAppendSystemMenuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_APPENDSYSTEMMENUVIEW_H__6E6C3800_50AA_491A_B219_140CC1E951F4__INCLUDED_)
#define AFX_APPENDSYSTEMMENUVIEW_H__6E6C3800_50AA_491A_B219_140CC1E951F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAppendSystemMenuView : public CView
{
protected: // create from serialization only
	CAppendSystemMenuView();
	DECLARE_DYNCREATE(CAppendSystemMenuView)

// Attributes
public:
	CAppendSystemMenuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAppendSystemMenuView)
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
	virtual ~CAppendSystemMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAppendSystemMenuView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AppendSystemMenuView.cpp
inline CAppendSystemMenuDoc* CAppendSystemMenuView::GetDocument()
   { return (CAppendSystemMenuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APPENDSYSTEMMENUVIEW_H__6E6C3800_50AA_491A_B219_140CC1E951F4__INCLUDED_)
