// GetLanCompName.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CGetLanCompNameApp:
// �йش����ʵ�֣������ GetLanCompName.cpp
//

class CGetLanCompNameApp : public CWinApp
{
public:
	CGetLanCompNameApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGetLanCompNameApp theApp;
