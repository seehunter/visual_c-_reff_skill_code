// StudyTreeDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// CStudyTreeDlg 对话框
class CStudyTreeDlg : public CDialog
{
// 构造
public:
	CStudyTreeDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_STUDYTREE_DIALOG };

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
private:
	CTreeCtrl m_TreeCtrl;

	CImageList Cil1;
	CImageList Cil2;//大小图标像列表


public:
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedSror();
	afx_msg void OnBnClickedLook();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTvnEndlabeleditTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult);
};
