// OLEDBView.h : interface of the COLEDBView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBVIEW_H__327670BB_1429_412D_8836_0D620A864819__INCLUDED_)
#define AFX_OLEDBVIEW_H__327670BB_1429_412D_8836_0D620A864819__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COLEDBSet;

class COLEDBView : public COleDBRecordView
{
protected: // create from serialization only
	COLEDBView();
	DECLARE_DYNCREATE(COLEDBView)

public:
	//{{AFX_DATA(COLEDBView)
	enum { IDD = IDD_OLEDB_FORM };
	COLEDBSet* m_pSet;
	CString	m_Name;
	CString	m_Sex;
	int		m_Grade;
	int		m_Age;
	//}}AFX_DATA

// Attributes
public:
	COLEDBDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEDBView)
	public:
	virtual CRowset* OnGetRowset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnMove(UINT nIDMoveCommand);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COLEDBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COLEDBView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OLEDBView.cpp
inline COLEDBDoc* COLEDBView::GetDocument()
   { return (COLEDBDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBVIEW_H__327670BB_1429_412D_8836_0D620A864819__INCLUDED_)
