// ADODlg.h : header file
//

#if !defined(AFX_ADODLG_H__F7862C36_5E3B_4F27_BED5_0F68C11BC701__INCLUDED_)
#define AFX_ADODLG_H__F7862C36_5E3B_4F27_BED5_0F68C11BC701__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CADODlg dialog

class CADODlg : public CDialog
{
// Construction
public:
	CADODlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CADODlg)
	enum { IDD = IDD_ADO_DIALOG };
	CString	m_strName;
	CString	m_strSex;
	int		m_nAge;
	int		m_nGrade;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADODlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
public:
    _ConnectionPtr    m_pConnection;
	_RecordsetPtr     m_pRecordset;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CADODlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFirst();
	afx_msg void OnPrev();
	afx_msg void OnNext();
	afx_msg void OnLast();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODLG_H__F7862C36_5E3B_4F27_BED5_0F68C11BC701__INCLUDED_)
