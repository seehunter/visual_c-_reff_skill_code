// QueryASCIIDlg.h : header file
//

#if !defined(AFX_QUERYASCIIDLG_H__AFD84898_ED98_4A41_84DA_73E1F47306A8__INCLUDED_)
#define AFX_QUERYASCIIDLG_H__AFD84898_ED98_4A41_84DA_73E1F47306A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CQueryASCIIDlg dialog

class CQueryASCIIDlg : public CDialog
{
// Construction
public:
	CQueryASCIIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CQueryASCIIDlg)
	enum { IDD = IDD_QUERYASCII_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQueryASCIIDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CQueryASCIIDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYASCIIDLG_H__AFD84898_ED98_4A41_84DA_73E1F47306A8__INCLUDED_)
