//�ļ����� MyEdit.cpp : CMyEdit���ʵ���ļ�
#include "stdafx.h"
#include "Test.h"
#include "MyEdit.h"
IMPLEMENT_DYNAMIC(CMyEdit, CEdit)
CMyEdit::CMyEdit()
{
}
CMyEdit::~CMyEdit()
{
}
BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()
void CMyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (IsCharAlpha((TCHAR)nChar)) 
	{	
		CEdit::OnChar(nChar, nRepCnt, nFlags);
		MessageBox("���������ĸ��","��Ϣ��ʾ",MB_OK);	
	}	
	else
	{
		MessageBox("����������֣�","��Ϣ��ʾ",MB_OK);	
	}
}
