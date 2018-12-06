#if !defined(AFX_MYSTATIC_H__E5D387EE_6B5C_4B48_BF81_F580886E54B2__INCLUDED_)
#define AFX_MYSTATIC_H__E5D387EE_6B5C_4B48_BF81_F580886E54B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyStatic window

class CMyStatic : public CStatic
{
// Construction
public:
	CMyStatic();
//public:
// Attributes

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyStatic)
	//}}AFX_VIRTUAL
public:
	void SetCtrlBkGr(COLORREF color);
	void SetCtrlBitmap(HBITMAP HBitmap);
	void SetCtrlIcon(HICON HIcon); 
	void Set3DText(int nHeight, int nWidth, int nEscapement, int nOrientation, int nWeight, 
						  BYTE bItalic, BYTE bUnderline, BYTE cStrikeOut, BYTE nCharSet, 
						  BYTE nOutPrecision, BYTE nClipPrecision, BYTE nQuality, 
						  BYTE nPitchAndFamily, LPCTSTR lpszFacename,COLORREF  colorTxt, COLORREF  colorShdow );
public:
    CFont  m_font;
	CString m_strCap;
    COLORREF  m_TxtColor;
	COLORREF  m_ShdowColor;
	COLORREF  m_BkColor;
	HBITMAP   m_hBitmap;
// Implementation
public:
	virtual ~CMyStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyStatic)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSTATIC_H__E5D387EE_6B5C_4B48_BF81_F580886E54B2__INCLUDED_)
