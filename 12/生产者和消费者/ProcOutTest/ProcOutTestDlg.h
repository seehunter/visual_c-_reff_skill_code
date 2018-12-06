// ProcOutTestDlg.h : header file
//

#if !defined(AFX_PROCOUTTESTDLG_H__342E9EF6_3CBF_4F5C_9793_435A28611073__INCLUDED_)
#define AFX_PROCOUTTESTDLG_H__342E9EF6_3CBF_4F5C_9793_435A28611073__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProcOutTestDlg dialog
#define _WIN32_DCOM
#include "ProcOut.h" 

class CProcOutTestDlg : public CDialog
{
// Construction
public:
	CProcOutTestDlg(CWnd* pParent = NULL);	// standard constructor
public:
	IUnknown*  m_pUnkown;
	IObject*   m_pObject;
// Dialog Data
	//{{AFX_DATA(CProcOutTestDlg)
	enum { IDD = IDD_PROCOUTTEST_DIALOG };
	double	m_Num;
	double	m_Cur;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcOutTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CProcOutTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnProduceBtn();
	afx_msg void OnCustomerBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCOUTTESTDLG_H__342E9EF6_3CBF_4F5C_9793_435A28611073__INCLUDED_)
