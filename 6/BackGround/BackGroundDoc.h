// BackGroundDoc.h : interface of the CBackGroundDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BACKGROUNDDOC_H__98496423_E369_4CF8_8071_E7D4C6F44C61__INCLUDED_)
#define AFX_BACKGROUNDDOC_H__98496423_E369_4CF8_8071_E7D4C6F44C61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBackGroundDoc : public CDocument
{
protected: // create from serialization only
	CBackGroundDoc();
	DECLARE_DYNCREATE(CBackGroundDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackGroundDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBackGroundDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBackGroundDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKGROUNDDOC_H__98496423_E369_4CF8_8071_E7D4C6F44C61__INCLUDED_)
