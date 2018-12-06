// FontViewerDlg.h : header file
//

#if !defined(AFX_FONTVIEWERDLG_H__616F3B19_8F57_41F6_A991_794156EB3B62__INCLUDED_)
#define AFX_FONTVIEWERDLG_H__616F3B19_8F57_41F6_A991_794156EB3B62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFontViewerDlg dialog
//声明字体回调函数
#include "afxwin.h" 
int CALLBACK MyEnumFontProc(ENUMLOGFONTEX* lpelf,NEWTEXTMETRICEX* lpntm,DWORD nFontType,long lParam);  
class CFontViewerDlg : public CDialog
{
// Construction
public:
	CFontViewerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFontViewerDlg)
	enum { IDD = IDD_FONTVIEWER_DIALOG };
	CListBox	m_FontNoList;
	CListBox	m_FontStyleCtrl;
	CComboBox	m_EngFontCtrl;
	CEdit	m_PreViewCtrl;
	CComboBox	m_ComBoxCtrl;
	CString	m_strEngFont;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontViewerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
//Function
	void  FillFontList();
	void SetMyFont();
	void InitFont();
	void MapFontNo();
//Attribute
	CFont  m_FontStyle;
	CString	m_strFontName;
	CString m_strFontStyle;
	CString m_strFontNo;
	BYTE    m_bItalic;//
	BYTE    m_bBold;//
	int     m_nWeight;
	int     m_nFontNo;
	CMapStringToOb m_MapStrToInt; 
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFontViewerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeFontChinaCombox();
	afx_msg void OnSelchangeFontEngCombox();
	afx_msg void OnSelchangeFontStyleList();
	afx_msg void OnSelchangeFontNoList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTVIEWERDLG_H__616F3B19_8F57_41F6_A991_794156EB3B62__INCLUDED_)
