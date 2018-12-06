// JpgViewView.cpp : implementation of the CJpgViewView class
//

#include "stdafx.h"
#include "JpgView.h"

#include "JpgViewDoc.h"
#include "JpgViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJpgViewView

IMPLEMENT_DYNCREATE(CJpgViewView, CView)

BEGIN_MESSAGE_MAP(CJpgViewView, CView)
	//{{AFX_MSG_MAP(CJpgViewView)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(IDM_ROMOTE, OnRomote)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJpgViewView construction/destruction

CJpgViewView::CJpgViewView()
{
   m_bRender = FALSE;
}

CJpgViewView::~CJpgViewView()
{
}

BOOL CJpgViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CJpgViewView drawing

void CJpgViewView::OnDraw(CDC* pDC)
{
	CJpgViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CJpgViewView printing

BOOL CJpgViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CJpgViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CJpgViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CJpgViewView diagnostics

#ifdef _DEBUG
void CJpgViewView::AssertValid() const
{
	CView::AssertValid();
}

void CJpgViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJpgViewDoc* CJpgViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJpgViewDoc)));
	return (CJpgViewDoc*)m_pDocument;
}
#endif //_DEBUG
/************************************************************************/
/* 
/************************************************************************/
void CJpgViewView::OnFileOpen() 
{
    CClientDC  dc(this);
	char  szFilter[] = "jpg文件 (*.jpg)|*.jpg|gif 文件 (*.gif)|*.gif|Data Files (*.bmp;*.bmp)|*.bmp; *.bmp|All Files (*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter, NULL);
	CFile file; 
    LONG cb; 
	
	if( IDOK != dlg.DoModal())
	{
		return;
	}
	m_strFilePath = dlg.GetPathName();
    CFileStatus fstatus; 
	
	if (file.Open(m_strFilePath,CFile::modeRead)&&file.GetStatus(m_strFilePath,fstatus)&& ((cb = fstatus.m_size) != -1)) 
	{ 
		HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb); 
		LPVOID pvData = NULL; 
		if (hGlobal != NULL) 
		{ 
			if((pvData = GlobalLock(hGlobal)) != NULL)
			{
				file.ReadHuge(pvData, cb);
				GlobalUnlock(hGlobal); 
				CreateStreamOnHGlobal(hGlobal, TRUE, &m_pIStream); 
			}
		}	
		UpdateData(FALSE);	
	}
	if(SUCCEEDED(OleLoadPicture(m_pIStream,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&m_pIPic)))
	{ 
		OLE_XSIZE_HIMETRIC hmWidth; 
		OLE_YSIZE_HIMETRIC hmHeight; 
		m_pIPic->get_Width(&hmWidth); 
		m_pIPic->get_Height(&hmHeight); 
		double fX,fY; 
		fX = (double)dc.GetDeviceCaps(HORZRES)*(double)hmWidth/((double)dc.GetDeviceCaps(HORZSIZE)*100.0); 
		fY = (double)dc.GetDeviceCaps(VERTRES)*(double)hmHeight/((double)dc.GetDeviceCaps(VERTSIZE)*100.0); 

		if(FAILED(m_pIPic->Render(dc.m_hDC,0,0,(DWORD)fX,(DWORD)fY,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		{
			AfxMessageBox("渲染图像失败！"); 
			m_pIPic->Release(); 
			m_bRender = FALSE;
		} 
		else
		{
            m_bRender = TRUE;
		}
	} 
}

void CJpgViewView::OnRomote() 
{
   	
}
