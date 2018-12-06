// ShowScrollTextDoc.h : interface of the CShowScrollTextDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWSCROLLTEXTDOC_H__26A84312_7ACE_4E16_8809_C08B35696C47__INCLUDED_)
#define AFX_SHOWSCROLLTEXTDOC_H__26A84312_7ACE_4E16_8809_C08B35696C47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowScrollTextDoc : public CDocument
{
protected: // create from serialization only
	CShowScrollTextDoc();
	DECLARE_DYNCREATE(CShowScrollTextDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowScrollTextDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowScrollTextDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowScrollTextDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWSCROLLTEXTDOC_H__26A84312_7ACE_4E16_8809_C08B35696C47__INCLUDED_)
