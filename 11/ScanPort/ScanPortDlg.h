// ScanPortDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CScanPortDlg �Ի���
class CScanPortDlg : public CDialog
{
// ����
public:
	CScanPortDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SCANPORT_DIALOG };

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
	CListCtrl m_ListCtrl;
	afx_msg void OnBnClickedScan();

	BOOL ScanPort(CString, int);
	
};
