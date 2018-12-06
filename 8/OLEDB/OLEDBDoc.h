// OLEDBDoc.h : interface of the COLEDBDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBDOC_H__AE89A362_66C1_48E0_8B5C_9A939525D699__INCLUDED_)
#define AFX_OLEDBDOC_H__AE89A362_66C1_48E0_8B5C_9A939525D699__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "OLEDBSet.h"


class COLEDBDoc : public CDocument
{
protected: // create from serialization only
	COLEDBDoc();
	DECLARE_DYNCREATE(COLEDBDoc)

// Attributes
public:
	COLEDBSet m_oLEDBSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEDBDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COLEDBDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COLEDBDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBDOC_H__AE89A362_66C1_48E0_8B5C_9A939525D699__INCLUDED_)
