// GetMACDlg.cpp : ʵ���ļ�
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
	//�������
	int nIndex;			
	//Mac��ַ���ַ�����ʽ��
	CString strMac;		
}AdapterStructRUCT;
CArray<AdapterStructRUCT,AdapterStructRUCT&> m_ArrayAdapters;	



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


// CGetMACDlg �Ի���



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


// CGetMACDlg ��Ϣ�������

BOOL CGetMACDlg::OnInitDialog()
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

	m_ListMacs.InsertColumn(0, "MAC��ַ�б�", LVCFMT_LEFT, 150);
	
	return TRUE;  // ���������˿ؼ��Ľ��㣬���򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGetMACDlg::OnPaint() 
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
HCURSOR CGetMACDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGetMACDlg::OnBnClickedGetmac()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	NCB Ncb; 
    UCHAR RetCode; 
	LANA_ENUM Lenum; 
	int i = 0; 	
	memset(&Ncb, 0, sizeof(Ncb)); 
	Ncb.ncb_command = NCBENUM; 
	Ncb.ncb_buffer = (UCHAR *)&Lenum; 
	Ncb.ncb_length = sizeof(Lenum); 
	//����������NCBENUM����Ի�ȡ��ǰ������������Ϣ�����ж��ٸ�������ÿ�������ı�ŵ� 
	RetCode = Netbios( &Ncb ); 
	//�������������Ϣ
	for(i=0; i < Lenum.length ;i++)
	{
		GetOneMac(Lenum.lana[i]);
	}	
	//�����浽�����е�����������Ϣ���б�����ʾ
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
			{//���
				sprintf(buffer,"%d", m_ArrayAdapters.GetAt(iItem).nIndex);
				lvitem.pszText = buffer;
				//iActualItem = m_ListMacs.InsertItem(&lvitem);
			}
			else
			{//Mac��ַ
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
	//ָ��������	
    ncb.ncb_lana_num = AdapterIndex;  
	//���ȶ�ѡ������������һ��NCBRESET����Ա���г�ʼ�� 
	RetCode = Netbios( &ncb );
    memset( &ncb, 0, sizeof(ncb) );
    ncb.ncb_command = NCBASTAT;
	// ָ��������
    ncb.ncb_lana_num = AdapterIndex; 	
    strcpy( (char *)ncb.ncb_callname,"*" );
	// ָ�����ص���Ϣ��ŵı��� 
    ncb.ncb_buffer = (unsigned char *) &Adapter;
	ncb.ncb_length = sizeof(Adapter);

	//����NCBASTAT�����Ի�ȡ��������Ϣ 
	RetCode = Netbios( &ncb );
    if ( RetCode == 0 )
    {
		//������MAC��ַ��ʽ���ɳ��õ�16������ʽ����0010-A4E4-5802 
		CString StrMacAddress;
		StrMacAddress.Format( "%02X%02X-%02X%02X-%02X%02X\n",
						Adapter.adapt.adapter_address[0],
						Adapter.adapt.adapter_address[1],
						Adapter.adapt.adapter_address[2],
						Adapter.adapt.adapter_address[3],
						Adapter.adapt.adapter_address[4],
						Adapter.adapt.adapter_address[5] );
		//��������ַ����Ŵ���������
		AdapterStructRUCT AdapterStruct;
		AdapterStruct.nIndex = AdapterIndex;
		AdapterStruct.strMac = StrMacAddress;

		m_ListMacs.InsertItem(0, "");

		m_ListMacs.InsertItem(0, StrMacAddress, 0);

		UpdateData(FALSE);

		m_ArrayAdapters.Add(AdapterStruct);
    }
}

