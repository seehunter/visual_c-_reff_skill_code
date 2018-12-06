// MiniCADDoc.cpp : implementation of the CMiniCADDoc class
//

#include "stdafx.h"
#include "MiniCAD.h"

#include "MiniCADDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMiniCADDoc

IMPLEMENT_DYNCREATE(CMiniCADDoc, CDocument)

BEGIN_MESSAGE_MAP(CMiniCADDoc, CDocument)
	//{{AFX_MSG_MAP(CMiniCADDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMiniCADDoc construction/destruction

CMiniCADDoc::CMiniCADDoc()
{
	// TODO: add one-time construction code here

}

CMiniCADDoc::~CMiniCADDoc()
{
}

BOOL CMiniCADDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMiniCADDoc serialization

void CMiniCADDoc::Serialize(CArchive& ar)
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
// CMiniCADDoc diagnostics

#ifdef _DEBUG
void CMiniCADDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMiniCADDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMiniCADDoc commands
