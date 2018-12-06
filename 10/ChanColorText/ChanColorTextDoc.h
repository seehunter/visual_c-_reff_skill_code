// ChanColorTextDoc.h : interface of the CChanColorTextDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHANCOLORTEXTDOC_H__15515619_10E6_4B6D_A2F0_8418FBFE3732__INCLUDED_)
#define AFX_CHANCOLORTEXTDOC_H__15515619_10E6_4B6D_A2F0_8418FBFE3732__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CChanColorTextDoc : public CDocument
{
protected: // create from serialization only
	CChanColorTextDoc();
	DECLARE_DYNCREATE(CChanColorTextDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChanColorTextDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChanColorTextDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CChanColorTextDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANCOLORTEXTDOC_H__15515619_10E6_4B6D_A2F0_8418FBFE3732__INCLUDED_)
