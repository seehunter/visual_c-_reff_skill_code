// CircleTextDoc.h : interface of the CCircleTextDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIRCLETEXTDOC_H__86BE004A_35D5_4012_B489_40D1DCD280C8__INCLUDED_)
#define AFX_CIRCLETEXTDOC_H__86BE004A_35D5_4012_B489_40D1DCD280C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCircleTextDoc : public CDocument
{
protected: // create from serialization only
	CCircleTextDoc();
	DECLARE_DYNCREATE(CCircleTextDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCircleTextDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCircleTextDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCircleTextDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CIRCLETEXTDOC_H__86BE004A_35D5_4012_B489_40D1DCD280C8__INCLUDED_)
