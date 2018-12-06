// MultipleDocumentDoc.cpp : implementation of the CMultipleDocumentDoc class
//

#include "stdafx.h"
#include "MultipleDocument.h"

#include "MultipleDocumentDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultipleDocumentDoc

IMPLEMENT_DYNCREATE(CMultipleDocumentDoc, CDocument)

BEGIN_MESSAGE_MAP(CMultipleDocumentDoc, CDocument)
	//{{AFX_MSG_MAP(CMultipleDocumentDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultipleDocumentDoc construction/destruction

CMultipleDocumentDoc::CMultipleDocumentDoc()
{
	// TODO: add one-time construction code here

}

CMultipleDocumentDoc::~CMultipleDocumentDoc()
{
}

BOOL CMultipleDocumentDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMultipleDocumentDoc serialization

void CMultipleDocumentDoc::Serialize(CArchive& ar)
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
// CMultipleDocumentDoc diagnostics

#ifdef _DEBUG
void CMultipleDocumentDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMultipleDocumentDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultipleDocumentDoc commands
