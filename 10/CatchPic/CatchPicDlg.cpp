// CatchPicDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CatchPic.h"
#include "CatchPicDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCatchPicDlg dialog

CCatchPicDlg::CCatchPicDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCatchPicDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCatchPicDlg)
	m_Left = 0;
	m_Top = 0;
	m_Right = 0;
	m_Bottom = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//获取屏幕分辩率
	m_xScreen = GetSystemMetrics(SM_CXSCREEN);
	m_yScreen = GetSystemMetrics(SM_CYSCREEN);
}

void CCatchPicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCatchPicDlg)
	DDX_Text(pDX, IDC_LEFT, m_Left);
	DDX_Text(pDX, IDC_TOP, m_Top);
	DDX_Text(pDX, IDC_RIGHT, m_Right);
	DDX_Text(pDX, IDC_BOTTOM, m_Bottom);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCatchPicDlg, CDialog)
	//{{AFX_MSG_MAP(CCatchPicDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CUT_SCREEN_BTN, OnCutScreenBtn)
	ON_BN_CLICKED(IDC_SAVE_BTN, OnSaveBtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCatchPicDlg message handlers

BOOL CCatchPicDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
        
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCatchPicDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCatchPicDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCatchPicDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/************************************************************************/
/* 函数说明:截取屏幕坐标到位图
*  参数说明:要截取屏幕的矩形区域
*   
/************************************************************************/
void CCatchPicDlg::CopyScreenToBitmap(LPRECT lpRect)
{
	//创建屏幕设备描述表
	HDC       hScrDC;
	//创建内存设备描述表
	HDC       hMemDC; 
	//位图句柄
	HBITMAP    hBitmap, hOldBitmap; 
	
	int       nX, nY, nX2, nY2;      
	// 选定区域坐标
	int       nWidth, nHeight;
	
	// 确保选定区域不为空矩形
	if (IsRectEmpty(lpRect))
		return ;
	//为屏幕创建设备描述表
	hScrDC = CreateDC("DISPLAY", NULL, NULL, NULL);
	
	//为屏幕设备描述表创建兼容的内存设备描述表
	hMemDC = CreateCompatibleDC(hScrDC);
	// 获得选定区域坐标
	nX = lpRect->left;
	nY = lpRect->top;
	nX2 = lpRect->right;
	nY2 = lpRect->bottom;
	
	//确保选定区域是可见的
	if (nX < 0)
		nX = 0;
	if (nY < 0)
		nY = 0;
	if (nX2 > m_xScreen)
		nX2 = m_xScreen;
	if (nY2 > m_yScreen)
		nY2 = m_yScreen;
	//获得位图的宽度和长度
	nWidth = nX2 - nX;
	nHeight = nY2 - nY;
	// 创建一个与屏幕设备描述表兼容的位图
	hBitmap = CreateCompatibleBitmap
		(hScrDC, nWidth, nHeight);
	// 把新位图选到内存设备描述表中
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);
	// 把屏幕设备描述表拷贝到内存设备描述表中
	BitBlt(hMemDC, 0, 0, nWidth, nHeight,
		hScrDC, nX, nY, SRCCOPY);
	hBitmap = (HBITMAP)SelectObject(hMemDC, hOldBitmap);
	//得到屏幕位图的句柄
	//清除 
	DeleteDC(hScrDC);
	DeleteDC(hMemDC);
	// 返回位图句柄			
	if (OpenClipboard()) 
	{
        
        EmptyClipboard();//清空剪贴板
        //把屏幕内容粘贴到剪贴板上,
        SetClipboardData(CF_BITMAP, hBitmap);
        //关闭剪贴板
        CloseClipboard();
	}
	m_hBitmap = hBitmap;
}

