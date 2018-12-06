// ChangeViewSizeDoc.h : interface of the CChangeViewSizeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHANGEVIEWSIZEDOC_H__270C0658_F678_4ADF_93E4_85349E6C6BB6__INCLUDED_)
#define AFX_CHANGEVIEWSIZEDOC_H__270C0658_F678_4ADF_93E4_85349E6C6BB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CChangeViewSizeDoc : public CDocument
{
protected: // create from serialization only
	CChangeViewSizeDoc();
	DECLARE_DYNCREATE(CChangeViewSizeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeViewSizeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChangeViewSizeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CChangeViewSizeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEVIEWSIZEDOC_H__270C0658_F678_4ADF_93E4_85349E6C6BB6__INCLUDED_)
