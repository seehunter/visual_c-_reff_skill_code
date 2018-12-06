// DragTreeDlg.h : header file
//

#if !defined(AFX_DRAGTREEDLG_H__D6EBC405_C56A_43B9_AF67_AB0FCB7C6FBF__INCLUDED_)
#define AFX_DRAGTREEDLG_H__D6EBC405_C56A_43B9_AF67_AB0FCB7C6FBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XTreeCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CDragTreeDlg dialog

class CDragTreeDlg : public CDialog
{
// Construction
public:
	CImageList m_image;
	CDragTreeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDragTreeDlg)
	enum { IDD = IDD_DRAGTREE_DIALOG };
	CXTreeCtrl	m_wndTree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDragTreeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDragTreeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAGTREEDLG_H__D6EBC405_C56A_43B9_AF67_AB0FCB7C6FBF__INCLUDED_)
