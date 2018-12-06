#if !defined(AFX_MYBUTTON_H__F0DC8FF5_8E36_42FE_B7B5_8AE6B27CB529__INCLUDED_)
#define AFX_MYBUTTON_H__F0DC8FF5_8E36_42FE_B7B5_8AE6B27CB529__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyButton window

class CMyButton : public CButton
{
// Construction
public:
	CMyButton();

// Attributes
public:
   void SetBtnBitmap(HBITMAP hBitmap1,HBITMAP hBitmap2);
public:
	HBITMAP  m_hBmp1;
	HBITMAP  m_hBmp2;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYBUTTON_H__F0DC8FF5_8E36_42FE_B7B5_8AE6B27CB529__INCLUDED_)
