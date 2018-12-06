// AddNewClsDlg.h : header file
//

#if !defined(AFX_ADDNEWCLSDLG_H__2BA106F8_CE78_4268_8834_1BAA18DCEB5B__INCLUDED_)
#define AFX_ADDNEWCLSDLG_H__2BA106F8_CE78_4268_8834_1BAA18DCEB5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAddNewClsDlg dialog

class CAddNewClsDlg : public CDialog
{
// Construction
public:
	CAddNewClsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAddNewClsDlg)
	enum { IDD = IDD_ADDNEWCLS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddNewClsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAddNewClsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDNEWCLSDLG_H__2BA106F8_CE78_4268_8834_1BAA18DCEB5B__INCLUDED_)
