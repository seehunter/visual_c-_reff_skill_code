// LinkFTP.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CLinkFTPApp:
// �йش����ʵ�֣������ LinkFTP.cpp
//

class CLinkFTPApp : public CWinApp
{
public:
	CLinkFTPApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLinkFTPApp theApp;
