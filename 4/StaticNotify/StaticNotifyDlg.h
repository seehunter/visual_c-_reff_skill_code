// StaticNotifyDlg.h : header file
//

#if !defined(AFX_STATICNOTIFYDLG_H__AC8823C2_3E84_4A3E_9CA8_3EEFF5C63EED__INCLUDED_)
#define AFX_STATICNOTIFYDLG_H__AC8823C2_3E84_4A3E_9CA8_3EEFF5C63EED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStaticNotifyDlg dialog

class CStaticNotifyDlg : public CDialog
{
// Construction
public:
	CStaticNotifyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStaticNotifyDlg)
	enum { IDD = IDD_STATICNOTIFY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticNotifyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStaticNotifyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNotifyStatic();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICNOTIFYDLG_H__AC8823C2_3E84_4A3E_9CA8_3EEFF5C63EED__INCLUDED_)
