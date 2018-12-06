// GetLanCompNameDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CGetLanCompNameDlg �Ի���



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


// CGetLanCompNameDlg ��Ϣ�������

BOOL CGetLanCompNameDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��\������...\���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_ListCtrl.InsertColumn(0, "�������ڼ��������", LVCFMT_LEFT, 200);
	m_ListCtrl.InsertColumn(1, "�������ڼ����IP", LVCFMT_LEFT, 200);
	
	return TRUE;  // ���������˿ؼ��Ľ��㣬���򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGetLanCompNameDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
HCURSOR CGetLanCompNameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGetLanCompNameDlg::OnBnClickedGetname()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

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
					//���������
					gethostname( StrHostName, strlen( StrHostName ) );

					MyListName.Add(StrHostName);

					//����������ø�����Ӧ��������Ϣ
					host = gethostbyname(strFullName);
					if(host == NULL) continue; 
					ptr = (struct in_addr *) host->h_addr_list[0];										
					// ��û����ģɣе�ַ			
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
