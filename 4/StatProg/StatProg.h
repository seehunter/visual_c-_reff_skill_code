// StatProg.h : StatProg Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h�� 
#endif

#include "resource.h"       // ������


// CStatProgApp:
// �йش����ʵ�֣������ StatProg.cpp
//

class CStatProgApp : public CWinApp
{
public:
	CStatProgApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CStatProgApp theApp;
