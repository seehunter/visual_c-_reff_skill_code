// ClearRecyDlg.h : header file
//

#if !defined(AFX_CLEARRECYDLG_H__0D5DA224_A3D2_42F4_BAEB_03AED7253E41__INCLUDED_)
#define AFX_CLEARRECYDLG_H__0D5DA224_A3D2_42F4_BAEB_03AED7253E41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClearRecyDlg dialog

class CClearRecyDlg : public CDialog
{
// Construction
public:
	CClearRecyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CClearRecyDlg)
	enum { IDD = IDD_CLEARRECY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClearRecyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClearRecyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClearRecyBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLEARRECYDLG_H__0D5DA224_A3D2_42F4_BAEB_03AED7253E41__INCLUDED_)
