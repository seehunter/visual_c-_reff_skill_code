// ProtectPasswordDlg.h : ͷ�ļ�
//

#pragma once
#include "passwordedit.h"


// CProtectPasswordDlg �Ի���
class CProtectPasswordDlg : public CDialog
{
// ����
public:
	CProtectPasswordDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PROTECTPASSWORD_DIALOG };

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
	CPasswordEdit m_Author;

	CPasswordEdit m_Password;
	afx_msg void OnBnClickedOk();
};