void CCatchPicDlg::OnCutScreenBtn() 
{
	UpdateData(TRUE);
    CRect rect(m_Left,m_Top,m_Right,m_Bottom);
	CopyScreenToBitmap(&rect);
}
/************************************************************************/
/* 函数说明:创建位图的结构
/************************************************************************/
BOOL CCatchPicDlg::CreateBitmapInfoStruct(HBITMAP hBmp,PBITMAPINFO& pbmi)
{ 
	BITMAP bmp; 
	//PBITMAPINFO pbmi; 
	WORD    cClrBits; 

	// Retrieve the bitmap color format, width, and height. 
	if (!GetObject(hBmp, sizeof(BITMAP), (LPSTR)&bmp)) 
		return FALSE;

	// Convert the color format to a count of bits. 
	cClrBits = (WORD)(bmp.bmPlanes * bmp.bmBitsPixel); 
	if (cClrBits == 1) 
		cClrBits = 1; 
	else if (cClrBits <= 4) 
		cClrBits = 4; 
	else if (cClrBits <= 8) 
		cClrBits = 8; 
	else if (cClrBits <= 16) 
		cClrBits = 16; 
	else if (cClrBits <= 24) 
		cClrBits = 24; 
	else cClrBits = 32; 

	// Allocate memory for the BITMAPINFO structure. (This structure 
	// contains a BITMAPINFOHEADER structure and an array of RGBQUAD 
	// data structures.) 

	if (cClrBits != 24) 
		pbmi = (PBITMAPINFO) LocalAlloc(LPTR, 
		sizeof(BITMAPINFOHEADER) + 
		sizeof(RGBQUAD) * (1<< cClrBits)); 

	// There is no RGBQUAD array for the 24-bit-per-pixel format. 

	else 
		pbmi = (PBITMAPINFO) LocalAlloc(LPTR, 
		sizeof(BITMAPINFOHEADER)); 

	// Initialize the fields in the BITMAPINFO structure. 

	pbmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER); 
	pbmi->bmiHeader.biWidth = bmp.bmWidth; 
	pbmi->bmiHeader.biHeight = bmp.bmHeight; 
	pbmi->bmiHeader.biPlanes = bmp.bmPlanes; 
	pbmi->bmiHeader.biBitCount = bmp.bmBitsPixel; 
	if (cClrBits < 24) 
		pbmi->bmiHeader.biClrUsed = (1<<cClrBits); 

	// If the bitmap is not compressed, set the BI_RGB flag. 
	pbmi->bmiHeader.biCompression = BI_RGB; 

	// Compute the number of bytes in the array of color 
	// indices and store the result in biSizeImage. 
	// For Windows NT, the width must be DWORD aligned unless 
	// the bitmap is RLE compressed. This example shows this. 
	// For Windows 95/98/Me, the width must be WORD aligned unless the 
	// bitmap is RLE compressed.
	pbmi->bmiHeader.biSizeImage = ((pbmi->bmiHeader.biWidth * cClrBits +31) & ~31) /8
		* pbmi->bmiHeader.biHeight; 
	// Set biClrImportant to 0, indicating that all of the 
	// device colors are important. 
	pbmi->bmiHeader.biClrImportant = 0; 
	return TRUE; 
} 
/************************************************************************/
/* 生成文件
/************************************************************************/
BOOL CCatchPicDlg::CreateBMPFile(LPTSTR pszFile, PBITMAPINFO pbi, 
				   HBITMAP hBMP, HDC hDC) 
{ 
	HANDLE hf;                 // file handle 
	BITMAPFILEHEADER hdr;       // bitmap file-header 
	PBITMAPINFOHEADER pbih;     // bitmap info-header 
	LPBYTE lpBits;              // memory pointer 
	DWORD dwTotal;              // total count of bytes 
	DWORD cb;                   // incremental count of bytes 
	BYTE *hp;                   // byte pointer 
	DWORD dwTmp; 

	pbih = (PBITMAPINFOHEADER) pbi; 
	lpBits = (LPBYTE) GlobalAlloc(GMEM_FIXED, pbih->biSizeImage);

	if (!lpBits) 
		return FALSE;

	// Retrieve the color table (RGBQUAD array) and the bits 
	// (array of palette indices) from the DIB. 
	if (!GetDIBits(hDC, hBMP, 0, (WORD) pbih->biHeight, lpBits, pbi, 
		DIB_RGB_COLORS)) 
	{
		return FALSE;
	}

	// Create the .BMP file. 
	hf = CreateFile(pszFile, 
		GENERIC_READ | GENERIC_WRITE, 
		(DWORD) 0, 
		NULL, 
		CREATE_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL, 
		(HANDLE) NULL); 
	if (hf == INVALID_HANDLE_VALUE) 
		return FALSE;
	hdr.bfType = 0x4d42;        // 0x42 = "B" 0x4d = "M" 
	// Compute the size of the entire file. 
	hdr.bfSize = (DWORD) (sizeof(BITMAPFILEHEADER) + 
		pbih->biSize + pbih->biClrUsed 
		* sizeof(RGBQUAD) + pbih->biSizeImage); 
	hdr.bfReserved1 = 0; 
	hdr.bfReserved2 = 0; 

	// Compute the offset to the array of color indices. 
	hdr.bfOffBits = (DWORD) sizeof(BITMAPFILEHEADER) + 
		pbih->biSize + pbih->biClrUsed 
		* sizeof (RGBQUAD); 

	// Copy the BITMAPFILEHEADER into the .BMP file. 
	if (!WriteFile(hf, (LPVOID) &hdr, sizeof(BITMAPFILEHEADER), 
		(LPDWORD) &dwTmp,  NULL)) 
	{
		return FALSE;
	}

	// Copy the BITMAPINFOHEADER and RGBQUAD array into the file. 
	if (!WriteFile(hf, (LPVOID) pbih, sizeof(BITMAPINFOHEADER) 
		+ pbih->biClrUsed * sizeof (RGBQUAD), 
		(LPDWORD) &dwTmp, ( NULL))) 
		return FALSE;

	// Copy the array of color indices into the .BMP file. 
	dwTotal = cb = pbih->biSizeImage; 
	hp = lpBits; 
	if (!WriteFile(hf, (LPSTR) hp, (int) cb, (LPDWORD) &dwTmp,NULL)) 
		return FALSE;
	// Close the .BMP file. 
	if (!CloseHandle(hf)) 
		return FALSE;

	// Free memory. 
	GlobalFree((HGLOBAL)lpBits);

	return TRUE;
}
void CCatchPicDlg::OnSaveBtn() 
{
   	
	if(m_hBitmap == NULL)
		return;
	
	CFileDialog fileDlg(FALSE, "*.bmp", "capture.bmp", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"Save File(*.bmp)|*.bmp||");
	if(IDOK == fileDlg.DoModal())
	{
		PBITMAPINFO pbmp;
		if(!CreateBitmapInfoStruct(m_hBitmap, pbmp))
		{
			return;
		}

		if(CreateBMPFile(fileDlg.GetPathName().GetBuffer(MAX_PATH), pbmp, m_hBitmap, GetDC()->GetSafeHdc()))
			AfxMessageBox("Save image file successfully!");
	}
}

