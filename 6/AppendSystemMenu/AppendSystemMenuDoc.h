// AppendSystemMenuDoc.h : interface of the CAppendSystemMenuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_APPENDSYSTEMMENUDOC_H__7CED2517_F461_4BA6_B2C5_DB0ACE9D71D7__INCLUDED_)
#define AFX_APPENDSYSTEMMENUDOC_H__7CED2517_F461_4BA6_B2C5_DB0ACE9D71D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAppendSystemMenuDoc : public CDocument
{
protected: // create from serialization only
	CAppendSystemMenuDoc();
	DECLARE_DYNCREATE(CAppendSystemMenuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAppendSystemMenuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAppendSystemMenuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAppendSystemMenuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APPENDSYSTEMMENUDOC_H__7CED2517_F461_4BA6_B2C5_DB0ACE9D71D7__INCLUDED_)
