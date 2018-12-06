// ODBCDlg.h : header file
//

#if !defined(AFX_ODBCDLG_H__290FDCDE_9EDB_4554_8CDF_0FE3312864B1__INCLUDED_)
#define AFX_ODBCDLG_H__290FDCDE_9EDB_4554_8CDF_0FE3312864B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CODBCDlg dialog

class CODBCDlg : public CDialog
{
// Construction
public:
	CODBCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CODBCDlg)
	enum { IDD = IDD_ODBC_DIALOG };
	CListBox	m_List;
	CString	m_strUserName;
	CString	m_strPassword;
	CString	m_strDescript;
	CString	m_strDataSource;
	CString	m_strDBName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
public:
	void MystrCpy(char* dest,const char* source,const char* source1,const char* source2,const char* source3);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CODBCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreateBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCDLG_H__290FDCDE_9EDB_4554_8CDF_0FE3312864B1__INCLUDED_)
