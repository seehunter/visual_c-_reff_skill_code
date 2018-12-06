// ChangeViewSizeDoc.cpp : implementation of the CChangeViewSizeDoc class
//

#include "stdafx.h"
#include "ChangeViewSize.h"

#include "ChangeViewSizeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChangeViewSizeDoc

IMPLEMENT_DYNCREATE(CChangeViewSizeDoc, CDocument)

BEGIN_MESSAGE_MAP(CChangeViewSizeDoc, CDocument)
	//{{AFX_MSG_MAP(CChangeViewSizeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangeViewSizeDoc construction/destruction

CChangeViewSizeDoc::CChangeViewSizeDoc()
{
	// TODO: add one-time construction code here

}

CChangeViewSizeDoc::~CChangeViewSizeDoc()
{
}

BOOL CChangeViewSizeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CChangeViewSizeDoc serialization

void CChangeViewSizeDoc::Serialize(CArchive& ar)
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
// CChangeViewSizeDoc diagnostics

#ifdef _DEBUG
void CChangeViewSizeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CChangeViewSizeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChangeViewSizeDoc commands
