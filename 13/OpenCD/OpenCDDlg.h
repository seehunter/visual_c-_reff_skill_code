// OpenCDDlg.h : header file
//

#if !defined(AFX_OPENCDDLG_H__1ABB169F_B623_421B_A736_D7C272E04D14__INCLUDED_)
#define AFX_OPENCDDLG_H__1ABB169F_B623_421B_A736_D7C272E04D14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COpenCDDlg dialog

class COpenCDDlg : public CDialog
{
// Construction
public:
	COpenCDDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COpenCDDlg)
	enum { IDD = IDD_OPENCD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenCDDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COpenCDDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenCd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENCDDLG_H__1ABB169F_B623_421B_A736_D7C272E04D14__INCLUDED_)
