// MiniCAD2Doc.cpp : implementation of the CMiniCAD2Doc class
//

#include "stdafx.h"
#include "MiniCAD2.h"

#include "MiniCAD2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMiniCAD2Doc

IMPLEMENT_DYNCREATE(CMiniCAD2Doc, CDocument)

BEGIN_MESSAGE_MAP(CMiniCAD2Doc, CDocument)
	//{{AFX_MSG_MAP(CMiniCAD2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMiniCAD2Doc construction/destruction

CMiniCAD2Doc::CMiniCAD2Doc()
{
	// TODO: add one-time construction code here

}

CMiniCAD2Doc::~CMiniCAD2Doc()
{
}

BOOL CMiniCAD2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMiniCAD2Doc serialization

void CMiniCAD2Doc::Serialize(CArchive& ar)
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
// CMiniCAD2Doc diagnostics

#ifdef _DEBUG
void CMiniCAD2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMiniCAD2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMiniCAD2Doc commands
