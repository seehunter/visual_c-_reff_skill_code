// Page3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Guide.h"
#include "Page3.h"
#include ".\page3.h"


// CPage3 �Ի���

IMPLEMENT_DYNAMIC(CPage3, CPropertyPage)
CPage3::CPage3()
	: CPropertyPage(CPage3::IDD)
	, m_ComTrade(_T(""))
{
}

CPage3::~CPage3()
{
}

void CPage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COM_TRADE, m_ComTrade);
}


BEGIN_MESSAGE_MAP(CPage3, CPropertyPage)
END_MESSAGE_MAP()


// CPage3 ��Ϣ�������

LRESULT CPage3::OnWizardNext()
{
	// TODO: �ڴ����ר�ô����/����û���

	CString trade = "";

	GetDlgItem(IDC_COM_TRADE)->GetWindowText(trade);

	if( trade == "" ){

		MessageBox("�����뵥λ��ҵ��", "��Ϣ��ʾ����", MB_OK);

		return -1;
	}

	return CPropertyPage::OnWizardNext();
}

BOOL CPage3::OnSetActive()
{
	// TODO: �ڴ����ר�ô����/����û���

	( ( CPropertySheet* ) GetParent())->SetWizardButtons(PSWIZB_FINISH | PSWIZB_BACK);

	return CPropertyPage::OnSetActive();
}
