// DirectoryDlg.h : header file
//

#if !defined(AFX_DIRECTORYDLG_H__F3139831_AD32_479C_840F_F8EACBBE1D84__INCLUDED_)
#define AFX_DIRECTORYDLG_H__F3139831_AD32_479C_840F_F8EACBBE1D84__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDirectoryDlg dialog

class CDirectoryDlg : public CDialog
{
// Construction
public:
	CDirectoryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDirectoryDlg)
	enum { IDD = IDD_DIRECTORY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDirectoryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
   void  GetDirectory();
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDirectoryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIRECTORYDLG_H__F3139831_AD32_479C_840F_F8EACBBE1D84__INCLUDED_)
