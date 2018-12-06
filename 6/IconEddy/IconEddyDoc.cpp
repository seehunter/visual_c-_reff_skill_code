// IconEddyDoc.cpp : implementation of the CIconEddyDoc class
//

#include "stdafx.h"
#include "IconEddy.h"

#include "IconEddyDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIconEddyDoc

IMPLEMENT_DYNCREATE(CIconEddyDoc, CDocument)

BEGIN_MESSAGE_MAP(CIconEddyDoc, CDocument)
	//{{AFX_MSG_MAP(CIconEddyDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIconEddyDoc construction/destruction

CIconEddyDoc::CIconEddyDoc()
{
	// TODO: add one-time construction code here

}

CIconEddyDoc::~CIconEddyDoc()
{
}

BOOL CIconEddyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CIconEddyDoc serialization

void CIconEddyDoc::Serialize(CArchive& ar)
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
// CIconEddyDoc diagnostics

#ifdef _DEBUG
void CIconEddyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CIconEddyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIconEddyDoc commands
