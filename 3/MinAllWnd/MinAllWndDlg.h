// MinAllWndDlg.h : header file
//

#if !defined(AFX_MINALLWNDDLG_H__3F8D53A6_9AA6_4091_86EE_332953E6BC74__INCLUDED_)
#define AFX_MINALLWNDDLG_H__3F8D53A6_9AA6_4091_86EE_332953E6BC74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMinAllWndDlg dialog

class CMinAllWndDlg : public CDialog
{
// Construction
public:
	CMinAllWndDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMinAllWndDlg)
	enum { IDD = IDD_MINALLWND_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMinAllWndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMinAllWndDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMinBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MINALLWNDDLG_H__3F8D53A6_9AA6_4091_86EE_332953E6BC74__INCLUDED_)
