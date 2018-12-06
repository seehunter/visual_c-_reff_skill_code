// SetWordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WordTextStyle.h"
#include "SetWordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetWordDlg dialog


CSetWordDlg::CSetWordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetWordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetWordDlg)
	m_Size = 0;
	m_Color = 0;
	//}}AFX_DATA_INIT
}


void CSetWordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetWordDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Size);
	DDX_Text(pDX, IDC_EDIT2, m_Color);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetWordDlg, CDialog)
	//{{AFX_MSG_MAP(CSetWordDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetWordDlg message handlers

void CSetWordDlg::OnOK() 
{
    UpdateData(TRUE);	
	CDialog::OnOK();
}
