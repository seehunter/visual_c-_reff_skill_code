// GetMACDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CGetMACDlg �Ի���
class CGetMACDlg : public CDialog
{
// ����
public:
	CGetMACDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GETMAC_DIALOG };

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
	afx_msg void OnBnClickedGetmac();

	void GetOneMac(int);
	CListCtrl m_ListMacs;
};