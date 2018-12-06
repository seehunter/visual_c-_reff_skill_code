// TitleBarDoc.cpp : implementation of the CTitleBarDoc class
//

#include "stdafx.h"
#include "TitleBar.h"

#include "TitleBarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTitleBarDoc

IMPLEMENT_DYNCREATE(CTitleBarDoc, CDocument)

BEGIN_MESSAGE_MAP(CTitleBarDoc, CDocument)
	//{{AFX_MSG_MAP(CTitleBarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTitleBarDoc construction/destruction

CTitleBarDoc::CTitleBarDoc()
{
	// TODO: add one-time construction code here

}

CTitleBarDoc::~CTitleBarDoc()
{
}

BOOL CTitleBarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTitleBarDoc serialization

void CTitleBarDoc::Serialize(CArchive& ar)
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
// CTitleBarDoc diagnostics

#ifdef _DEBUG
void CTitleBarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTitleBarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTitleBarDoc commands
