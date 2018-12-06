// TitleBarDoc.h : interface of the CTitleBarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TITLEBARDOC_H__BAA5B7DF_9F4C_4CF0_9E60_93BB8195B368__INCLUDED_)
#define AFX_TITLEBARDOC_H__BAA5B7DF_9F4C_4CF0_9E60_93BB8195B368__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTitleBarDoc : public CDocument
{
protected: // create from serialization only
	CTitleBarDoc();
	DECLARE_DYNCREATE(CTitleBarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTitleBarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTitleBarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTitleBarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TITLEBARDOC_H__BAA5B7DF_9F4C_4CF0_9E60_93BB8195B368__INCLUDED_)
