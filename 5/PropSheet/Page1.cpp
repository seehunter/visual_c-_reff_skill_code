// Page1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PropSheet.h"
#include "Page1.h"


// CPage1 �Ի���

IMPLEMENT_DYNAMIC(CPage1, CPropertyPage)
CPage1::CPage1()
	: CPropertyPage(CPage1::IDD)
	, m_Area(_T(""))
{
}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_AREA, m_Area);
}


BEGIN_MESSAGE_MAP(CPage1, CPropertyPage)
END_MESSAGE_MAP()


// CPage1 ��Ϣ�������
