// TestView3.cpp : implementation file
//

#include "stdafx.h"
#include "View.h"
#include "TestView3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestView3

IMPLEMENT_DYNCREATE(CTestView3, CFormView)

CTestView3::CTestView3()
	: CFormView(CTestView3::IDD)
{
	//{{AFX_DATA_INIT(CTestView3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CTestView3::~CTestView3()
{
}

void CTestView3::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestView3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestView3, CFormView)
	//{{AFX_MSG_MAP(CTestView3)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView3 diagnostics

#ifdef _DEBUG
void CTestView3::AssertValid() const
{
	CFormView::AssertValid();
}

void CTestView3::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView3 message handlers
