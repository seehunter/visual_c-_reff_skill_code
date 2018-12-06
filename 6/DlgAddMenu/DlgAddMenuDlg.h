// DlgAddMenuDlg.h : header file
//

#if !defined(AFX_DLGADDMENUDLG_H__9573E26A_DF58_47F1_B8EA_FF5CB12D4A82__INCLUDED_)
#define AFX_DLGADDMENUDLG_H__9573E26A_DF58_47F1_B8EA_FF5CB12D4A82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgAddMenuDlg dialog

class CDlgAddMenuDlg : public CDialog
{
// Construction
public:
	CDlgAddMenuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgAddMenuDlg)
	enum { IDD = IDD_DLGADDMENU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAddMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDlgAddMenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADDMENUDLG_H__9573E26A_DF58_47F1_B8EA_FF5CB12D4A82__INCLUDED_)
