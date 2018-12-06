// MiniCADDoc.h : interface of the CMiniCADDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MINICADDOC_H__C8A5A557_BF44_4512_97A9_301661ABC73E__INCLUDED_)
#define AFX_MINICADDOC_H__C8A5A557_BF44_4512_97A9_301661ABC73E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMiniCADDoc : public CDocument
{
protected: // create from serialization only
	CMiniCADDoc();
	DECLARE_DYNCREATE(CMiniCADDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMiniCADDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMiniCADDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMiniCADDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MINICADDOC_H__C8A5A557_BF44_4512_97A9_301661ABC73E__INCLUDED_)
