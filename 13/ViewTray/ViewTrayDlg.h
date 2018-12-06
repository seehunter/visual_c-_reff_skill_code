// ViewTrayDlg.h : header file
//

#if !defined(AFX_VIEWTRAYDLG_H__502EFF0A_85E0_4000_978A_4AF8DE04746D__INCLUDED_)
#define AFX_VIEWTRAYDLG_H__502EFF0A_85E0_4000_978A_4AF8DE04746D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CViewTrayDlg dialog

class CViewTrayDlg : public CDialog
{
// Construction
public:
	CViewTrayDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CViewTrayDlg)
	enum { IDD = IDD_VIEWTRAY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewTrayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CViewTrayDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnViewTrayBtn();
	afx_msg void OnHideTrayBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWTRAYDLG_H__502EFF0A_85E0_4000_978A_4AF8DE04746D__INCLUDED_)
