// LookAndCheck.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CLookAndCheckApp:
// �йش����ʵ�֣������ LookAndCheck.cpp
//

class CLookAndCheckApp : public CWinApp
{
public:
	CLookAndCheckApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLookAndCheckApp theApp;
