// JpgViewView.h : interface of the CJpgViewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JPGVIEWVIEW_H__1DFD22A9_99B5_4C75_A3E8_8D3587887328__INCLUDED_)
#define AFX_JPGVIEWVIEW_H__1DFD22A9_99B5_4C75_A3E8_8D3587887328__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CJpgViewView : public CView
{
protected: // create from serialization only
	CJpgViewView();
	DECLARE_DYNCREATE(CJpgViewView)

// Attributes
public:
	CJpgViewDoc* GetDocument();
public:
	IPicture*   m_pIPic;
	IStream*    m_pIStream;
	CString     m_strFilePath;
	BOOL        m_bRender;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJpgViewView)
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
	virtual ~CJpgViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJpgViewView)
	afx_msg void OnFileOpen();
	afx_msg void OnRomote();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in JpgViewView.cpp
inline CJpgViewDoc* CJpgViewView::GetDocument()
   { return (CJpgViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JPGVIEWVIEW_H__1DFD22A9_99B5_4C75_A3E8_8D3587887328__INCLUDED_)
