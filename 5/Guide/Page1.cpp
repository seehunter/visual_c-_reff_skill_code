// Page1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Guide.h"
#include "Page1.h"
#include ".\page1.h"


// CPage1 �Ի���

IMPLEMENT_DYNAMIC(CPage1, CPropertyPage)
CPage1::CPage1()
	: CPropertyPage(CPage1::IDD)
	, m_ComName(_T(""))
{
}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COM_NAME, m_ComName);
}


BEGIN_MESSAGE_MAP(CPage1, CPropertyPage)
END_MESSAGE_MAP()


// CPage1 ��Ϣ�������

BOOL CPage1::OnSetActive()
{
	// TODO: �ڴ����ר�ô����/����û���

	( ( CPropertySheet* ) GetParent())->SetWizardButtons(PSWIZB_NEXT);

	return CPropertyPage::OnSetActive();
}

LRESULT CPage1::OnWizardNext()
{
	// TODO: �ڴ����ר�ô����/����û���

	CString area = "";
	GetDlgItem(IDC_COM_NAME)->GetWindowText(area);

	if( area == "" ){


		MessageBox("��������ĵ�λ���ƣ�", "��Ϣ��ʾ����", MB_OK);
		return -1;
	}

	return CPropertyPage::OnWizardNext();
}
