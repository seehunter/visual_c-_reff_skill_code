// FontSetup.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CFontSetupApp:
// �йش����ʵ�֣������ FontSetup.cpp
//

class CFontSetupApp : public CWinApp
{
public:
	CFontSetupApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFontSetupApp theApp;
