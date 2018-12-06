// DownPullButtonDoc.cpp : implementation of the CDownPullButtonDoc class
//

#include "stdafx.h"
#include "DownPullButton.h"

#include "DownPullButtonDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDownPullButtonDoc

IMPLEMENT_DYNCREATE(CDownPullButtonDoc, CDocument)

BEGIN_MESSAGE_MAP(CDownPullButtonDoc, CDocument)
	//{{AFX_MSG_MAP(CDownPullButtonDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDownPullButtonDoc construction/destruction

CDownPullButtonDoc::CDownPullButtonDoc()
{
	// TODO: add one-time construction code here

}

CDownPullButtonDoc::~CDownPullButtonDoc()
{
}

BOOL CDownPullButtonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDownPullButtonDoc serialization

void CDownPullButtonDoc::Serialize(CArchive& ar)
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
// CDownPullButtonDoc diagnostics

#ifdef _DEBUG
void CDownPullButtonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDownPullButtonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDownPullButtonDoc commands
