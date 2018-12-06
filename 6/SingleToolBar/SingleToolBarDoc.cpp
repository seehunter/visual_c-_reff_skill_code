// SingleToolBarDoc.cpp : implementation of the CSingleToolBarDoc class
//

#include "stdafx.h"
#include "SingleToolBar.h"

#include "SingleToolBarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSingleToolBarDoc

IMPLEMENT_DYNCREATE(CSingleToolBarDoc, CDocument)

BEGIN_MESSAGE_MAP(CSingleToolBarDoc, CDocument)
	//{{AFX_MSG_MAP(CSingleToolBarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSingleToolBarDoc construction/destruction

CSingleToolBarDoc::CSingleToolBarDoc()
{
	// TODO: add one-time construction code here

}

CSingleToolBarDoc::~CSingleToolBarDoc()
{
}

BOOL CSingleToolBarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSingleToolBarDoc serialization

void CSingleToolBarDoc::Serialize(CArchive& ar)
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
// CSingleToolBarDoc diagnostics

#ifdef _DEBUG
void CSingleToolBarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSingleToolBarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSingleToolBarDoc commands
