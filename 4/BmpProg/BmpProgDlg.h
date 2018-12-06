// BmpProgDlg.h : header file
//

#if !defined(AFX_BMPPROGCTRLDEMODLG_H__36BCF966_198F_4023_AD94_146D78E1C9DF__INCLUDED_)
#define AFX_BMPPROGCTRLDEMODLG_H__36BCF966_198F_4023_AD94_146D78E1C9DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "BmpProgCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CBmpProgDlg dialog

class CBmpProgDlg : public CDialog
{
// Construction
public:
	CBmpProgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBmpProgDlg)
	enum { IDD = IDD_BMPPROG_DIALOG };
	CBmpProgCtrl	m_bmpprog;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpProgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBmpProgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGo();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPPROGCTRLDEMODLG_H__36BCF966_198F_4023_AD94_146D78E1C9DF__INCLUDED_)
