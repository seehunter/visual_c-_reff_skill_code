//文件名： MyEdit.cpp : CMyEdit类的实现文件
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
		MessageBox("输入的是字母！","信息提示",MB_OK);	
	}	
	else
	{
		MessageBox("输入的是数字！","信息提示",MB_OK);	
	}
}
