// MultipleDocumentDoc.h : interface of the CMultipleDocumentDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTIPLEDOCUMENTDOC_H__4110452E_ED08_4A04_86E5_FF06F8B03EB2__INCLUDED_)
#define AFX_MULTIPLEDOCUMENTDOC_H__4110452E_ED08_4A04_86E5_FF06F8B03EB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultipleDocumentDoc : public CDocument
{
protected: // create from serialization only
	CMultipleDocumentDoc();
	DECLARE_DYNCREATE(CMultipleDocumentDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultipleDocumentDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMultipleDocumentDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultipleDocumentDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIPLEDOCUMENTDOC_H__4110452E_ED08_4A04_86E5_FF06F8B03EB2__INCLUDED_)
