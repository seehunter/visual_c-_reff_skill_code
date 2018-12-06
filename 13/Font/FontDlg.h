// FontDlg.h : header file
//

#if !defined(AFX_FONTDLG_H__B5AC70FC_3830_431C_A7DB_51D6C063B2FF__INCLUDED_)
#define AFX_FONTDLG_H__B5AC70FC_3830_431C_A7DB_51D6C063B2FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFontDlg dialog
int CALLBACK MyEnumFontProc(ENUMLOGFONTEX* lpelf,NEWTEXTMETRICEX* lpntm,DWORD nFontType,long lParam); 
class CFontDlg : public CDialog
{
// Construction
public:
	CFontDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFontDlg)
	enum { IDD = IDD_FONT_DIALOG };
	CEdit	m_BrowerCtrl;
	CListBox	m_FontNoList;
	CListBox	m_FontStyleList;
	CComboBox	m_WestCtrl;
	CComboBox	m_ChinaCtrl;
	//}}AFX_DATA
private:
	CMapStringToOb   m_MapStrToOb;
	CFont            m_Font;
	CString          m_strFontName;
	CString          m_strFontStyle;
	CString          m_strFontNo;
	int              m_nWeight;
	int              m_nHeight;
	BYTE             m_bItalic;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

private:
	void FillFont();//fill font
    void FillFontStyle();//fill font style
	void FillFontNo();//fill font num...
	void FillBrowerED();
	void SetMyFont();

    
	
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFontDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeChinaCombox();
	afx_msg void OnSelchangeWestCombox();
	afx_msg void OnSelchangeFontStyleList();
	afx_msg void OnSelchangeFontNoList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTDLG_H__B5AC70FC_3830_431C_A7DB_51D6C063B2FF__INCLUDED_)
