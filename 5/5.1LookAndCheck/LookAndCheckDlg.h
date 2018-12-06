// LookAndCheckDlg.h : 头文件
//

#pragma once

const WM_FINDREPLACE = ::RegisterWindowMessage(FINDMSGSTRING);


// CLookAndCheckDlg 对话框
class CLookAndCheckDlg : public CDialog
{
// 构造
public:
	CLookAndCheckDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LOOKANDCHECK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LONG OnFindReplace(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLook();
	afx_msg void OnBnClickedReplace();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
