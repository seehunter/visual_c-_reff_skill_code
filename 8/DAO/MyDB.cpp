// MyDB.cpp : implementation file
//

#include "stdafx.h"
#include "DAO.h"
#include "MyDB.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDB

IMPLEMENT_DYNAMIC(CMyDB, CDaoRecordset)

CMyDB::CMyDB(CDaoDatabase* pdb)
	: CDaoRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CMyDB)
	m_name = _T("");
	m_sex = _T("");
	m_age = 0;
	m_grade = 0;
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dbOpenDynaset;
}


CString CMyDB::GetDefaultDBName()
{
	return _T("E:\\VC++编程技巧与代码参考\\代码\\第08章\\db1.mdb");
}

CString CMyDB::GetDefaultSQL()
{
	return _T("[student]");
}

void CMyDB::DoFieldExchange(CDaoFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CMyDB)
	pFX->SetFieldType(CDaoFieldExchange::outputColumn);
	DFX_Text(pFX, _T("[name]"), m_name);
	DFX_Text(pFX, _T("[sex]"), m_sex);
	DFX_Long(pFX, _T("[age]"), m_age);
	DFX_Long(pFX, _T("[grade]"), m_grade);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CMyDB diagnostics

#ifdef _DEBUG
void CMyDB::AssertValid() const
{
	CDaoRecordset::AssertValid();
}

void CMyDB::Dump(CDumpContext& dc) const
{
	CDaoRecordset::Dump(dc);
}
#endif //_DEBUG
