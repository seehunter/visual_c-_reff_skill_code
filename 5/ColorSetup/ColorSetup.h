// ColorSetup.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CColorSetupApp:
// �йش����ʵ�֣������ ColorSetup.cpp
//

class CColorSetupApp : public CWinApp
{
public:
	CColorSetupApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CColorSetupApp theApp;
