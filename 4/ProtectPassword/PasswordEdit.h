#pragma once


// CPasswordEdit

class CPasswordEdit : public CEdit
{
	DECLARE_DYNAMIC(CPasswordEdit)

public:
	CPasswordEdit();
	virtual ~CPasswordEdit();

protected:
	DECLARE_MESSAGE_MAP()
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};


