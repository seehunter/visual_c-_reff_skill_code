// Page2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Guide.h"
#include "Page2.h"
#include ".\page2.h"


// CPage2 �Ի���

IMPLEMENT_DYNAMIC(CPage2, CPropertyPage)
CPage2::CPage2()
	: CPropertyPage(CPage2::IDD)
	, m_ComArea(_T(""))
{
}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COM_AREA, m_ComArea);
}


BEGIN_MESSAGE_MAP(CPage2, CPropertyPage)
END_MESSAGE_MAP()


// CPage2 ��Ϣ�������

BOOL CPage2::OnSetActive()
{
	// TODO: �ڴ����ר�ô����/����û���

	( ( CPropertySheet* ) GetParent())->SetWizardButtons(PSWIZB_NEXT | PSWIZB_BACK);

	return CPropertyPage::OnSetActive();
}

LRESULT CPage2::OnWizardNext()
{
	// TODO: �ڴ����ר�ô����/����û���

	CString name = "";

	GetDlgItem(IDC_COM_AREA)->GetWindowText(name);

	if( name == "" ){

		MessageBox("�����뵥λ�ص㣡", "��Ϣ��ʾ����", MB_OK);

		return -1;
	}

	return CPropertyPage::OnWizardNext();
}
