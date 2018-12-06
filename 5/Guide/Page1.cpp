// Page1.cpp : 实现文件
//

#include "stdafx.h"
#include "Guide.h"
#include "Page1.h"
#include ".\page1.h"


// CPage1 对话框

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


// CPage1 消息处理程序

BOOL CPage1::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类

	( ( CPropertySheet* ) GetParent())->SetWizardButtons(PSWIZB_NEXT);

	return CPropertyPage::OnSetActive();
}

LRESULT CPage1::OnWizardNext()
{
	// TODO: 在此添加专用代码和/或调用基类

	CString area = "";
	GetDlgItem(IDC_COM_NAME)->GetWindowText(area);

	if( area == "" ){


		MessageBox("请输入你的单位名称！", "信息提示窗口", MB_OK);
		return -1;
	}

	return CPropertyPage::OnWizardNext();
}
