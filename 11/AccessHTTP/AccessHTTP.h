// AccessHTTP.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CAccessHTTPApp:
// �йش����ʵ�֣������ AccessHTTP.cpp
//

class CAccessHTTPApp : public CWinApp
{
public:
	CAccessHTTPApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAccessHTTPApp theApp;
