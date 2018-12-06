// OLEDBDoc.cpp : implementation of the COLEDBDoc class
//

#include "stdafx.h"
#include "OLEDB.h"

#include "OLEDBSet.h"
#include "OLEDBDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COLEDBDoc

IMPLEMENT_DYNCREATE(COLEDBDoc, CDocument)

BEGIN_MESSAGE_MAP(COLEDBDoc, CDocument)
	//{{AFX_MSG_MAP(COLEDBDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COLEDBDoc construction/destruction

COLEDBDoc::COLEDBDoc()
{
	// TODO: add one-time construction code here

}

COLEDBDoc::~COLEDBDoc()
{
}

BOOL COLEDBDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COLEDBDoc diagnostics

#ifdef _DEBUG
void COLEDBDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COLEDBDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COLEDBDoc commands
