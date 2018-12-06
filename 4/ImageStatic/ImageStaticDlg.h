// ImageStaticDlg.h : header file
//

#if !defined(AFX_IMAGESTATICDLG_H__570D62C1_05C8_4AFA_9F71_C8E62F843E70__INCLUDED_)
#define AFX_IMAGESTATICDLG_H__570D62C1_05C8_4AFA_9F71_C8E62F843E70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CImageStaticDlg dialog

class CImageStaticDlg : public CDialog
{
// Construction
public:
	CImageStaticDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CImageStaticDlg)
	enum { IDD = IDD_IMAGESTATIC_DIALOG };
	CStatic	m_IconStatic;
	CStatic	m_BitmapStatic;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageStaticDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
public:
	void SetImageStatic();

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CImageStaticDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGESTATICDLG_H__570D62C1_05C8_4AFA_9F71_C8E62F843E70__INCLUDED_)
