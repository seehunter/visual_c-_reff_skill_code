// MultiCloseDoc.h : interface of the CMultiCloseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTICLOSEDOC_H__BDB22867_738E_4333_ADA9_132803C5BB76__INCLUDED_)
#define AFX_MULTICLOSEDOC_H__BDB22867_738E_4333_ADA9_132803C5BB76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultiCloseDoc : public CDocument
{
protected: // create from serialization only
	CMultiCloseDoc();
	DECLARE_DYNCREATE(CMultiCloseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiCloseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMultiCloseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultiCloseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTICLOSEDOC_H__BDB22867_738E_4333_ADA9_132803C5BB76__INCLUDED_)
