// ViewDoc.h : interface of the CViewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWDOC_H__DCD49437_8C14_434A_AFEF_7C467B4F2DB3__INCLUDED_)
#define AFX_VIEWDOC_H__DCD49437_8C14_434A_AFEF_7C467B4F2DB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CViewDoc : public CDocument
{
protected: // create from serialization only
	CViewDoc();
	DECLARE_DYNCREATE(CViewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CViewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWDOC_H__DCD49437_8C14_434A_AFEF_7C467B4F2DB3__INCLUDED_)
