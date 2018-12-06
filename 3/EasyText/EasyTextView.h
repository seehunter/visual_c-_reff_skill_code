// EasyTextView.h : interface of the CEasyTextView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EASYTEXTVIEW_H__E4804D83_F7E3_40F6_B14C_7DB0036C48FA__INCLUDED_)
#define AFX_EASYTEXTVIEW_H__E4804D83_F7E3_40F6_B14C_7DB0036C48FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Row.h"
class CEasyTextView : public CView
{
protected: // create from serialization only
	CEasyTextView();
	DECLARE_DYNCREATE(CEasyTextView)
//-------------------------------------------------
public:
// Attributes
	CRowList  m_RowList;
	CString   m_strPre;
	POINT     m_prePoint;
public:
	CEasyTextDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEasyTextView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEasyTextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEasyTextView)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in EasyTextView.cpp
inline CEasyTextDoc* CEasyTextView::GetDocument()
   { return (CEasyTextDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EASYTEXTVIEW_H__E4804D83_F7E3_40F6_B14C_7DB0036C48FA__INCLUDED_)
