// GetLanCompNameDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CGetLanCompNameDlg �Ի���
class CGetLanCompNameDlg : public CDialog
{
// ����
public:
	CGetLanCompNameDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GETLANCOMPNAME_DIALOG };

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
	afx_msg void OnBnClickedGetname();
	CListCtrl m_ListCtrl;

	void FindAllComputer(CStringArray& , CStringArray&);
};
