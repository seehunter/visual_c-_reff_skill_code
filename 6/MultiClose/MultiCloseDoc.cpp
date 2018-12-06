// MultiCloseDoc.cpp : implementation of the CMultiCloseDoc class
//

#include "stdafx.h"
#include "MultiClose.h"

#include "MultiCloseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiCloseDoc

IMPLEMENT_DYNCREATE(CMultiCloseDoc, CDocument)

BEGIN_MESSAGE_MAP(CMultiCloseDoc, CDocument)
	//{{AFX_MSG_MAP(CMultiCloseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiCloseDoc construction/destruction

CMultiCloseDoc::CMultiCloseDoc()
{
	// TODO: add one-time construction code here

}

CMultiCloseDoc::~CMultiCloseDoc()
{
}

BOOL CMultiCloseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMultiCloseDoc serialization

void CMultiCloseDoc::Serialize(CArchive& ar)
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
// CMultiCloseDoc diagnostics

#ifdef _DEBUG
void CMultiCloseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMultiCloseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultiCloseDoc commands
