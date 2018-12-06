// ShowScrollTextDoc.cpp : implementation of the CShowScrollTextDoc class
//

#include "stdafx.h"
#include "ShowScrollText.h"

#include "ShowScrollTextDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowScrollTextDoc

IMPLEMENT_DYNCREATE(CShowScrollTextDoc, CDocument)

BEGIN_MESSAGE_MAP(CShowScrollTextDoc, CDocument)
	//{{AFX_MSG_MAP(CShowScrollTextDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowScrollTextDoc construction/destruction

CShowScrollTextDoc::CShowScrollTextDoc()
{
	// TODO: add one-time construction code here

}

CShowScrollTextDoc::~CShowScrollTextDoc()
{
}

BOOL CShowScrollTextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShowScrollTextDoc serialization

void CShowScrollTextDoc::Serialize(CArchive& ar)
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
// CShowScrollTextDoc diagnostics

#ifdef _DEBUG
void CShowScrollTextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShowScrollTextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowScrollTextDoc commands
