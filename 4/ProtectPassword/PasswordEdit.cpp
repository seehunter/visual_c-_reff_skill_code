// PasswordEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "ProtectPassword.h"
#include "PasswordEdit.h"
#include ".\passwordedit.h"


// CPasswordEdit

IMPLEMENT_DYNAMIC(CPasswordEdit, CEdit)
CPasswordEdit::CPasswordEdit()
{
}

CPasswordEdit::~CPasswordEdit()
{
}


BEGIN_MESSAGE_MAP(CPasswordEdit, CEdit)
END_MESSAGE_MAP()



// CPasswordEdit 消息处理程序


LRESULT CPasswordEdit::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: 在此添加专用代码和/或调用基类

	if( message == WM_GETTEXT || message == EM_GETLINE){

		if( !g_flag){ 

			MessageBox("非法获得！", "信息提示窗口", MB_OK);
			return -1;
		}else {
			g_flag = FALSE;
		}
	}


	return CEdit::DefWindowProc(message, wParam, lParam);
}
