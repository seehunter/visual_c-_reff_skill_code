// DAO.h : main header file for the DAO application
//

#if !defined(AFX_DAO_H__1C07475C_D238_4EB5_AD62_CB23A90846A2__INCLUDED_)
#define AFX_DAO_H__1C07475C_D238_4EB5_AD62_CB23A90846A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDAOApp:
// See DAO.cpp for the implementation of this class
//

class CDAOApp : public CWinApp
{
public:
	CDAOApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDAOApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDAOApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAO_H__1C07475C_D238_4EB5_AD62_CB23A90846A2__INCLUDED_)
