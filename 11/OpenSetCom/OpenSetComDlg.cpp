// OpenSetComDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OpenSetCom.h"
#include "OpenSetComDlg.h"
#include ".\opensetcomdlg.h"

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


// COpenSetComDlg �Ի���



COpenSetComDlg::COpenSetComDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COpenSetComDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpenSetComDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COpenSetComDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_SET, OnBnClickedSet)
END_MESSAGE_MAP()


// COpenSetComDlg ��Ϣ�������

BOOL COpenSetComDlg::OnInitDialog()
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
	
	return TRUE;  // ���������˿ؼ��Ľ��㣬���򷵻� TRUE
}

void COpenSetComDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COpenSetComDlg::OnPaint() 
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
HCURSOR COpenSetComDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void COpenSetComDlg::OnBnClickedSet()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	COMMTIMEOUTS TimeOuts;

	CString port = "";

	GetDlgItem(IDC_PORT)->GetWindowText(port);

	m_hCom=CreateFile(port, GENERIC_READ | GENERIC_WRITE, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 
		NULL); // �ص���ʽ

	if(m_hCom==INVALID_HANDLE_VALUE)
		return ;

	SetupComm(m_hCom,MAXBLOCK,MAXBLOCK);
	SetCommMask(m_hCom, EV_RXCHAR);

	
	// �Ѽ����ʱ��Ϊ���
	TimeOuts.ReadIntervalTimeout=MAXDWORD; 
	TimeOuts.ReadTotalTimeoutMultiplier=0; 
	TimeOuts.ReadTotalTimeoutConstant=0; 

	
	TimeOuts.WriteTotalTimeoutMultiplier=50;
	TimeOuts.WriteTotalTimeoutConstant=2000;

	SetCommTimeouts(m_hCom, &TimeOuts);

	DCB dcb;

	if(!GetCommState(m_hCom, &dcb))
		return ;

	dcb.fBinary = TRUE;
	CString rate = "";
	GetDlgItem(IDC_RATE)->GetWindowText(rate);
	if( rate == "" ){
		MessageBox("���������ݴ������ʣ�", "��Ϣ��ʾ����", MB_OK);
		return;
	}
	dcb.BaudRate = atoi(rate); // ���ݴ�������

	CString bit = "";
	GetDlgItem(IDC_BIT)->GetWindowText(bit);
	if( bit == "" ){
		MessageBox("���������ݴ������ʣ�", "��Ϣ��ʾ����", MB_OK);
		return;
	}
	dcb.ByteSize = atoi(bit); // ÿ�ֽ�λ��
	dcb.fParity = TRUE;

	CString parity = "";
	GetDlgItem(IDC_BAUD)->GetWindowText(parity);
	if( parity == "" ){
		MessageBox("������У��λ��", "��Ϣ��ʾ����", MB_OK);
		return ;
	}

	switch(atoi(parity)) // У������
	{
	case 0: 
		dcb.Parity = NOPARITY;
		break;

	case 1: 
		dcb.Parity=EVENPARITY;
		break;

	case 2: 
		dcb.Parity=ODDPARITY;
		break;

	default:;
	}

	CString stop = "";
	GetDlgItem(IDC_STOP)->GetWindowText(stop);
	if( stop == "" ){
		MessageBox("������У��λ��", "��Ϣ��ʾ����", MB_OK);
		return ;
	}

	switch(atoi(stop)) // ֹͣλ
	{
	case 0: 
		dcb.StopBits=ONESTOPBIT;
		break;

	case 1: 
		dcb.StopBits=ONE5STOPBITS;
		break;

	case 2:
		dcb.StopBits=TWOSTOPBITS;
		break;

	default:;
	}

	// Ӳ������������
	dcb.fOutxCtsFlow = TRUE;
	dcb.fRtsControl = TRUE;

	// XON/XOFF����������
	dcb.fInX=dcb.fOutX = TRUE;
	dcb.XonChar = XON;
	dcb.XoffChar = XOFF;
	dcb.XonLim = 50;
	dcb.XoffLim = 50;

	BOOL flag = SetCommState(m_hCom, &dcb);

	if( flag ){
		MessageBox("���ڴ򿪲����óɹ���", "��Ϣ��ʾ����", MB_OK);
		CloseHandle(m_hCom);
		return;
	}else {
		MessageBox("���ڲ���ʧ�ܣ�", "��Ϣ��ʾ����", MB_OK);
		CloseHandle(m_hCom);
		return;
	}

	return;
}
