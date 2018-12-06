#pragma once

#include "Page1.h"
#include "Page2.h"
#include "Page3.h"
// CSheet

class CSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSheet)

public:
	CSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CSheet();

protected:
	DECLARE_MESSAGE_MAP()

public:
	int m_nActiveIndex;

	CString m_Content;

	CPage1 m_page1;
	CPage2 m_page2;
	CPage3 m_page3;

protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
};


