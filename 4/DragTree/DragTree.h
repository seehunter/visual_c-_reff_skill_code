// DragTree.h : main header file for the DRAGTREE application
//

#if !defined(AFX_DRAGTREE_H__935C40B6_F90F_4CA5_8BCF_10A201392BB4__INCLUDED_)
#define AFX_DRAGTREE_H__935C40B6_F90F_4CA5_8BCF_10A201392BB4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDragTreeApp:
// See DragTree.cpp for the implementation of this class
//

class CDragTreeApp : public CWinApp
{
public:
	CDragTreeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDragTreeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDragTreeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAGTREE_H__935C40B6_F90F_4CA5_8BCF_10A201392BB4__INCLUDED_)
