// BrowseFTPFolders.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CBrowseFTPFoldersApp:
// �йش����ʵ�֣������ BrowseFTPFolders.cpp
//

class CBrowseFTPFoldersApp : public CWinApp
{
public:
	CBrowseFTPFoldersApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBrowseFTPFoldersApp theApp;
