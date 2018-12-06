// BrowseFTPFoldersDlg.h : 头文件
//


#include "afxinet.h"
#include "afxcmn.h"

#include "afxtempl.h"

#pragma once


typedef struct FileItem
{
	int nItem;				//在列表框中的索引
	BOOL bDir;				//是否是文件夹
	CString StrFileName;	//文件名
}FILEITEM;


// CBrowseFTPFoldersDlg 对话框
class CBrowseFTPFoldersDlg : public CDialog
{
// 构造
public:
	CBrowseFTPFoldersDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_BROWSEFTPFOLDERS_DIALOG };

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
	afx_msg void OnBnClickedLook();

	CInternetSession* m_pIntSession;
	CFtpConnection* m_pFTPConnection;

	void BrowseFolder(CString, CListCtrl* , CFileFind* , CArray<FILEITEM, FILEITEM&>* );
	void AddItem(CListCtrl* , int , BOOL , CString );
	CListCtrl m_ListCtrl;

	CFtpFileFind* m_pRemoteFinder;
	CArray<FILEITEM,FILEITEM&>m_ArrayRemoteFiles;
};
