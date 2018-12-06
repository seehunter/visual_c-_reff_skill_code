// DDBView.h : interface of the CDDBView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDBVIEW_H__2179DC61_8D74_41A7_B8CE_856922BC7F7D__INCLUDED_)
#define AFX_DDBVIEW_H__2179DC61_8D74_41A7_B8CE_856922BC7F7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDDBView : public CView
{
protected: // create from serialization only
	CDDBView();
	DECLARE_DYNCREATE(CDDBView)

// Attributes
public:
	CDDBDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDDBView)
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
	virtual ~CDDBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDDBView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DDBView.cpp
inline CDDBDoc* CDDBView::GetDocument()
   { return (CDDBDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDBVIEW_H__2179DC61_8D74_41A7_B8CE_856922BC7F7D__INCLUDED_)
