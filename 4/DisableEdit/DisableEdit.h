// DisableEdit.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CDisableEditApp:
// �йش����ʵ�֣������ DisableEdit.cpp
//

class CDisableEditApp : public CWinApp
{
public:
	CDisableEditApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDisableEditApp theApp;
