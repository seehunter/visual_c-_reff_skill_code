// ScreenPixDlg.h : header file
//

#if !defined(AFX_SCREENPIXDLG_H__2BE0819D_30F7_4EDE_8908_648E0D23B041__INCLUDED_)
#define AFX_SCREENPIXDLG_H__2BE0819D_30F7_4EDE_8908_648E0D23B041__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CScreenPixDlg dialog

class CScreenPixDlg : public CDialog
{
// Construction
public:
	CScreenPixDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CScreenPixDlg)
	enum { IDD = IDD_SCREENPIX_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScreenPixDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScreenPixDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSetBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCREENPIXDLG_H__2BE0819D_30F7_4EDE_8908_648E0D23B041__INCLUDED_)
