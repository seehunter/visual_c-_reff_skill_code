// CreateProgress.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CCreateProgressApp:
// �йش����ʵ�֣������ CreateProgress.cpp
//

class CCreateProgressApp : public CWinApp
{
public:
	CCreateProgressApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCreateProgressApp theApp;
