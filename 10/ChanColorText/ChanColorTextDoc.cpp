// ChanColorTextDoc.cpp : implementation of the CChanColorTextDoc class
//

#include "stdafx.h"
#include "ChanColorText.h"

#include "ChanColorTextDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChanColorTextDoc

IMPLEMENT_DYNCREATE(CChanColorTextDoc, CDocument)

BEGIN_MESSAGE_MAP(CChanColorTextDoc, CDocument)
	//{{AFX_MSG_MAP(CChanColorTextDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChanColorTextDoc construction/destruction

CChanColorTextDoc::CChanColorTextDoc()
{
	// TODO: add one-time construction code here

}

CChanColorTextDoc::~CChanColorTextDoc()
{
}

BOOL CChanColorTextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CChanColorTextDoc serialization

void CChanColorTextDoc::Serialize(CArchive& ar)
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
// CChanColorTextDoc diagnostics

#ifdef _DEBUG
void CChanColorTextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CChanColorTextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChanColorTextDoc commands
