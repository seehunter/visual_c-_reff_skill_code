// RichEditDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CRichEditDlg �Ի���
class CRichEditDlg : public CDialog
{
// ����
public:
	CRichEditDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_RICHEDIT_DIALOG };

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

	CRichEditCtrl pmyRichEditCtrl;
public:
	afx_msg void OnBnClickedOk();
	CRichEditCtrl m_RichEdit;
	afx_msg void OnEnSetfocusRichedit22();
};