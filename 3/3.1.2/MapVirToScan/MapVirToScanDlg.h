// MapVirToScanDlg.h : header file
//

#if !defined(AFX_MAPVIRTOSCANDLG_H__E7F1B810_A068_4299_8F10_D610A2A89E57__INCLUDED_)
#define AFX_MAPVIRTOSCANDLG_H__E7F1B810_A068_4299_8F10_D610A2A89E57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMapVirToScanDlg dialog

class CMapVirToScanDlg : public CDialog
{
// Construction
public:
	CMapVirToScanDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMapVirToScanDlg)
	enum { IDD = IDD_MAPVIRTOSCAN_DIALOG };
	CListBox	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapVirToScanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMapVirToScanDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMapBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPVIRTOSCANDLG_H__E7F1B810_A068_4299_8F10_D610A2A89E57__INCLUDED_)
