// SimuteKeyDlg.h : header file
//

#if !defined(AFX_SIMUTEKEYDLG_H__00576BF4_D89D_46F8_B36D_ADB902B89212__INCLUDED_)
#define AFX_SIMUTEKEYDLG_H__00576BF4_D89D_46F8_B36D_ADB902B89212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSimuteKeyDlg dialog

class CSimuteKeyDlg : public CDialog
{
// Construction
public:
	CSimuteKeyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSimuteKeyDlg)
	enum { IDD = IDD_SIMUTEKEY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimuteKeyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSimuteKeyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSimulateBtn();
	afx_msg void OnSimulateValidBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMUTEKEYDLG_H__00576BF4_D89D_46F8_B36D_ADB902B89212__INCLUDED_)
