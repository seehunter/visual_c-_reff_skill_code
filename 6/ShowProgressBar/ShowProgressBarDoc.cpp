// ShowProgressBarDoc.cpp : implementation of the CShowProgressBarDoc class
//

#include "stdafx.h"
#include "ShowProgressBar.h"

#include "ShowProgressBarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowProgressBarDoc

IMPLEMENT_DYNCREATE(CShowProgressBarDoc, CDocument)

BEGIN_MESSAGE_MAP(CShowProgressBarDoc, CDocument)
	//{{AFX_MSG_MAP(CShowProgressBarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowProgressBarDoc construction/destruction

CShowProgressBarDoc::CShowProgressBarDoc()
{
	// TODO: add one-time construction code here

}

CShowProgressBarDoc::~CShowProgressBarDoc()
{
}

BOOL CShowProgressBarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShowProgressBarDoc serialization
/*
void CShowProgressBarDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}*/
/////////////////////////////////////////////////////////////////////////文档装载处理函数；
void CShowProgressBarDoc::Serialize(CArchive& ar)
{
	CWnd* pFrame=AfxGetMainWnd();
	if(!ar.IsStoring()) 
	{
		for(int pct=10;pct<=100;pct+=10)
		{//对文档装载进行仿真处理；
			Sleep(150);
			if(pFrame)
				pFrame->SendMessage(MYWM_PROGRESS,pct);
		}
	}
	if(pFrame)
		pFrame->SendMessage(MYWM_PROGRESS,0);
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);//显示文本文件的内容；
}

/////////////////////////////////////////////////////////////////////////////
// CShowProgressBarDoc diagnostics

#ifdef _DEBUG
void CShowProgressBarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShowProgressBarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowProgressBarDoc commands
