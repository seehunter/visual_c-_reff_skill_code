#pragma once


// CPage3 �Ի���

class CPage3 : public CPropertyPage
{
	DECLARE_DYNAMIC(CPage3)

public:
	CPage3();
	virtual ~CPage3();

// �Ի�������
	enum { IDD = IDD_PAGE3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_Sex;
};