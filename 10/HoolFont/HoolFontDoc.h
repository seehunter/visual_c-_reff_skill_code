// HoolFontDoc.h : interface of the CHoolFontDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOOLFONTDOC_H__FAC8BE9A_EA26_4299_A14A_9765075D2261__INCLUDED_)
#define AFX_HOOLFONTDOC_H__FAC8BE9A_EA26_4299_A14A_9765075D2261__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHoolFontDoc : public CDocument
{
protected: // create from serialization only
	CHoolFontDoc();
	DECLARE_DYNCREATE(CHoolFontDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHoolFontDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHoolFontDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHoolFontDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOOLFONTDOC_H__FAC8BE9A_EA26_4299_A14A_9765075D2261__INCLUDED_)
