// AutoStartDlg.h : header file
//

#if !defined(AFX_AUTOSTARTDLG_H__C4D8DDD2_AD13_47AD_BD89_5A193EBAC258__INCLUDED_)
#define AFX_AUTOSTARTDLG_H__C4D8DDD2_AD13_47AD_BD89_5A193EBAC258__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAutoStartDlg dialog

class CAutoStartDlg : public CDialog
{
// Construction
public:
	CAutoStartDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAutoStartDlg)
	enum { IDD = IDD_AUTOSTART_DIALOG };
	CString	m_filename;
	CString	m_strTitle;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoStartDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAutoStartDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBrowerBtn();
	afx_msg void OnRegBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOSTARTDLG_H__C4D8DDD2_AD13_47AD_BD89_5A193EBAC258__INCLUDED_)
