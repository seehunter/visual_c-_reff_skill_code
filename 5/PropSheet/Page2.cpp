// Page2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PropSheet.h"
#include "Page2.h"


// CPage2 �Ի���

IMPLEMENT_DYNAMIC(CPage2, CPropertyPage)
CPage2::CPage2()
	: CPropertyPage(CPage2::IDD)
	, m_Name(_T(""))
{
}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_Name);
}


BEGIN_MESSAGE_MAP(CPage2, CPropertyPage)
END_MESSAGE_MAP()


// CPage2 ��Ϣ�������
