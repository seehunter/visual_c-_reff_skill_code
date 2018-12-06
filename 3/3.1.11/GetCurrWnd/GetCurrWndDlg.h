// GetCurrWndDlg.h : header file
//

#if !defined(AFX_GETCURRWNDDLG_H__A1673F4A_49C0_4889_A0AD_2661CE71E5ED__INCLUDED_)
#define AFX_GETCURRWNDDLG_H__A1673F4A_49C0_4889_A0AD_2661CE71E5ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetCurrWndDlg dialog

class CGetCurrWndDlg : public CDialog
{
// Construction
public:
	CGetCurrWndDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetCurrWndDlg)
	enum { IDD = IDD_GETCURRWND_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetCurrWndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetCurrWndDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETCURRWNDDLG_H__A1673F4A_49C0_4889_A0AD_2661CE71E5ED__INCLUDED_)
