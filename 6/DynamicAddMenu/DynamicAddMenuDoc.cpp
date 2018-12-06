// DynamicAddMenuDoc.cpp : implementation of the CDynamicAddMenuDoc class
//

#include "stdafx.h"
#include "DynamicAddMenu.h"

#include "DynamicAddMenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynamicAddMenuDoc

IMPLEMENT_DYNCREATE(CDynamicAddMenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CDynamicAddMenuDoc, CDocument)
	//{{AFX_MSG_MAP(CDynamicAddMenuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynamicAddMenuDoc construction/destruction

CDynamicAddMenuDoc::CDynamicAddMenuDoc()
{
	// TODO: add one-time construction code here

}

CDynamicAddMenuDoc::~CDynamicAddMenuDoc()
{
}

BOOL CDynamicAddMenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDynamicAddMenuDoc serialization

void CDynamicAddMenuDoc::Serialize(CArchive& ar)
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
// CDynamicAddMenuDoc diagnostics

#ifdef _DEBUG
void CDynamicAddMenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDynamicAddMenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynamicAddMenuDoc commands
