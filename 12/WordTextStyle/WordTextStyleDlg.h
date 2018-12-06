// WordTextStyleDlg.h : header file
//

#if !defined(AFX_WORDTEXTSTYLEDLG_H__EA1481DC_4A96_4818_8EA1_E4526D6186A1__INCLUDED_)
#define AFX_WORDTEXTSTYLEDLG_H__EA1481DC_4A96_4818_8EA1_E4526D6186A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWordTextStyleDlg dialog
#include "OpWord.h"
#include "SetWordDlg.h"
class CWordTextStyleDlg : public CDialog
{
// Construction
public:
	CWordTextStyleDlg(CWnd* pParent = NULL);	// standard constructor
//Attribute
	COpWord   m_WordFile;
// Dialog Data
	//{{AFX_DATA(CWordTextStyleDlg)
	enum { IDD = IDD_WORDTEXTSTYLE_DIALOG };
	CString	m_Text;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordTextStyleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWordTextStyleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnWriteFileBtn();
	afx_msg void OnSetfileBtn();
	afx_msg void OnSaveBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDTEXTSTYLEDLG_H__EA1481DC_4A96_4818_8EA1_E4526D6186A1__INCLUDED_)
