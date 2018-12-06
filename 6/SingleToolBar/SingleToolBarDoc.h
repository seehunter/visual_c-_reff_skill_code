// SingleToolBarDoc.h : interface of the CSingleToolBarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLETOOLBARDOC_H__B6396C9A_9614_4E1E_910A_B649B44373E1__INCLUDED_)
#define AFX_SINGLETOOLBARDOC_H__B6396C9A_9614_4E1E_910A_B649B44373E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSingleToolBarDoc : public CDocument
{
protected: // create from serialization only
	CSingleToolBarDoc();
	DECLARE_DYNCREATE(CSingleToolBarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSingleToolBarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSingleToolBarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSingleToolBarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLETOOLBARDOC_H__B6396C9A_9614_4E1E_910A_B649B44373E1__INCLUDED_)
