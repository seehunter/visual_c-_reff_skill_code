// HoolFontDoc.cpp : implementation of the CHoolFontDoc class
//

#include "stdafx.h"
#include "HoolFont.h"

#include "HoolFontDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHoolFontDoc

IMPLEMENT_DYNCREATE(CHoolFontDoc, CDocument)

BEGIN_MESSAGE_MAP(CHoolFontDoc, CDocument)
	//{{AFX_MSG_MAP(CHoolFontDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHoolFontDoc construction/destruction

CHoolFontDoc::CHoolFontDoc()
{
	// TODO: add one-time construction code here

}

CHoolFontDoc::~CHoolFontDoc()
{
}

BOOL CHoolFontDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHoolFontDoc serialization

void CHoolFontDoc::Serialize(CArchive& ar)
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
// CHoolFontDoc diagnostics

#ifdef _DEBUG
void CHoolFontDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHoolFontDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHoolFontDoc commands
