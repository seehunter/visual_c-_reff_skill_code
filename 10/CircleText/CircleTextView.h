// CircleTextView.h : interface of the CCircleTextView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIRCLETEXTVIEW_H__5A178ED3_6F60_47B7_B3FF_FF4B0D2B3DDA__INCLUDED_)
#define AFX_CIRCLETEXTVIEW_H__5A178ED3_6F60_47B7_B3FF_FF4B0D2B3DDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCircleTextView : public CView
{
protected: // create from serialization only
	CCircleTextView();
	DECLARE_DYNCREATE(CCircleTextView)

// Attributes
public:
	CCircleTextDoc* GetDocument();
public:
	CFont  m_Font;
	int    m_Angle;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCircleTextView)
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
	virtual ~CCircleTextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCircleTextView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CircleTextView.cpp
inline CCircleTextDoc* CCircleTextView::GetDocument()
   { return (CCircleTextDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CIRCLETEXTVIEW_H__5A178ED3_6F60_47B7_B3FF_FF4B0D2B3DDA__INCLUDED_)
