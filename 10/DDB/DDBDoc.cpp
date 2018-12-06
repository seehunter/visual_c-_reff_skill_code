// DDBDoc.cpp : implementation of the CDDBDoc class
//

#include "stdafx.h"
#include "DDB.h"

#include "DDBDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDDBDoc

IMPLEMENT_DYNCREATE(CDDBDoc, CDocument)

BEGIN_MESSAGE_MAP(CDDBDoc, CDocument)
	//{{AFX_MSG_MAP(CDDBDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDDBDoc construction/destruction

CDDBDoc::CDDBDoc()
{
	// TODO: add one-time construction code here

}

CDDBDoc::~CDDBDoc()
{
}

BOOL CDDBDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDDBDoc serialization

void CDDBDoc::Serialize(CArchive& ar)
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
// CDDBDoc diagnostics

#ifdef _DEBUG
void CDDBDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDDBDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDDBDoc commands
