// JpgViewDoc.cpp : implementation of the CJpgViewDoc class
//

#include "stdafx.h"
#include "JpgView.h"

#include "JpgViewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJpgViewDoc

IMPLEMENT_DYNCREATE(CJpgViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CJpgViewDoc, CDocument)
	//{{AFX_MSG_MAP(CJpgViewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJpgViewDoc construction/destruction

CJpgViewDoc::CJpgViewDoc()
{
	// TODO: add one-time construction code here

}

CJpgViewDoc::~CJpgViewDoc()
{
}

BOOL CJpgViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CJpgViewDoc serialization

void CJpgViewDoc::Serialize(CArchive& ar)
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
// CJpgViewDoc diagnostics

#ifdef _DEBUG
void CJpgViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CJpgViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJpgViewDoc commands
