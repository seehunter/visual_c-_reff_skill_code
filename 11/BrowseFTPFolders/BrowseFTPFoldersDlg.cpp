// BrowseFTPFoldersDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BrowseFTPFolders.h"
#include "BrowseFTPFoldersDlg.h"
#include ".\browseftpfoldersdlg.h"

#include "afxinet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CBrowseFTPFoldersDlg 对话框



CBrowseFTPFoldersDlg::CBrowseFTPFoldersDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBrowseFTPFoldersDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBrowseFTPFoldersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CBrowseFTPFoldersDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_LOOK, OnBnClickedLook)
END_MESSAGE_MAP()


// CBrowseFTPFoldersDlg 消息处理程序

BOOL CBrowseFTPFoldersDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将\“关于...\”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	DWORD dwExStyle = LVS_EX_GRIDLINES ;
	m_ListCtrl.SetExtendedStyle(dwExStyle);

	m_ListCtrl.InsertColumn(0,"文件/文件名",LVCFMT_CENTER,200);
	m_ListCtrl.InsertColumn(1,"类型",LVCFMT_CENTER,100);
	
	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
}

void CBrowseFTPFoldersDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CBrowseFTPFoldersDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
HCURSOR CBrowseFTPFoldersDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBrowseFTPFoldersDlg::OnBnClickedLook()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	//新建CInternetSession对象
	m_pIntSession = new CInternetSession(AfxGetAppName(),1,PRE_CONFIG_INTERNET_ACCESS);
	try 
	{ 
		//新建连接对象
		CString ftp = "";
		GetDlgItem(IDC_FTP)->GetWindowText(ftp);
		if( ftp == "" ){
			MessageBox("请输入FTP地址！", "信息提示窗口", MB_OK);
			return;
		}

		CString name = "";
		GetDlgItem(IDC_NAME)->GetWindowText(name);
		if( name == "" ){
			MessageBox("请输入FTP地址！", "信息提示窗口", MB_OK);
			return;
		}

		CString password = "";
		GetDlgItem(IDC_PASSWORD)->GetWindowText(password);
		if( password == "" ){
			MessageBox("请输入FTP地址！", "信息提示窗口", MB_OK);
			return;
		}
		m_pFTPConnection = m_pIntSession->GetFtpConnection(ftp, name, password); 

		ASSERT(m_pFTPConnection);

		MessageBox("FTP服务器连接成功！", "信息提示窗口", MB_OK);
		return;

	} 
	catch(CInternetException *pEx) 
	{
		//获取错误信息
		TCHAR szError[1024];
		if(pEx->GetErrorMessage(szError,1024))
			AfxMessageBox(szError);
		else  
			AfxMessageBox("出现意外情况");
		pEx->Delete();
		m_pFTPConnection = NULL;
		return;
	}

	m_pRemoteFinder = new CFtpFileFind(m_pFTPConnection);
	//获得服务器根目录的所有文件并在列表框中显示
	BrowseFolder("",&m_ListCtrl,m_pRemoteFinder,&m_ArrayRemoteFiles);
}


void CBrowseFTPFoldersDlg::BrowseFolder(CString strDir,CListCtrl* pLstCtrl,CFileFind* pFinder,CArray<FILEITEM,FILEITEM&>* pFilesArr)
{
	//清空列表框
	pLstCtrl->DeleteAllItems();
	pFilesArr->RemoveAll();
	int nIndex = 0;	
	CString szDir = strDir;
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	szDir += "*.*";	
	//查找目录下的文件
	BOOL res = pFinder->FindFile(szDir);
	while(res)
	{
		res = pFinder->FindNextFile();
		//是目录
		if(pFinder->IsDirectory() && !pFinder->IsDots())
		{
			FILEITEM fileitem;
			fileitem.nItem = nIndex;
			fileitem.bDir = TRUE;
			fileitem.StrFileName = pFinder->GetFileName();
			pFilesArr->Add(fileitem);
			AddItem(pLstCtrl,nIndex,TRUE,pFinder->GetFileName());
		}
		//是文件
		else if(!pFinder->IsDirectory() && !pFinder->IsDots())
		{
			FILEITEM fileitem;
			fileitem.nItem = nIndex;
			fileitem.bDir = FALSE;
			fileitem.StrFileName = pFinder->GetFileName();
			pFilesArr->Add(fileitem);
			AddItem(pLstCtrl,nIndex,FALSE,pFinder->GetFileName());			
		}		
		nIndex++;
	}
}
//给列表框增加一条记录
void CBrowseFTPFoldersDlg::AddItem(CListCtrl* pLstCtrl,int nIndex,BOOL bDir,CString strText)
{
	LV_ITEM lvitem;
	int iActualItem;
	for(int iSubItem=0;iSubItem<2;iSubItem++)
	{
		lvitem.mask = LVIF_TEXT|(iSubItem == 0? LVIF_IMAGE : 0);
		lvitem.iItem = (iSubItem == 0)? nIndex : iActualItem;
		lvitem.iSubItem = iSubItem;
		switch(iSubItem)
		{
		case 0:
			lvitem.pszText =(LPTSTR)(LPCTSTR)strText;
			break;
		case 1:
			if(bDir)
				lvitem.pszText = "文件夹";
			else
				lvitem.pszText = "文件";
			break;
		} 
		if (iSubItem == 0)
			iActualItem = pLstCtrl->InsertItem(&lvitem);
		else
			pLstCtrl->SetItem(&lvitem);
	}
}
