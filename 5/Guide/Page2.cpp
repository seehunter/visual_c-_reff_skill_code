// Page2.cpp : 实现文件
//

#include "stdafx.h"
#include "Guide.h"
#include "Page2.h"
#include ".\page2.h"


// CPage2 对话框

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


// CPage2 消息处理程序

BOOL CPage2::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类

	( ( CPropertySheet* ) GetParent())->SetWizardButtons(PSWIZB_NEXT | PSWIZB_BACK);

	return CPropertyPage::OnSetActive();
}

LRESULT CPage2::OnWizardNext()
{
	// TODO: 在此添加专用代码和/或调用基类

	CString name = "";

	GetDlgItem(IDC_COM_AREA)->GetWindowText(name);

	if( name == "" ){

		MessageBox("请输入单位地点！", "信息提示窗口", MB_OK);

		return -1;
	}

	return CPropertyPage::OnWizardNext();
}
