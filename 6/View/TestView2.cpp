// TestView2.cpp : implementation file
//

#include "stdafx.h"
#include "View.h"
#include "TestView2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestView2

IMPLEMENT_DYNCREATE(CTestView2, CFormView)

CTestView2::CTestView2()
	: CFormView(CTestView2::IDD)
{
	//{{AFX_DATA_INIT(CTestView2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CTestView2::~CTestView2()
{
}

void CTestView2::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestView2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestView2, CFormView)
	//{{AFX_MSG_MAP(CTestView2)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView2 diagnostics

#ifdef _DEBUG
void CTestView2::AssertValid() const
{
	CFormView::AssertValid();
}

void CTestView2::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView2 message handlers
