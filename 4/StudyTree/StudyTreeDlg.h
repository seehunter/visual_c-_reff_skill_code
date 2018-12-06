// StudyTreeDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CStudyTreeDlg �Ի���
class CStudyTreeDlg : public CDialog
{
// ����
public:
	CStudyTreeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_STUDYTREE_DIALOG };

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
private:
	CTreeCtrl m_TreeCtrl;

	CImageList Cil1;
	CImageList Cil2;//��Сͼ�����б�


public:
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedSror();
	afx_msg void OnBnClickedLook();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTvnEndlabeleditTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult);
};
