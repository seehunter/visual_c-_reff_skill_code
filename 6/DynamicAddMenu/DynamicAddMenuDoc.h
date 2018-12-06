// DynamicAddMenuDoc.h : interface of the CDynamicAddMenuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYNAMICADDMENUDOC_H__828E03E0_4D03_4C6B_A4FE_0581C0C1225C__INCLUDED_)
#define AFX_DYNAMICADDMENUDOC_H__828E03E0_4D03_4C6B_A4FE_0581C0C1225C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDynamicAddMenuDoc : public CDocument
{
protected: // create from serialization only
	CDynamicAddMenuDoc();
	DECLARE_DYNCREATE(CDynamicAddMenuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynamicAddMenuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDynamicAddMenuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDynamicAddMenuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMICADDMENUDOC_H__828E03E0_4D03_4C6B_A4FE_0581C0C1225C__INCLUDED_)
