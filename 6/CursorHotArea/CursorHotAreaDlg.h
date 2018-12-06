// CursorHotAreaDlg.h : header file
//

#if !defined(AFX_CURSORHOTAREADLG_H__A18908AB_1646_4559_919D_D6F2B77473A6__INCLUDED_)
#define AFX_CURSORHOTAREADLG_H__A18908AB_1646_4559_919D_D6F2B77473A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCursorHotAreaDlg dialog

class CCursorHotAreaDlg : public CDialog
{
// Construction
public:
	CCursorHotAreaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCursorHotAreaDlg)
	enum { IDD = IDD_CURSORHOTAREA_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCursorHotAreaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCursorHotAreaDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CURSORHOTAREADLG_H__A18908AB_1646_4559_919D_D6F2B77473A6__INCLUDED_)
