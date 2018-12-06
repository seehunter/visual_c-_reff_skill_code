// 3DStaticDlg.h : header file
//

#if !defined(AFX_3DSTATICDLG_H__8499608A_F419_4AD9_B486_5D41D3B1A07D__INCLUDED_)
#define AFX_3DSTATICDLG_H__8499608A_F419_4AD9_B486_5D41D3B1A07D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy3DStaticDlg dialog
#include "myStatic.h"
class CMy3DStaticDlg : public CDialog
{
// Construction
public:
	CMy3DStaticDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy3DStaticDlg)
	enum { IDD = IDD_MY3DSTATIC_DIALOG };
//	CStatic	m_ctrl;
	CMyStatic	m_Static;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy3DStaticDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy3DStaticDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_3DSTATICDLG_H__8499608A_F419_4AD9_B486_5D41D3B1A07D__INCLUDED_)
