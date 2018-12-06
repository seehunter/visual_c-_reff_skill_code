// BmpButtonDlg.h : header file
//

#if !defined(AFX_BMPBUTTONDLG_H__5DEEC754_48F4_4FBF_B7B1_68534640088E__INCLUDED_)
#define AFX_BMPBUTTONDLG_H__5DEEC754_48F4_4FBF_B7B1_68534640088E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBmpButtonDlg dialog
#include "MyButton.h"
class CBmpButtonDlg : public CDialog
{
// Construction
public:
	CBmpButtonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBmpButtonDlg)
	enum { IDD = IDD_BMPBUTTON_DIALOG };
	CMyButton	m_BmpBtn;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
public:
	HBITMAP  m_hBmp1;
	HBITMAP  m_hBmp2;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBmpButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPBUTTONDLG_H__5DEEC754_48F4_4FBF_B7B1_68534640088E__INCLUDED_)
