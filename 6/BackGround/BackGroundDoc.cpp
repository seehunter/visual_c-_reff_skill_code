// BackGroundDoc.cpp : implementation of the CBackGroundDoc class
//

#include "stdafx.h"
#include "BackGround.h"

#include "BackGroundDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBackGroundDoc

IMPLEMENT_DYNCREATE(CBackGroundDoc, CDocument)

BEGIN_MESSAGE_MAP(CBackGroundDoc, CDocument)
	//{{AFX_MSG_MAP(CBackGroundDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBackGroundDoc construction/destruction

CBackGroundDoc::CBackGroundDoc()
{
	// TODO: add one-time construction code here

}

CBackGroundDoc::~CBackGroundDoc()
{
}

BOOL CBackGroundDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBackGroundDoc serialization

void CBackGroundDoc::Serialize(CArchive& ar)
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
// CBackGroundDoc diagnostics

#ifdef _DEBUG
void CBackGroundDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBackGroundDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBackGroundDoc commands
