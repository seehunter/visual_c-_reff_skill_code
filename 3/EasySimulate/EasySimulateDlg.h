// EasySimulateDlg.h : header file
//

#if !defined(AFX_EASYSIMULATEDLG_H__60FA6A0B_AADB_44C4_8170_F4EC1D09FFB1__INCLUDED_)
#define AFX_EASYSIMULATEDLG_H__60FA6A0B_AADB_44C4_8170_F4EC1D09FFB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEasySimulateDlg dialog

class CEasySimulateDlg : public CDialog
{
// Construction
public:
	CEasySimulateDlg(CWnd* pParent = NULL);	// standard constructor
// Attribute
   int m_nCount;
// Dialog Data
	//{{AFX_DATA(CEasySimulateDlg)
	enum { IDD = IDD_EASYSIMULATE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEasySimulateDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEasySimulateDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStartBtn();
	afx_msg void OnSnedBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EASYSIMULATEDLG_H__60FA6A0B_AADB_44C4_8170_F4EC1D09FFB1__INCLUDED_)
