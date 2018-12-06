// SystemVersionDlg.h : header file
//

#if !defined(AFX_SYSTEMVERSIONDLG_H__711A9A34_A193_4203_9469_25F569B6DC8C__INCLUDED_)
#define AFX_SYSTEMVERSIONDLG_H__711A9A34_A193_4203_9469_25F569B6DC8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSystemVersionDlg dialog

class CSystemVersionDlg : public CDialog
{
// Construction
public:
	CSystemVersionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSystemVersionDlg)
	enum { IDD = IDD_SYSTEMVERSION_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSystemVersionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSystemVersionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTEMVERSIONDLG_H__711A9A34_A193_4203_9469_25F569B6DC8C__INCLUDED_)
