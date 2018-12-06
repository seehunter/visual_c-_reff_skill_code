// MultipleDocument.h : main header file for the MULTIPLEDOCUMENT application
//

#if !defined(AFX_MULTIPLEDOCUMENT_H__1F2C82A6_4716_49BF_88FC_88172BDCFD96__INCLUDED_)
#define AFX_MULTIPLEDOCUMENT_H__1F2C82A6_4716_49BF_88FC_88172BDCFD96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultipleDocumentApp:
// See MultipleDocument.cpp for the implementation of this class
//

class CMultipleDocumentApp : public CWinApp
{
public:
	CMultipleDocumentApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultipleDocumentApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMultipleDocumentApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIPLEDOCUMENT_H__1F2C82A6_4716_49BF_88FC_88172BDCFD96__INCLUDED_)
