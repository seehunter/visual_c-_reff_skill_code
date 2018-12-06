// EasyFollowDoc.h : interface of the CEasyFollowDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EASYFOLLOWDOC_H__94000B6C_4991_4D44_B04E_F8D0A5E907A1__INCLUDED_)
#define AFX_EASYFOLLOWDOC_H__94000B6C_4991_4D44_B04E_F8D0A5E907A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEasyFollowDoc : public CDocument
{
protected: // create from serialization only
	CEasyFollowDoc();
	DECLARE_DYNCREATE(CEasyFollowDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEasyFollowDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEasyFollowDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEasyFollowDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EASYFOLLOWDOC_H__94000B6C_4991_4D44_B04E_F8D0A5E907A1__INCLUDED_)
