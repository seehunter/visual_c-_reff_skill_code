// PropSheet.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CPropSheetApp:
// �йش����ʵ�֣������ PropSheet.cpp
//

class CPropSheetApp : public CWinApp
{
public:
	CPropSheetApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPropSheetApp theApp;
