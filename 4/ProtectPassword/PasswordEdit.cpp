// PasswordEdit.cpp : ʵ���ļ�
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



// CPasswordEdit ��Ϣ�������


LRESULT CPasswordEdit::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: �ڴ����ר�ô����/����û���

	if( message == WM_GETTEXT || message == EM_GETLINE){

		if( !g_flag){ 

			MessageBox("�Ƿ���ã�", "��Ϣ��ʾ����", MB_OK);
			return -1;
		}else {
			g_flag = FALSE;
		}
	}


	return CEdit::DefWindowProc(message, wParam, lParam);
}
