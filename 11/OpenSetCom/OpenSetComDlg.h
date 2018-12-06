// OpenSetComDlg.h : 头文件
//

#pragma once
#define MAXBLOCK 4096
#define XON 0x11
#define XOFF 0x13


// COpenSetComDlg 对话框
class COpenSetComDlg : public CDialog
{
// 构造
public:
	COpenSetComDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_OPENSETCOM_DIALOG };

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
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSet();

	volatile HANDLE m_hCom;
};
