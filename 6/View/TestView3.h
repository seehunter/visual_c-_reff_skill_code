#if !defined(AFX_TESTVIEW3_H__E2DCFDA3_05A4_4573_A66F_844BEB06511E__INCLUDED_)
#define AFX_TESTVIEW3_H__E2DCFDA3_05A4_4573_A66F_844BEB06511E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestView3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestView3 form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CTestView3 : public CFormView
{
protected:
	CTestView3();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTestView3)

// Form Data
public:
	//{{AFX_DATA(CTestView3)
	enum { IDD = IDD_TEST_VIEW3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestView3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTestView3();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CTestView3)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTVIEW3_H__E2DCFDA3_05A4_4573_A66F_844BEB06511E__INCLUDED_)
