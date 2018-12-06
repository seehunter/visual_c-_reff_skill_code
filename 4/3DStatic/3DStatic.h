// 3DStatic.h : main header file for the 3DSTATIC application
//

#if !defined(AFX_3DSTATIC_H__49D9E798_7EAF_4D50_93B0_F3AF98524901__INCLUDED_)
#define AFX_3DSTATIC_H__49D9E798_7EAF_4D50_93B0_F3AF98524901__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy3DStaticApp:
// See 3DStatic.cpp for the implementation of this class
//

class CMy3DStaticApp : public CWinApp
{
public:
	CMy3DStaticApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy3DStaticApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy3DStaticApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_3DSTATIC_H__49D9E798_7EAF_4D50_93B0_F3AF98524901__INCLUDED_)
