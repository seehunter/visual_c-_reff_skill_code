// TestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Test.h"
#include "TestDlg.h"

#include "Ras.h"

#include "ras.h"
#include "raserror.h"
#include ".\testdlg.h"

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


// CTestDlg �Ի���



CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CONNECT, OnBnClickedConnect)
	ON_BN_CLICKED(IDC_CLOSE, OnBnClickedClose)
END_MESSAGE_MAP()


// CTestDlg ��Ϣ�������

BOOL CTestDlg::OnInitDialog()
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
	
	return TRUE;  // ���������˿ؼ��Ľ��㣬���򷵻� TRUE
}

void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestDlg::OnPaint() 
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
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestDlg::OnBnClickedCancel()
{
	OnCancel();
}

void CTestDlg::OnBnClickedConnect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData( TRUE );
    RASDIALPARAMS rdParams;
    rdParams.dwSize = sizeof(RASDIALPARAMS);
	rdParams.szEntryName[0] = '\0';

	CString photo = "";//���ڴ���û�����ĵ绰����
	GetDlgItem(IDC_EDIT3)->GetWindowText(photo);

	if( photo == "" ){
		MessageBox("������绰���룡", "��Ϣ��ʾ����", MB_OK);
		return ;
	}
	lstrcpy( rdParams.szPhoneNumber, photo);
	rdParams.szCallbackNumber[0] = '\0';

	CString name = "";//���ڴ���û�����
	GetDlgItem(IDC_EDIT1)->GetWindowText(name);

	if( name == "" ){
		MessageBox("�������û�������", "��Ϣ��ʾ����", MB_OK);
		return ;
	}

	lstrcpy( rdParams.szUserName, name );

	CString password = "";//���ڴ���û������������Ϣ��
	GetDlgItem(IDC_EDIT2)->GetWindowText(password);

	if( password == "" ){
		MessageBox("�������û����룡", "��Ϣ��ʾ����", MB_OK);
		return ;
	}
	lstrcpy( rdParams.szPassword, password);
	rdParams.szDomain[0] = '\0';
	HRASCONN hRasConn = NULL;
    DWORD dwRet = RasDial( NULL, NULL, &rdParams, 0L, NULL, &hRasConn );
    if ( dwRet == 0 )  return ;
    char  szBuf[256];
	if ( RasGetErrorString( (UINT)dwRet, (LPSTR)szBuf, 256 ) != 0 )
		wsprintf( (LPSTR)szBuf, "δ֪���Ŵ��� (%ld).", dwRet );
	RasHangUp( hRasConn );
	MessageBox( (LPSTR)szBuf, "��Ϣ��ʾ����", MB_OK | MB_ICONSTOP );	
}

void CTestDlg::OnBnClickedClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	RASCONN ras[20];
	DWORD  dSize, dNumber;
	char  szBuf[256];	
	ras[0].dwSize = sizeof( RASCONN );
	dSize = sizeof( ras );   
	DWORD  dwRet = RasEnumConnections( ras, &dSize, &dNumber );
	if ( dwRet != 0 )
	{
		if ( RasGetErrorString( (UINT)dwRet, (LPSTR)szBuf, 256 ) != 0 )
			wsprintf( (LPSTR)szBuf, "δ�������Ӵ��� (%ld).", dwRet );
		MessageBox( (LPSTR)szBuf, "��Ϣ��ʾ����", MB_OK | MB_ICONSTOP );
		return ;
	}
	for( DWORD dCount = 0;  dCount < dNumber;  dCount++ )
	{   
		HRASCONN hRasConn = ras[dCount].hrasconn;
		DWORD dwRet = RasHangUp( hRasConn );
		if ( dwRet != 0 )
		{
			char  szBuf[256];
			if ( RasGetErrorString( (UINT)dwRet, (LPSTR)szBuf, 256 ) != 0 )
				wsprintf( (LPSTR)szBuf, "Undefined RAS HangUp Error (%ld).", dwRet );
			MessageBox( (LPSTR)szBuf, "RasHangUp", MB_OK | MB_ICONSTOP );
		}
	}	
}
