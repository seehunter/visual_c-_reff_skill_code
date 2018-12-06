// HookDlgDlg.h : header file
//

#if !defined(AFX_HOOKDLGDLG_H__14ACBA5C_B5F0_4893_97A2_4A499AEF4A5D__INCLUDED_)
#define AFX_HOOKDLGDLG_H__14ACBA5C_B5F0_4893_97A2_4A499AEF4A5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHookDlgDlg dialog

class CHookDlgDlg : public CDialog
{
// Construction
public:
	CHookDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHookDlgDlg)
	enum { IDD = IDD_HOOKDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHookDlgDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHookDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInstallBtn();
	afx_msg void OnUninstallBtn();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOOKDLGDLG_H__14ACBA5C_B5F0_4893_97A2_4A499AEF4A5D__INCLUDED_)
