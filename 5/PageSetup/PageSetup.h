// PageSetup.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CPageSetupApp:
// �йش����ʵ�֣������ PageSetup.cpp
//

class CPageSetupApp : public CWinApp
{
public:
	CPageSetupApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPageSetupApp theApp;
