// Row.cpp: implementation of the CRow class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EasyText.h"
#include "Row.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRow::CRow()
{
	strText = "";
	nTextleng = 0;
    startPoint.x  =0 ;
	startPoint.y = 0;
	endPonit.x = 0;
	endPonit.y = 0;
}

CRow::~CRow()
{

}
