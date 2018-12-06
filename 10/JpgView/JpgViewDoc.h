// JpgViewDoc.h : interface of the CJpgViewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JPGVIEWDOC_H__8A6449CC_B936_4B6C_9747_C082B61C7B77__INCLUDED_)
#define AFX_JPGVIEWDOC_H__8A6449CC_B936_4B6C_9747_C082B61C7B77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CJpgViewDoc : public CDocument
{
protected: // create from serialization only
	CJpgViewDoc();
	DECLARE_DYNCREATE(CJpgViewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJpgViewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CJpgViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJpgViewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JPGVIEWDOC_H__8A6449CC_B936_4B6C_9747_C082B61C7B77__INCLUDED_)
