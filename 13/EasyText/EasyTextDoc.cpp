// EasyTextDoc.cpp : implementation of the CEasyTextDoc class
//

#include "stdafx.h"
#include "EasyText.h"

#include "EasyTextDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEasyTextDoc

IMPLEMENT_DYNCREATE(CEasyTextDoc, CDocument)

BEGIN_MESSAGE_MAP(CEasyTextDoc, CDocument)
	//{{AFX_MSG_MAP(CEasyTextDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEasyTextDoc construction/destruction

CEasyTextDoc::CEasyTextDoc()
{
	// TODO: add one-time construction code here

}

CEasyTextDoc::~CEasyTextDoc()
{
}

BOOL CEasyTextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEasyTextDoc serialization

void CEasyTextDoc::Serialize(CArchive& ar)
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
// CEasyTextDoc diagnostics

#ifdef _DEBUG
void CEasyTextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEasyTextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEasyTextDoc commands
