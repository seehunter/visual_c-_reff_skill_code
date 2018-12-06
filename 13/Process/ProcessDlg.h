// ProcessDlg.h : header file
//

#if !defined(AFX_PROCESSDLG_H__4FC01A00_F426_46FE_B555_19DFC90279D7__INCLUDED_)
#define AFX_PROCESSDLG_H__4FC01A00_F426_46FE_B555_19DFC90279D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProcessDlg dialog

class CProcessDlg : public CDialog
{
// Construction
public:
	CProcessDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CProcessDlg)
	enum { IDD = IDD_PROCESS_DIALOG };
	CListCtrl	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
public:
    void    ViewProcess();
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CProcessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCESSDLG_H__4FC01A00_F426_46FE_B555_19DFC90279D7__INCLUDED_)
