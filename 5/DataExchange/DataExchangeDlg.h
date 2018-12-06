// DataExchangeDlg.h : header file
//

#if !defined(AFX_DATAEXCHANGEDLG_H__16C99B50_8B8A_4378_A36E_D2D2EFC767B7__INCLUDED_)
#define AFX_DATAEXCHANGEDLG_H__16C99B50_8B8A_4378_A36E_D2D2EFC767B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>
/////////////////////////////////////////////////////////////////////////////
// CDataExchangeDlg dialog
struct stu 
{
   CString  strName;
   int      nAge;
   int      nGrade;
};
class CDataExchangeDlg : public CDialog
{
// Construction
public:
	CDataExchangeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDataExchangeDlg)
	enum { IDD = IDD_DATAEXCHANGE_DIALOG };
	int		m_mAge;
	int		m_nGrade;
	CString	m_strName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataExchangeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
CArray <stu,stu&> m_stu;
int m_nIndex;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDataExchangeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddBtn();
	afx_msg void OnPreBtn();
	afx_msg void OnNextBtn();
	afx_msg void OnInput();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAEXCHANGEDLG_H__16C99B50_8B8A_4378_A36E_D2D2EFC767B7__INCLUDED_)
