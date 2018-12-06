// CatchPicDlg.h : header file
//

#if !defined(AFX_CATCHPICDLG_H__3CD0453C_2CBC_433F_B7AD_725650AA7FCA__INCLUDED_)
#define AFX_CATCHPICDLG_H__3CD0453C_2CBC_433F_B7AD_725650AA7FCA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCatchPicDlg dialog

class CCatchPicDlg : public CDialog
{
// Construction
public:
	CCatchPicDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCatchPicDlg)
	enum { IDD = IDD_CATCHPIC_DIALOG };
	int		m_Left;
	int		m_Top;
	int		m_Right;
	int		m_Bottom;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCatchPicDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

public:
	//创建位图结构
	BOOL CreateBitmapInfoStruct(HBITMAP hBmp,PBITMAPINFO& pbmi);
    //创建位图文件
	BOOL CreateBMPFile(LPTSTR pszFile, PBITMAPINFO pbi, HBITMAP hBMP, HDC hDC) ;
	//截取屏幕到位图
	void CopyScreenToBitmap(LPRECT lpRect);
	//定义屏幕的分辨率
	int m_xScreen;
	int m_yScreen;
	//位图句柄
	HBITMAP m_hBitmap;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCatchPicDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCutScreenBtn();
	afx_msg void OnSaveBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CATCHPICDLG_H__3CD0453C_2CBC_433F_B7AD_725650AA7FCA__INCLUDED_)
