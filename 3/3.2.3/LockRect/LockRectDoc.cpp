// LockRectDoc.cpp : implementation of the CLockRectDoc class
//

#include "stdafx.h"
#include "LockRect.h"

#include "LockRectDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLockRectDoc

IMPLEMENT_DYNCREATE(CLockRectDoc, CDocument)

BEGIN_MESSAGE_MAP(CLockRectDoc, CDocument)
	//{{AFX_MSG_MAP(CLockRectDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLockRectDoc construction/destruction

CLockRectDoc::CLockRectDoc()
{
	// TODO: add one-time construction code here

}

CLockRectDoc::~CLockRectDoc()
{
}

BOOL CLockRectDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLockRectDoc serialization

void CLockRectDoc::Serialize(CArchive& ar)
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
// CLockRectDoc diagnostics

#ifdef _DEBUG
void CLockRectDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLockRectDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLockRectDoc commands
