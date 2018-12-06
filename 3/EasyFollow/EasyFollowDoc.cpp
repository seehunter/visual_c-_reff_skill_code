// EasyFollowDoc.cpp : implementation of the CEasyFollowDoc class
//

#include "stdafx.h"
#include "EasyFollow.h"

#include "EasyFollowDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEasyFollowDoc

IMPLEMENT_DYNCREATE(CEasyFollowDoc, CDocument)

BEGIN_MESSAGE_MAP(CEasyFollowDoc, CDocument)
	//{{AFX_MSG_MAP(CEasyFollowDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEasyFollowDoc construction/destruction

CEasyFollowDoc::CEasyFollowDoc()
{
	// TODO: add one-time construction code here

}

CEasyFollowDoc::~CEasyFollowDoc()
{
}

BOOL CEasyFollowDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEasyFollowDoc serialization

void CEasyFollowDoc::Serialize(CArchive& ar)
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
// CEasyFollowDoc diagnostics

#ifdef _DEBUG
void CEasyFollowDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEasyFollowDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEasyFollowDoc commands
