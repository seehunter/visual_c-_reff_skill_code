// StatProgDoc.cpp :  CStatProgDoc ���ʵ��
//

#include "stdafx.h"
#include "StatProg.h"

#include "StatProgDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStatProgDoc

IMPLEMENT_DYNCREATE(CStatProgDoc, CDocument)

BEGIN_MESSAGE_MAP(CStatProgDoc, CDocument)
END_MESSAGE_MAP()


// CStatProgDoc ����/����

CStatProgDoc::CStatProgDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CStatProgDoc::~CStatProgDoc()
{
}

BOOL CStatProgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CStatProgDoc ���л�

void CStatProgDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CStatProgDoc ���

#ifdef _DEBUG
void CStatProgDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStatProgDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CStatProgDoc ����
