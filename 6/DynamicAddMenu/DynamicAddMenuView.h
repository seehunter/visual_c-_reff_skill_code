// DynamicAddMenuView.h : interface of the CDynamicAddMenuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYNAMICADDMENUVIEW_H__564711D3_1DFA_42D4_A9B3_61CF9BAFFF0A__INCLUDED_)
#define AFX_DYNAMICADDMENUVIEW_H__564711D3_1DFA_42D4_A9B3_61CF9BAFFF0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDynamicAddMenuView : public CView
{
protected: // create from serialization only
	CDynamicAddMenuView();
	DECLARE_DYNCREATE(CDynamicAddMenuView)

// Attributes
public:
	CDynamicAddMenuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynamicAddMenuView)
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
	virtual ~CDynamicAddMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDynamicAddMenuView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DynamicAddMenuView.cpp
inline CDynamicAddMenuDoc* CDynamicAddMenuView::GetDocument()
   { return (CDynamicAddMenuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMICADDMENUVIEW_H__564711D3_1DFA_42D4_A9B3_61CF9BAFFF0A__INCLUDED_)