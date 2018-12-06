// CircleTextDoc.cpp : implementation of the CCircleTextDoc class
//

#include "stdafx.h"
#include "CircleText.h"

#include "CircleTextDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCircleTextDoc

IMPLEMENT_DYNCREATE(CCircleTextDoc, CDocument)

BEGIN_MESSAGE_MAP(CCircleTextDoc, CDocument)
	//{{AFX_MSG_MAP(CCircleTextDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCircleTextDoc construction/destruction

CCircleTextDoc::CCircleTextDoc()
{
	// TODO: add one-time construction code here

}

CCircleTextDoc::~CCircleTextDoc()
{
}

BOOL CCircleTextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCircleTextDoc serialization

void CCircleTextDoc::Serialize(CArchive& ar)
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
// CCircleTextDoc diagnostics

#ifdef _DEBUG
void CCircleTextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCircleTextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCircleTextDoc commands
