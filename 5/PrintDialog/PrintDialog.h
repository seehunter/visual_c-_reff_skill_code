// PrintDialog.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CPrintDialogApp:
// �йش����ʵ�֣������ PrintDialog.cpp
//

class CPrintDialogApp : public CWinApp
{
public:
	CPrintDialogApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPrintDialogApp theApp;
