#if !defined(AFX_MYDB_H__E906ABA1_F169_440C_BBC2_BCA8C9CA8C0C__INCLUDED_)
#define AFX_MYDB_H__E906ABA1_F169_440C_BBC2_BCA8C9CA8C0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyDB.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyDB DAO recordset
#include"afxdao.h"
class CMyDB : public CDaoRecordset
{
public:
	CMyDB(CDaoDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMyDB)

// Field/Param Data
	//{{AFX_FIELD(CMyDB, CDaoRecordset)
	CString	m_name;
	CString	m_sex;
	long	m_age;
	long	m_grade;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDB)
	public:
	virtual CString GetDefaultDBName();		// Default database name
	virtual CString GetDefaultSQL();		// Default SQL for Recordset
	virtual void DoFieldExchange(CDaoFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDB_H__E906ABA1_F169_440C_BBC2_BCA8C9CA8C0C__INCLUDED_)
