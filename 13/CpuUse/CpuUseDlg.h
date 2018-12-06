// CpuUseDlg.h : header file
//

#if !defined(AFX_CPUUSEDLG_H__A6FBA76B_DE0A_4225_83AD_A4F95A2CEF36__INCLUDED_)
#define AFX_CPUUSEDLG_H__A6FBA76B_DE0A_4225_83AD_A4F95A2CEF36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCpuUseDlg dialog

class CCpuUseDlg : public CDialog
{
// Construction
public:
	CCpuUseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCpuUseDlg)
	enum { IDD = IDD_CPUUSE_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCpuUseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
void GetCpuUsgesNt();
void DrawCpuUsges();
	unsigned long	m_fNewUsges;
	LARGE_INTEGER   m_liOldIdleTime;
    LARGE_INTEGER   m_liOldSystemTime;
		COLORREF        m_LableColor;
	COLORREF		m_ForeFontColor;
	COLORREF		m_ForeColor;
	COLORREF		m_BackColor;
	COLORREF		m_FreeColor;
	COLORREF		m_UsedColor;
	int				m_iGridHeight;
	int				m_iGridCount;
	int				m_iRefreshInterval;
// Implementation
protected:
	HICON m_hIcon;

	//{{AFX_MSG(CCpuUseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetBtn();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPUUSEDLG_H__A6FBA76B_DE0A_4225_83AD_A4F95A2CEF36__INCLUDED_)
