// Adapers.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CAdapersApp:
// �йش����ʵ�֣������ Adapers.cpp
//

class CAdapersApp : public CWinApp
{
public:
	CAdapersApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAdapersApp theApp;
