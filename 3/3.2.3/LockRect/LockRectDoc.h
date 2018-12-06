// LockRectDoc.h : interface of the CLockRectDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOCKRECTDOC_H__411B212D_E4DD_45E2_A003_37F5C2B3F7F5__INCLUDED_)
#define AFX_LOCKRECTDOC_H__411B212D_E4DD_45E2_A003_37F5C2B3F7F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLockRectDoc : public CDocument
{
protected: // create from serialization only
	CLockRectDoc();
	DECLARE_DYNCREATE(CLockRectDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLockRectDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLockRectDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLockRectDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOCKRECTDOC_H__411B212D_E4DD_45E2_A003_37F5C2B3F7F5__INCLUDED_)
