// DisableEdit.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error 在包含用于 PCH 的此文件之前包含“stdafx.h”
#endif

#include "resource.h"		// 主符号


// CDisableEditApp:
// 有关此类的实现，请参阅 DisableEdit.cpp
//

class CDisableEditApp : public CWinApp
{
public:
	CDisableEditApp();

// 重写
	public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CDisableEditApp theApp;
