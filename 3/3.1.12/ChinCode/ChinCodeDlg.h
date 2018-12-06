// ChinCodeDlg.h : header file
//

#if !defined(AFX_CHINCODEDLG_H__927F7FF3_04B8_463D_A519_784F1E179D81__INCLUDED_)
#define AFX_CHINCODEDLG_H__927F7FF3_04B8_463D_A519_784F1E179D81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChinCodeDlg dialog

class CChinCodeDlg : public CDialog
{
// Construction
public:
	CChinCodeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChinCodeDlg)
	enum { IDD = IDD_CHINCODE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChinCodeDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
CString  m_str;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChinCodeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHINCODEDLG_H__927F7FF3_04B8_463D_A519_784F1E179D81__INCLUDED_)
