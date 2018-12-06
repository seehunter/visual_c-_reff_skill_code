// Sheet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PropSheet.h"
#include "Sheet.h"
#include ".\sheet.h"


// CSheet

IMPLEMENT_DYNAMIC(CSheet, CPropertySheet)
CSheet::CSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

	AddPage(&m_page1);
	AddPage(&m_page2);
	AddPage(&m_page3);

	m_nActiveIndex = 0;

	m_Content = "";

}

CSheet::CSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

	AddPage(&m_page1);
	AddPage(&m_page2);
	AddPage(&m_page3);

	m_nActiveIndex = 0;

	m_Content = "";

}

CSheet::~CSheet()
{
}


BEGIN_MESSAGE_MAP(CSheet, CPropertySheet)
END_MESSAGE_MAP()


// CSheet ��Ϣ�������

BOOL CSheet::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: �ڴ����ר�ô����/����û���

	 if((int)LOWORD(wParam)==IDOK){   
		 m_nActiveIndex = GetActiveIndex();
	 }   


	return CPropertySheet::OnCommand(wParam, lParam);
}
