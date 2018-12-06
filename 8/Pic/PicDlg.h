// PicDlg.h : header file
//

#if !defined(AFX_PICDLG_H__D994EBB8_7CD6_488F_BE74_C2BD768C142E__INCLUDED_)
#define AFX_PICDLG_H__D994EBB8_7CD6_488F_BE74_C2BD768C142E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPicDlg dialog
#include "picture.h"
class CPicDlg : public CDialog
{
// Construction
public:
	CPicDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPicDlg)
	enum { IDD = IDD_PIC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
public:
    CPicture  m_Pic;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPicDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICDLG_H__D994EBB8_7CD6_488F_BE74_C2BD768C142E__INCLUDED_)
