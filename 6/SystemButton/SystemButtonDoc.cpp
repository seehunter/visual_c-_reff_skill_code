// SystemButtonDoc.cpp : implementation of the CSystemButtonDoc class
//

#include "stdafx.h"
#include "SystemButton.h"

#include "SystemButtonDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSystemButtonDoc

IMPLEMENT_DYNCREATE(CSystemButtonDoc, CDocument)

BEGIN_MESSAGE_MAP(CSystemButtonDoc, CDocument)
	//{{AFX_MSG_MAP(CSystemButtonDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSystemButtonDoc construction/destruction

CSystemButtonDoc::CSystemButtonDoc()
{
	// TODO: add one-time construction code here

}

CSystemButtonDoc::~CSystemButtonDoc()
{
}

BOOL CSystemButtonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSystemButtonDoc serialization

void CSystemButtonDoc::Serialize(CArchive& ar)
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
// CSystemButtonDoc diagnostics

#ifdef _DEBUG
void CSystemButtonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSystemButtonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSystemButtonDoc commands
