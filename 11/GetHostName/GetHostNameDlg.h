// GetHostNameDlg.h : header file
//

#if !defined(AFX_GETHOSTNAMEDLG_H__0F5CE663_446F_46A6_AD07_8E04376DF370__INCLUDED_)
#define AFX_GETHOSTNAMEDLG_H__0F5CE663_446F_46A6_AD07_8E04376DF370__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetHostNameDlg dialog

class CGetHostNameDlg : public CDialog
{
// Construction
public:
	CGetHostNameDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetHostNameDlg)
	enum { IDD = IDD_GETHOSTNAME_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetHostNameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
   int StartUp();
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetHostNameDlg)
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

#endif // !defined(AFX_GETHOSTNAMEDLG_H__0F5CE663_446F_46A6_AD07_8E04376DF370__INCLUDED_)
