// ProtectPassword.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CProtectPasswordApp:
// �йش����ʵ�֣������ ProtectPassword.cpp
//

class CProtectPasswordApp : public CWinApp
{
public:
	CProtectPasswordApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()

public:

	 
};

extern CProtectPasswordApp theApp;
extern BOOL g_flag;