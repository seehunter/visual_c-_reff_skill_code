// AnCtrlDlg.h : header file
//

#if !defined(AFX_ANCTRLDLG_H__3585B298_E916_4840_AAC8_5352C629C7D7__INCLUDED_)
#define AFX_ANCTRLDLG_H__3585B298_E916_4840_AAC8_5352C629C7D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAnCtrlDlg dialog

class CAnCtrlDlg : public CDialog
{
// Construction
public:
	CAnCtrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAnCtrlDlg)
	enum { IDD = IDD_ANCTRL_DIALOG };
	CAnimateCtrl	m_Animate;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAnCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartBtn();
	afx_msg void OnPlayBtn();
	afx_msg void OnDirBtn();
	afx_msg void OnStopBtn();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANCTRLDLG_H__3585B298_E916_4840_AAC8_5352C629C7D7__INCLUDED_)
