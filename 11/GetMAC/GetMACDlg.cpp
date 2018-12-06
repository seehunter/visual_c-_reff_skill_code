// GetMACDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GetMAC.h"
#include "GetMACDlg.h"
#include ".\getmacdlg.h"

#include "afxtempl.h"
#include "nb30.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

typedef struct _ASTAT_
{
    ADAPTER_STATUS adapt;
    NAME_BUFFER    NameBuff [30];
}ASTAT, * PASTAT;
typedef struct AdapterStruct
{
	//网卡编号
	int nIndex;			
	//Mac地址（字符串形式）
	CString strMac;		
}AdapterStructRUCT;
CArray<AdapterStructRUCT,AdapterStructRUCT&> m_ArrayAdapters;	



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


// CGetMACDlg 对话框



CGetMACDlg::CGetMACDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetMACDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetMACDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_ListMacs);
}

BEGIN_MESSAGE_MAP(CGetMACDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_GETMAC, OnBnClickedGetmac)
END_MESSAGE_MAP()


// CGetMACDlg 消息处理程序

BOOL CGetMACDlg::OnInitDialog()
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

	m_ListMacs.InsertColumn(0, "MAC地址列表", LVCFMT_LEFT, 150);
	
	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
}

void CGetMACDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGetMACDlg::OnPaint() 
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
HCURSOR CGetMACDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGetMACDlg::OnBnClickedGetmac()
{
	// TODO: 在此添加控件通知处理程序代码

	NCB Ncb; 
    UCHAR RetCode; 
	LANA_ENUM Lenum; 
	int i = 0; 	
	memset(&Ncb, 0, sizeof(Ncb)); 
	Ncb.ncb_command = NCBENUM; 
	Ncb.ncb_buffer = (UCHAR *)&Lenum; 
	Ncb.ncb_length = sizeof(Lenum); 
	//向网卡发送NCBENUM命令，以获取当前机器的网卡信息，如有多少个网卡、每张网卡的编号等 
	RetCode = Netbios( &Ncb ); 
	//获得所有网卡信息
	for(i=0; i < Lenum.length ;i++)
	{
		GetOneMac(Lenum.lana[i]);
	}	
	//将保存到数组中的所有网卡信息在列表中显示
	int iActualItem = 0;
	LV_ITEM lvitem;
	TCHAR buffer[128];
	for(int iItem=0;iItem<m_ArrayAdapters.GetSize();iItem++)
	{
		for(int iSubItem=0;iSubItem<2;iSubItem++)
		{
			lvitem.mask = LVIF_TEXT|(iSubItem == 0? LVIF_IMAGE : 0);
			lvitem.iItem = (iSubItem == 0)? iItem : iActualItem;
			lvitem.iSubItem = iSubItem;
			lvitem.iImage = (iItem%2)?0:2;
		
			if (iSubItem == 0)
			{//序号
				sprintf(buffer,"%d", m_ArrayAdapters.GetAt(iItem).nIndex);
				lvitem.pszText = buffer;
				//iActualItem = m_ListMacs.InsertItem(&lvitem);
			}
			else
			{//Mac地址
				sprintf(buffer,"%s",m_ArrayAdapters.GetAt(iItem).strMac);
				lvitem.pszText = buffer;
				//m_ListMacs.SetItem(&lvitem);
			}
		}
	}

}

void CGetMACDlg::GetOneMac(int AdapterIndex)
{
	NCB ncb;
    UCHAR RetCode;
	ASTAT Adapter;
    memset( &ncb, 0, sizeof(ncb) );
    ncb.ncb_command = NCBRESET;
	//指定网卡号	
    ncb.ncb_lana_num = AdapterIndex;  
	//首先对选定的网卡发送一个NCBRESET命令，以便进行初始化 
	RetCode = Netbios( &ncb );
    memset( &ncb, 0, sizeof(ncb) );
    ncb.ncb_command = NCBASTAT;
	// 指定网卡号
    ncb.ncb_lana_num = AdapterIndex; 	
    strcpy( (char *)ncb.ncb_callname,"*" );
	// 指定返回的信息存放的变量 
    ncb.ncb_buffer = (unsigned char *) &Adapter;
	ncb.ncb_length = sizeof(Adapter);

	//发送NCBASTAT命令以获取网卡的信息 
	RetCode = Netbios( &ncb );
    if ( RetCode == 0 )
    {
		//把网卡MAC地址格式化成常用的16进制形式，如0010-A4E4-5802 
		CString StrMacAddress;
		StrMacAddress.Format( "%02X%02X-%02X%02X-%02X%02X\n",
						Adapter.adapt.adapter_address[0],
						Adapter.adapt.adapter_address[1],
						Adapter.adapt.adapter_address[2],
						Adapter.adapt.adapter_address[3],
						Adapter.adapt.adapter_address[4],
						Adapter.adapt.adapter_address[5] );
		//将网卡地址和序号存入数组中
		AdapterStructRUCT AdapterStruct;
		AdapterStruct.nIndex = AdapterIndex;
		AdapterStruct.strMac = StrMacAddress;

		m_ListMacs.InsertItem(0, "");

		m_ListMacs.InsertItem(0, StrMacAddress, 0);

		UpdateData(FALSE);

		m_ArrayAdapters.Add(AdapterStruct);
    }
}

