// AppendSystemMenuDoc.cpp : implementation of the CAppendSystemMenuDoc class
//

#include "stdafx.h"
#include "AppendSystemMenu.h"

#include "AppendSystemMenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAppendSystemMenuDoc

IMPLEMENT_DYNCREATE(CAppendSystemMenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CAppendSystemMenuDoc, CDocument)
	//{{AFX_MSG_MAP(CAppendSystemMenuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAppendSystemMenuDoc construction/destruction

CAppendSystemMenuDoc::CAppendSystemMenuDoc()
{
	// TODO: add one-time construction code here

}

CAppendSystemMenuDoc::~CAppendSystemMenuDoc()
{
}

BOOL CAppendSystemMenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAppendSystemMenuDoc serialization

void CAppendSystemMenuDoc::Serialize(CArchive& ar)
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
// CAppendSystemMenuDoc diagnostics

#ifdef _DEBUG
void CAppendSystemMenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAppendSystemMenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAppendSystemMenuDoc commands
