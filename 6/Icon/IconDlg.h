// IconDlg.h : header file
//

#if !defined(AFX_ICONDLG_H__4E57916C_0094_481B_9F2A_D9B00BB90D92__INCLUDED_)
#define AFX_ICONDLG_H__4E57916C_0094_481B_9F2A_D9B00BB90D92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIconDlg dialog

class CIconDlg : public CDialog
{
// Construction
public:
	CIconDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CIconDlg)
	enum { IDD = IDD_ICON_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIconDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIconDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetApplicationIcon();
	afx_msg void OnSetApplicationIcon();
	afx_msg void OnLoadIcon();
	afx_msg void OnSystemSalverSet();
	afx_msg void OnGetIconSize();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICONDLG_H__4E57916C_0094_481B_9F2A_D9B00BB90D92__INCLUDED_)
