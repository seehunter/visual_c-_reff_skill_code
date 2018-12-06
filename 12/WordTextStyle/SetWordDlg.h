#if !defined(AFX_SETWORDDLG_H__DCEEE95E_28B7_47E9_AEFF_8F3312347C95__INCLUDED_)
#define AFX_SETWORDDLG_H__DCEEE95E_28B7_47E9_AEFF_8F3312347C95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetWordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetWordDlg dialog

class CSetWordDlg : public CDialog
{
// Construction
public:
	CSetWordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetWordDlg)
	enum { IDD = IDD_SET_WORD_DLG };
	int		m_Size;
	int		m_Color;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetWordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetWordDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETWORDDLG_H__DCEEE95E_28B7_47E9_AEFF_8F3312347C95__INCLUDED_)
