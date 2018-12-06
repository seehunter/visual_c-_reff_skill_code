// OLEDBSet.h : interface of the COLEDBSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBSET_H__C2CFA99F_2EC6_42E9_8922_B372F2B2AA2C__INCLUDED_)
#define AFX_OLEDBSET_H__C2CFA99F_2EC6_42E9_8922_B372F2B2AA2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStudent
{
public:
	CStudent()
	{
		memset( (void*)this, 0, sizeof(*this) );
	};

	int m_age;
	int m_grade;
	wchar_t m_name[26];
	wchar_t m_sex[26];


BEGIN_COLUMN_MAP(CStudent)
		COLUMN_ENTRY_TYPE(3, DBTYPE_I4, m_age)
		COLUMN_ENTRY_TYPE(4, DBTYPE_I4, m_grade)
		COLUMN_ENTRY_TYPE(1, DBTYPE_WSTR, m_name)
		COLUMN_ENTRY_TYPE(2, DBTYPE_WSTR, m_sex)
END_COLUMN_MAP()

};

class COLEDBSet : public CCommand<CAccessor<CStudent> >
{
public:

	HRESULT Open()
	{
		CDataSource db;
		CSession	session;
		HRESULT		hr;

		CDBPropSet	dbinit(DBPROPSET_DBINIT);
		dbinit.AddProperty(DBPROP_AUTH_CACHE_AUTHINFO, true);
		dbinit.AddProperty(DBPROP_AUTH_ENCRYPT_PASSWORD, false);
		dbinit.AddProperty(DBPROP_AUTH_MASK_PASSWORD, false);
		dbinit.AddProperty(DBPROP_AUTH_PASSWORD, "");
		dbinit.AddProperty(DBPROP_AUTH_USERID, "Admin");
		dbinit.AddProperty(DBPROP_INIT_DATASOURCE, "E:\\VC++编程技巧与代码参考\\代码\\第08章\\db1.mdb");
		dbinit.AddProperty(DBPROP_INIT_MODE, (long)16);
		dbinit.AddProperty(DBPROP_INIT_PROMPT, (short)4);
		dbinit.AddProperty(DBPROP_INIT_PROVIDERSTRING, "");
		dbinit.AddProperty(DBPROP_INIT_LCID, (long)1033);
		dbinit.AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, false);

		hr = db.OpenWithServiceComponents("Microsoft.Jet.OLEDB.4.0", &dbinit);
		if (FAILED(hr))
			return hr;

		hr = session.Open(db);
		if (FAILED(hr))
			return hr;

		CDBPropSet	propset(DBPROPSET_ROWSET);
		propset.AddProperty(DBPROP_CANFETCHBACKWARDS, true);
		propset.AddProperty(DBPROP_IRowsetScroll, true);
		propset.AddProperty(DBPROP_IRowsetChange, true);
		propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE );

		hr = CCommand<CAccessor<CStudent> >::Open(session, "SELECT * FROM student", &propset);
		if (FAILED(hr))
			return hr;

		return MoveNext();
	}

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBSET_H__C2CFA99F_2EC6_42E9_8922_B372F2B2AA2C__INCLUDED_)

