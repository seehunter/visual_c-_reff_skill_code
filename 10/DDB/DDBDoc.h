// DDBDoc.h : interface of the CDDBDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDBDOC_H__D8EEFB77_C650_4119_A4C0_AB7AE29154C1__INCLUDED_)
#define AFX_DDBDOC_H__D8EEFB77_C650_4119_A4C0_AB7AE29154C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDDBDoc : public CDocument
{
protected: // create from serialization only
	CDDBDoc();
	DECLARE_DYNCREATE(CDDBDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDDBDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDDBDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDDBDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDBDOC_H__D8EEFB77_C650_4119_A4C0_AB7AE29154C1__INCLUDED_)
