// Page3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PropSheet.h"
#include "Page3.h"


// CPage3 �Ի���

IMPLEMENT_DYNAMIC(CPage3, CPropertyPage)
CPage3::CPage3()
	: CPropertyPage(CPage3::IDD)
	, m_Sex(_T(""))
{
}

CPage3::~CPage3()
{
}

void CPage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SEX, m_Sex);
}


BEGIN_MESSAGE_MAP(CPage3, CPropertyPage)
END_MESSAGE_MAP()


// CPage3 ��Ϣ�������
