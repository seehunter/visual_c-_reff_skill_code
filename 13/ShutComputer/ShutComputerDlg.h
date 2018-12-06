// ShutComputerDlg.h : header file
//

#if !defined(AFX_SHUTCOMPUTERDLG_H__BAF012A1_5369_4E01_A96F_B68C00DBE23F__INCLUDED_)
#define AFX_SHUTCOMPUTERDLG_H__BAF012A1_5369_4E01_A96F_B68C00DBE23F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShutComputerDlg dialog
class CShutComputerDlg : public CDialog
{
// Construction
public:
	CShutComputerDlg(CWnd* pParent = NULL);	// standard constructor
//orperation
	BOOL             MySystemShutDown();

//Attribute
    CString    m_strResourceTime;
	CBitmap    m_Bmp;
	HBITMAP    m_hBmp;
// Dialog Data
	//{{AFX_DATA(CShutComputerDlg)
	enum { IDD = IDD_SHUTCOMPUTER_DIALOG };
	CStatic	m_cImage;

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShutComputerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShutComputerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnTimeBtn();
	afx_msg LRESULT OnTrayNotification(WPARAM aparam, LPARAM lparam);
	afx_msg void OnBtnTray();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHUTCOMPUTERDLG_H__BAF012A1_5369_4E01_A96F_B68C00DBE23F__INCLUDED_)
