// MiniCAD2Doc.h : interface of the CMiniCAD2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MINICAD2DOC_H__A432FF47_5339_4569_AC8D_BB29820D33EF__INCLUDED_)
#define AFX_MINICAD2DOC_H__A432FF47_5339_4569_AC8D_BB29820D33EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMiniCAD2Doc : public CDocument
{
protected: // create from serialization only
	CMiniCAD2Doc();
	DECLARE_DYNCREATE(CMiniCAD2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMiniCAD2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMiniCAD2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMiniCAD2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MINICAD2DOC_H__A432FF47_5339_4569_AC8D_BB29820D33EF__INCLUDED_)
