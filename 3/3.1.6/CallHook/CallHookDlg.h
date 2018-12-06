// CallHookDlg.h : header file
//

#if !defined(AFX_CALLHOOKDLG_H__D09734C5_E82E_439D_83F0_AA7917D5A1AA__INCLUDED_)
#define AFX_CALLHOOKDLG_H__D09734C5_E82E_439D_83F0_AA7917D5A1AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCallHookDlg dialog

class CCallHookDlg : public CDialog
{
// Construction
public:
	CCallHookDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCallHookDlg)
	enum { IDD = IDD_CALLHOOK_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCallHookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCallHookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInstallBtn();
	afx_msg void OnUninstallBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALLHOOKDLG_H__D09734C5_E82E_439D_83F0_AA7917D5A1AA__INCLUDED_)
