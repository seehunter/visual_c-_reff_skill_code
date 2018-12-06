// Page3.cpp : 实现文件
//

#include "stdafx.h"
#include "Guide.h"
#include "Page3.h"
#include ".\page3.h"


// CPage3 对话框

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


// CPage3 消息处理程序

LRESULT CPage3::OnWizardNext()
{
	// TODO: 在此添加专用代码和/或调用基类

	CString trade = "";

	GetDlgItem(IDC_COM_TRADE)->GetWindowText(trade);

	if( trade == "" ){

		MessageBox("请输入单位行业！", "信息提示窗口", MB_OK);

		return -1;
	}

	return CPropertyPage::OnWizardNext();
}

BOOL CPage3::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类

	( ( CPropertySheet* ) GetParent())->SetWizardButtons(PSWIZB_FINISH | PSWIZB_BACK);

	return CPropertyPage::OnSetActive();
}
