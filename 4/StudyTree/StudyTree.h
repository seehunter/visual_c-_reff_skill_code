// StudyTree.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CStudyTreeApp:
// �йش����ʵ�֣������ StudyTree.cpp
//

class CStudyTreeApp : public CWinApp
{
public:
	CStudyTreeApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CStudyTreeApp theApp;
