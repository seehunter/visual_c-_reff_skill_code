// TitleBarLetterDoc.cpp : implementation of the CTitleBarLetterDoc class
//

#include "stdafx.h"
#include "TitleBarLetter.h"

#include "TitleBarLetterDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTitleBarLetterDoc

IMPLEMENT_DYNCREATE(CTitleBarLetterDoc, CDocument)

BEGIN_MESSAGE_MAP(CTitleBarLetterDoc, CDocument)
	//{{AFX_MSG_MAP(CTitleBarLetterDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTitleBarLetterDoc construction/destruction

CTitleBarLetterDoc::CTitleBarLetterDoc()
{
	// TODO: add one-time construction code here

}

CTitleBarLetterDoc::~CTitleBarLetterDoc()
{
}

BOOL CTitleBarLetterDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTitleBarLetterDoc serialization

void CTitleBarLetterDoc::Serialize(CArchive& ar)
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
// CTitleBarLetterDoc diagnostics

#ifdef _DEBUG
void CTitleBarLetterDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTitleBarLetterDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTitleBarLetterDoc commands
void CTitleBarLetterDoc::SetTitle(LPCTSTR lpszTitle) 
{
    ///////////////////////////
	//
	lpszTitle="我的文档标题栏";
	//
	///////////////////////////
	CDocument::SetTitle(lpszTitle);
}
