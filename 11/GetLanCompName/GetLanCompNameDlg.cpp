// GetLanCompNameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GetLanCompName.h"
#include "GetLanCompNameDlg.h"
#include ".\getlancompnamedlg.h"

#include "Winsock.h"
#include "Winnetwk.h"

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


// CGetLanCompNameDlg 对话框



CGetLanCompNameDlg::CGetLanCompNameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetLanCompNameDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetLanCompNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CGetLanCompNameDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_GETNAME, OnBnClickedGetname)
END_MESSAGE_MAP()


// CGetLanCompNameDlg 消息处理程序

BOOL CGetLanCompNameDlg::OnInitDialog()
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

	m_ListCtrl.InsertColumn(0, "局域网内计算机名称", LVCFMT_LEFT, 200);
	m_ListCtrl.InsertColumn(1, "局域网内计算机IP", LVCFMT_LEFT, 200);
	
	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
}

void CGetLanCompNameDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGetLanCompNameDlg::OnPaint() 
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
HCURSOR CGetLanCompNameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGetLanCompNameDlg::OnBnClickedGetname()
{
	// TODO: 在此添加控件通知处理程序代码

	CStringArray iparray;

	CStringArray namearray;


	FindAllComputer(iparray, namearray);
	CString ip = "";
	CString name = "";

	for( int i = 0; i < iparray.GetSize(); i++ ){

		ip = iparray.GetAt(i);
		name = namearray.GetAt(i);

		int m_nCurrentSel = m_ListCtrl.InsertItem(0xffff,"");

		m_ListCtrl.SetItem( m_nCurrentSel, 0, LVIF_TEXT, ip, NULL, 0, 0, 0);

		m_ListCtrl.SetItem( m_nCurrentSel, 1, LVIF_TEXT, name, NULL, 0, 0, 0);
	}

	int error = ::GetLastError();

}


void CGetLanCompNameDlg::FindAllComputer(CStringArray& MyList, CStringArray& MyListName)
{	
	MyList.RemoveAll();
	CString StrTemp;	
	struct hostent *host;
	struct in_addr *ptr;	
	DWORD dwScope = RESOURCE_CONTEXT;
	NETRESOURCE *NetResource = NULL;
	HANDLE hEnum;
	WNetOpenEnum( dwScope, NULL, NULL, NULL, &hEnum );
	WSADATA wsaData;
	
	WSAStartup(MAKEWORD(1,1),&wsaData);
	
	if ( hEnum )    
	{
		DWORD Count = 0xFFFFFFFF;
		DWORD BufferSize = 2048;
		LPVOID Buffer = new char[2048];
		
		WNetEnumResource( hEnum, &Count, Buffer, &BufferSize );
		NetResource = (NETRESOURCE*)Buffer;
		char StrHostName[200];
		for ( unsigned int i = 0; i < BufferSize/sizeof(NETRESOURCE); i++, NetResource++ )		
		{
			if ( NetResource->dwUsage == RESOURCEUSAGE_CONTAINER && NetResource->dwType == RESOURCETYPE_ANY ){
				if ( NetResource->lpRemoteName )
				{
					CString strFullName = NetResource->lpRemoteName;
					if ( 0 == strFullName.Left(2).Compare("\\\\") )			
						strFullName = strFullName.Right(strFullName.GetLength()-2);                    
					//获得主机名
					gethostname( StrHostName, strlen( StrHostName ) );

					MyListName.Add(StrHostName);

					//由主机名获得跟它对应的主机信息
					host = gethostbyname(strFullName);
					if(host == NULL) continue; 
					ptr = (struct in_addr *) host->h_addr_list[0];										
					// 获得机器的ＩＰ地址			
					int a = ptr->S_un.S_un_b.s_b1;  			
					int b = ptr->S_un.S_un_b.s_b2;  
					int c = ptr->S_un.S_un_b.s_b3;  
					int d = ptr->S_un.S_un_b.s_b4;  
					StrTemp.Format("%s : %d.%d.%d.%d",strFullName,a,b,c,d);

					MyList.Add(StrTemp);
				}
			}
		}
		delete Buffer;
		
		WNetCloseEnum( hEnum );	
	}
	
	WSACleanup();
}
