// LinkFTPDlg.h : ͷ�ļ�
//

#pragma once

#include "afxinet.h"


// CLinkFTPDlg �Ի���
class CLinkFTPDlg : public CDialog
{
// ����
public:
	CLinkFTPDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LINKFTP_DIALOG };

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
	afx_msg void OnBnClickedLink();

	CInternetSession* m_pIntSession;
	CFtpConnection* m_pFTPConnection;
};
