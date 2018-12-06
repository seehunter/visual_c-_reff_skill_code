// StaticBkDlg.h : header file
//

#if !defined(AFX_STATICBKDLG_H__878A8F8D_67E4_401E_9508_2342F456BC9D__INCLUDED_)
#define AFX_STATICBKDLG_H__878A8F8D_67E4_401E_9508_2342F456BC9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStaticBkDlg dialog

class CStaticBkDlg : public CDialog
{
// Construction
public:
	CStaticBkDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStaticBkDlg)
	enum { IDD = IDD_STATICBK_DIALOG };
	CStatic	m_Static;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticBkDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStaticBkDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnModiBkBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICBKDLG_H__878A8F8D_67E4_401E_9508_2342F456BC9D__INCLUDED_)
