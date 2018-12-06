// GetHostIPDlg.h : header file
//

#if !defined(AFX_GETHOSTIPDLG_H__E3D979A4_3DE3_48F4_AF3E_1D3B2597A863__INCLUDED_)
#define AFX_GETHOSTIPDLG_H__E3D979A4_3DE3_48F4_AF3E_1D3B2597A863__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetHostIPDlg dialog

class CGetHostIPDlg : public CDialog
{
// Construction
public:
	CGetHostIPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetHostIPDlg)
	enum { IDD = IDD_GETHOSTIP_DIALOG };
	CString	m_strName;
	CString	m_strIP;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetHostIPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
// Implementation
	protected:
	int StartUp();
	int CleanUp();
	int GetLocalHostName(CString& sHostName);
	int GetIPAddress(const CString& sHostName, CString& sIPAddress);
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetHostIPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETHOSTIPDLG_H__E3D979A4_3DE3_48F4_AF3E_1D3B2597A863__INCLUDED_)
