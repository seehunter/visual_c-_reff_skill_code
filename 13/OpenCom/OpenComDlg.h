// OpenComDlg.h : header file
//

#if !defined(AFX_OPENCOMDLG_H__47DFCC43_7AF3_4ED6_A0AE_5E983DA2DD21__INCLUDED_)
#define AFX_OPENCOMDLG_H__47DFCC43_7AF3_4ED6_A0AE_5E983DA2DD21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COpenComDlg dialog

class COpenComDlg : public CDialog
{
// Construction
public:
	COpenComDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COpenComDlg)
	enum { IDD = IDD_OPENCOM_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenComDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
//
	void  OpenCom();
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COpenComDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENCOMDLG_H__47DFCC43_7AF3_4ED6_A0AE_5E983DA2DD21__INCLUDED_)
