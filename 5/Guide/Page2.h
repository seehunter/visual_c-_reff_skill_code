#pragma once


// CPage2 对话框

class CPage2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CPage2)

public:
	CPage2();
	virtual ~CPage2();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_LARGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_ComArea;
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardNext();
};
