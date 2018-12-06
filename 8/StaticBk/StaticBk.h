// StaticBk.h : main header file for the STATICBK application
//

#if !defined(AFX_STATICBK_H__864B39CC_5B3F_473F_B573_FDAD9E021DDC__INCLUDED_)
#define AFX_STATICBK_H__864B39CC_5B3F_473F_B573_FDAD9E021DDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStaticBkApp:
// See StaticBk.cpp for the implementation of this class
//

class CStaticBkApp : public CWinApp
{
public:
	CStaticBkApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticBkApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStaticBkApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICBK_H__864B39CC_5B3F_473F_B573_FDAD9E021DDC__INCLUDED_)
