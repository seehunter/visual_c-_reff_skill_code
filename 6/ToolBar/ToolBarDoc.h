// ToolBarDoc.h : interface of the CToolBarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLBARDOC_H__384ED803_D596_4CEA_A29A_3B7C80348A7D__INCLUDED_)
#define AFX_TOOLBARDOC_H__384ED803_D596_4CEA_A29A_3B7C80348A7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CToolBarDoc : public CDocument
{
protected: // create from serialization only
	CToolBarDoc();
	DECLARE_DYNCREATE(CToolBarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolBarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CToolBarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CToolBarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBARDOC_H__384ED803_D596_4CEA_A29A_3B7C80348A7D__INCLUDED_)
