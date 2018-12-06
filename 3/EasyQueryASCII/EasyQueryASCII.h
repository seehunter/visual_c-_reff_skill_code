// EasyQueryASCII.h : main header file for the EASYQUERYASCII application
//

#if !defined(AFX_EASYQUERYASCII_H__B2E35416_1183_4AE5_850C_46C369D44C55__INCLUDED_)
#define AFX_EASYQUERYASCII_H__B2E35416_1183_4AE5_850C_46C369D44C55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEasyQueryASCIIApp:
// See EasyQueryASCII.cpp for the implementation of this class
//

class CEasyQueryASCIIApp : public CWinApp
{
public:
	CEasyQueryASCIIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEasyQueryASCIIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEasyQueryASCIIApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EASYQUERYASCII_H__B2E35416_1183_4AE5_850C_46C369D44C55__INCLUDED_)
