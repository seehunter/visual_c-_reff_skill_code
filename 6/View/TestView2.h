#if !defined(AFX_TESTVIEW2_H__7F595059_6F53_44D7_A6B7_289B00B3D501__INCLUDED_)
#define AFX_TESTVIEW2_H__7F595059_6F53_44D7_A6B7_289B00B3D501__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestView2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestView2 form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CTestView2 : public CFormView
{
protected:
	CTestView2();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTestView2)

// Form Data
public:
	//{{AFX_DATA(CTestView2)
	enum { IDD = IDD_TEST_VIEW2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestView2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTestView2();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CTestView2)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTVIEW2_H__7F595059_6F53_44D7_A6B7_289B00B3D501__INCLUDED_)
