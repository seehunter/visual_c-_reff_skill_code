// StatProgDoc.cpp :  CStatProgDoc 类的实现
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


// CStatProgDoc 构造/析构

CStatProgDoc::CStatProgDoc()
{
	// TODO: 在此添加一次性构造代码

}

CStatProgDoc::~CStatProgDoc()
{
}

BOOL CStatProgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CStatProgDoc 序列化

void CStatProgDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CStatProgDoc 诊断

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


// CStatProgDoc 命令
