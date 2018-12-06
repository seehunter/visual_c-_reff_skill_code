// Row.h: interface for the CRow class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROW_H__9D674D81_3102_45B1_B528_1D2AE1BDE22A__INCLUDED_)
#define AFX_ROW_H__9D674D81_3102_45B1_B528_1D2AE1BDE22A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>
class CRow  
{
public:
	CRow();
	virtual ~CRow();
     
	CString  strText;
	int      nTextleng;
	POINT    startPoint;
	POINT    endPonit;
};
typedef CTypedPtrList<CPtrList,CRow*> CRowList;
#endif // !defined(AFX_ROW_H__9D674D81_3102_45B1_B528_1D2AE1BDE22A__INCLUDED_)
