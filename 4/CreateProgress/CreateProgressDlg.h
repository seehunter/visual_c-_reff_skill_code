// CreateProgressDlg.h : ͷ�ļ�
//

#pragma once


// CCreateProgressDlg �Ի���
class CCreateProgressDlg : public CDialog
{
// ����
public:
	CCreateProgressDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CREATEPROGRESS_DIALOG };

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
	afx_msg void OnBnClickedOk();

	CProgressCtrl m_myCtrl;

	int m_Step;
	afx_msg void OnBnClickedRun();
};
