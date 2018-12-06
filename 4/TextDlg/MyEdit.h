//文件名： MyEdit.h : CMyEdit类的头文件
#pragma once
class CMyEdit : public CEdit
{
	DECLARE_DYNAMIC(CMyEdit)
public:
	CMyEdit();
	virtual ~CMyEdit();
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};
