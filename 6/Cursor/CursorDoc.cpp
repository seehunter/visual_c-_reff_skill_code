// CursorDoc.cpp : implementation of the CCursorDoc class
//

#include "stdafx.h"
#include "Cursor.h"

#include "CursorDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCursorDoc

IMPLEMENT_DYNCREATE(CCursorDoc, CDocument)

BEGIN_MESSAGE_MAP(CCursorDoc, CDocument)
	//{{AFX_MSG_MAP(CCursorDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCursorDoc construction/destruction

CCursorDoc::CCursorDoc()
{
	// TODO: add one-time construction code here

}

CCursorDoc::~CCursorDoc()
{
}

BOOL CCursorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCursorDoc serialization

void CCursorDoc::Serialize(CArchive& ar)
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
// CCursorDoc diagnostics

#ifdef _DEBUG
void CCursorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCursorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCursorDoc commands
