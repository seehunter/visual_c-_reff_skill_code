// ImageStatic.h : main header file for the IMAGESTATIC application
//

#if !defined(AFX_IMAGESTATIC_H__EFD5DFBF_0F47_4516_89AB_7F6F6DA7AAAA__INCLUDED_)
#define AFX_IMAGESTATIC_H__EFD5DFBF_0F47_4516_89AB_7F6F6DA7AAAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CImageStaticApp:
// See ImageStatic.cpp for the implementation of this class
//

class CImageStaticApp : public CWinApp
{
public:
	CImageStaticApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageStaticApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CImageStaticApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGESTATIC_H__EFD5DFBF_0F47_4516_89AB_7F6F6DA7AAAA__INCLUDED_)
