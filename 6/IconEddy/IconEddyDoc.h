// IconEddyDoc.h : interface of the CIconEddyDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICONEDDYDOC_H__BF49D250_41AE_423B_AEBF_942BCEE16028__INCLUDED_)
#define AFX_ICONEDDYDOC_H__BF49D250_41AE_423B_AEBF_942BCEE16028__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CIconEddyDoc : public CDocument
{
protected: // create from serialization only
	CIconEddyDoc();
	DECLARE_DYNCREATE(CIconEddyDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIconEddyDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIconEddyDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CIconEddyDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICONEDDYDOC_H__BF49D250_41AE_423B_AEBF_942BCEE16028__INCLUDED_)
