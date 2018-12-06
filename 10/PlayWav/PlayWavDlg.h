// PlayWavDlg.h : header file
//

#if !defined(AFX_PLAYWAVDLG_H__F8477654_2CD7_4831_9B56_2F2C99D6C25D__INCLUDED_)
#define AFX_PLAYWAVDLG_H__F8477654_2CD7_4831_9B56_2F2C99D6C25D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPlayWavDlg dialog
#include <mmsystem.h>
class CPlayWavDlg : public CDialog
{
// Construction
public:
	CPlayWavDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPlayWavDlg)
	enum { IDD = IDD_PLAYWAV_DIALOG };
	CButton	m_CloseBtn;
	CButton	m_StopBtn;
	CButton	m_PreBtn;
	CButton	m_PlayBtn;
	CButton	m_OpenBtn;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayWavDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
public:
	MCIDEVICEID   m_nDeviceID;
	MCIDEVICEID   m_nElementID;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPlayWavDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenBtn();
	afx_msg void OnPlayBtn();
	afx_msg void OnPreBtn();
	afx_msg void OnCloseBtn();
	afx_msg void OnStopBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYWAVDLG_H__F8477654_2CD7_4831_9B56_2F2C99D6C25D__INCLUDED_)
