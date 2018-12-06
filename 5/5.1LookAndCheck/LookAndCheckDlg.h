// LookAndCheckDlg.h : ͷ�ļ�
//

#pragma once

const WM_FINDREPLACE = ::RegisterWindowMessage(FINDMSGSTRING);


// CLookAndCheckDlg �Ի���
class CLookAndCheckDlg : public CDialog
{
// ����
public:
	CLookAndCheckDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LOOKANDCHECK_DIALOG };

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
	afx_msg LONG OnFindReplace(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLook();
	afx_msg void OnBnClickedReplace();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
