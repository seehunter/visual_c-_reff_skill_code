// DAODlg.h : header file
//

#if !defined(AFX_DAODLG_H__8BCBEF8D_876F_4792_852D_9D63A1815C60__INCLUDED_)
#define AFX_DAODLG_H__8BCBEF8D_876F_4792_852D_9D63A1815C60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyDB.h"
/////////////////////////////////////////////////////////////////////////////
// CDAODlg dialog

class CDAODlg : public CDialog
{
// Construction
public:
	CDAODlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDAODlg)
	enum { IDD = IDD_DAO_DIALOG };
	CString	m_strName;
	CString	m_strSex;
	CString	m_strAge;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDAODlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
public:
   CMyDB   m_MyDB;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDAODlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAODLG_H__8BCBEF8D_876F_4792_852D_9D63A1815C60__INCLUDED_)
