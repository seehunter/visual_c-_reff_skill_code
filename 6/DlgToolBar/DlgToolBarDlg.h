// DlgToolBarDlg.h : header file
//

#if !defined(AFX_DLGTOOLBARDLG_H__C4BC4DEF_548C_457A_8524_D92FBA59647F__INCLUDED_)
#define AFX_DLGTOOLBARDLG_H__C4BC4DEF_548C_457A_8524_D92FBA59647F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgToolBarDlg dialog

class CDlgToolBarDlg : public CDialog
{
// Construction
public:
	CDlgToolBarDlg(CWnd* pParent = NULL);	// standard constructor
    CToolBar   m_wndToolBar; 
// Dialog Data
	//{{AFX_DATA(CDlgToolBarDlg)
	enum { IDD = IDD_DLGTOOLBAR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgToolBarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDlgToolBarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTOOLBARDLG_H__C4BC4DEF_548C_457A_8524_D92FBA59647F__INCLUDED_)
