// OpenSetCom.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// COpenSetComApp:
// �йش����ʵ�֣������ OpenSetCom.cpp
//

class COpenSetComApp : public CWinApp
{
public:
	COpenSetComApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern COpenSetComApp theApp;
