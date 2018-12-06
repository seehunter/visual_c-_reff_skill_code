// DrawButtonDlg.h : header file
//

#if !defined(AFX_DRAWBUTTONDLG_H__62C0C716_2976_4377_B902_1884B65AA073__INCLUDED_)
#define AFX_DRAWBUTTONDLG_H__62C0C716_2976_4377_B902_1884B65AA073__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDrawButtonDlg dialog

class CDrawButtonDlg : public CDialog
{
// Construction
public:
	CDrawButtonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDrawButtonDlg)
	enum { IDD = IDD_DRAWBUTTON_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
void   DrawMyButton();
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDrawButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWBUTTONDLG_H__62C0C716_2976_4377_B902_1884B65AA073__INCLUDED_)
