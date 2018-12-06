// TestView1.cpp : implementation file
//

#include "stdafx.h"
#include "View.h"
#include "TestView1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestView1

IMPLEMENT_DYNCREATE(CTestView1, CFormView)

CTestView1::CTestView1()
	: CFormView(CTestView1::IDD)
{
	//{{AFX_DATA_INIT(CTestView1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CTestView1::~CTestView1()
{
}

void CTestView1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestView1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestView1, CFormView)
	//{{AFX_MSG_MAP(CTestView1)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView1 diagnostics

#ifdef _DEBUG
void CTestView1::AssertValid() const
{
	CFormView::AssertValid();
}

void CTestView1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView1 message handlers
