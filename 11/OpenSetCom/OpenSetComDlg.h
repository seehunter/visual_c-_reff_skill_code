// OpenSetComDlg.h : ͷ�ļ�
//

#pragma once
#define MAXBLOCK 4096
#define XON 0x11
#define XOFF 0x13


// COpenSetComDlg �Ի���
class COpenSetComDlg : public CDialog
{
// ����
public:
	COpenSetComDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_OPENSETCOM_DIALOG };

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
	afx_msg void OnBnClickedSet();

	volatile HANDLE m_hCom;
};
