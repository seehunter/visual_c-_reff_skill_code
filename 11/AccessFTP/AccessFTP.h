// AccessFTP.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CAccessFTPApp:
// �йش����ʵ�֣������ AccessFTP.cpp
//

class CAccessFTPApp : public CWinApp
{
public:
	CAccessFTPApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAccessFTPApp theApp;
