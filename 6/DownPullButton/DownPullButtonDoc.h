// DownPullButtonDoc.h : interface of the CDownPullButtonDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOWNPULLBUTTONDOC_H__C6BA424E_7EBA_4352_BED2_EFF5D66787CE__INCLUDED_)
#define AFX_DOWNPULLBUTTONDOC_H__C6BA424E_7EBA_4352_BED2_EFF5D66787CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDownPullButtonDoc : public CDocument
{
protected: // create from serialization only
	CDownPullButtonDoc();
	DECLARE_DYNCREATE(CDownPullButtonDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownPullButtonDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDownPullButtonDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDownPullButtonDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNPULLBUTTONDOC_H__C6BA424E_7EBA_4352_BED2_EFF5D66787CE__INCLUDED_)
