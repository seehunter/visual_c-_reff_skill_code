#if !defined(AFX_TESTVIEW1_H__9EB4D954_CF8D_4D5C_BDB8_FD52AD3BBABD__INCLUDED_)
#define AFX_TESTVIEW1_H__9EB4D954_CF8D_4D5C_BDB8_FD52AD3BBABD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestView1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestView1 form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CTestView1 : public CFormView
{
protected:
	CTestView1();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTestView1)

// Form Data
public:
	//{{AFX_DATA(CTestView1)
	enum { IDD = IDD_TEST_VIEW1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestView1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTestView1();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CTestView1)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTVIEW1_H__9EB4D954_CF8D_4D5C_BDB8_FD52AD3BBABD__INCLUDED_)
