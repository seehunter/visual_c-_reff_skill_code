// KeyStateDlg.h : header file
//

#if !defined(AFX_KEYSTATEDLG_H__6AB47D4B_479E_497C_AC48_ECE3B34B0011__INCLUDED_)
#define AFX_KEYSTATEDLG_H__6AB47D4B_479E_497C_AC48_ECE3B34B0011__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CKeyStateDlg dialog

class CKeyStateDlg : public CDialog
{
// Construction
public:
	CKeyStateDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CKeyStateDlg)
	enum { IDD = IDD_KEYSTATE_DIALOG };
	CListBox	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyStateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
  BYTE  m_BYTE[256];
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CKeyStateDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCapBtn();
	afx_msg void OnNumBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYSTATEDLG_H__6AB47D4B_479E_497C_AC48_ECE3B34B0011__INCLUDED_)
