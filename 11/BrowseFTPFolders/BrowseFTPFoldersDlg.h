// BrowseFTPFoldersDlg.h : ͷ�ļ�
//


#include "afxinet.h"
#include "afxcmn.h"

#include "afxtempl.h"

#pragma once


typedef struct FileItem
{
	int nItem;				//���б���е�����
	BOOL bDir;				//�Ƿ����ļ���
	CString StrFileName;	//�ļ���
}FILEITEM;


// CBrowseFTPFoldersDlg �Ի���
class CBrowseFTPFoldersDlg : public CDialog
{
// ����
public:
	CBrowseFTPFoldersDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BROWSEFTPFOLDERS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
