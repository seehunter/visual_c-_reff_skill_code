// CloseStatusBarDoc.cpp : implementation of the CCloseStatusBarDoc class
//

#include "stdafx.h"
#include "CloseStatusBar.h"

#include "CloseStatusBarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCloseStatusBarDoc

IMPLEMENT_DYNCREATE(CCloseStatusBarDoc, CDocument)

BEGIN_MESSAGE_MAP(CCloseStatusBarDoc, CDocument)
	//{{AFX_MSG_MAP(CCloseStatusBarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCloseStatusBarDoc construction/destruction

CCloseStatusBarDoc::CCloseStatusBarDoc()
{
	// TODO: add one-time construction code here

}

CCloseStatusBarDoc::~CCloseStatusBarDoc()
{
}

BOOL CCloseStatusBarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCloseStatusBarDoc serialization

void CCloseStatusBarDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCloseStatusBarDoc diagnostics

#ifdef _DEBUG
void CCloseStatusBarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCloseStatusBarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCloseStatusBarDoc commands
