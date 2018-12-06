// PageSetupDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PageSetup.h"
#include "PageSetupDlg.h"
#include ".\pagesetupdlg.h"

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


// CPageSetupDlg �Ի���



CPageSetupDlg::CPageSetupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPageSetupDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPageSetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PORTRAIT, M_Way);
}

BEGIN_MESSAGE_MAP(CPageSetupDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_PAGESETUP, OnBnClickedPagesetup)
END_MESSAGE_MAP()


// CPageSetupDlg ��Ϣ�������

BOOL CPageSetupDlg::OnInitDialog()
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

void CPageSetupDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPageSetupDlg::OnPaint() 
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
HCURSOR CPageSetupDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPageSetupDlg::OnBnClickedPagesetup()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CPageSetupDialog PageDlg;

	PageDlg.m_psd.rtMargin.bottom = 100;
	PageDlg.m_psd.rtMargin.left = 100;

	if(PageDlg.DoModal()==IDOK)
	{
		//�û�����ȷ���󣬿���ͨ��PageDlg���������Ա����������û�ѡ���ҳ����Ϣ��

		CWnd* pWnd = NULL;

		pWnd = GetDlgItem(IDC_DEVICE_NAME);//��ô�ӡ������

		if( pWnd != NULL ){

			pWnd->SetWindowText( PageDlg.GetDeviceName() );
		}


		LPDEVMODE mode = NULL;

		mode = PageDlg.GetDevMode();

		pWnd = NULL;

		pWnd = GetDlgItem(IDC_LARGE);//�����ѡֽ���ͺ�

		if( pWnd != NULL ){

			CString name = ( CString )mode->dmFormName;

			pWnd->SetWindowText(name);

		}

		if( mode->dmDefaultSource == 7 ){//����ֽ����Դ

			GetDlgItem(IDC_SOURCE)->SetWindowText("�Զ�ѡ��");
		}else {

			GetDlgItem(IDC_SOURCE)->SetWindowText("�ֶ���ֽ");

		}

		if( mode->dmOrientation == 1 ){//����ֽ�Ŵ�ӡ����
			( ( CButton* )GetDlgItem(IDC_ROW) )->SetCheck(FALSE);
			( ( CButton* )GetDlgItem(IDC_PORTRAIT) )->SetCheck(TRUE);
		}else {

			( ( CButton* )GetDlgItem(IDC_ROW) )->SetCheck(TRUE);
			( ( CButton* )GetDlgItem(IDC_PORTRAIT) )->SetCheck(FALSE);
		}

		RECT rect1;
		RECT rect2;

		PageDlg.GetMargins(&rect1, &rect2);//����û������ҳ�߾�

		char len[10];
		itoa(rect1.left * 0.01, len, 10);
		CString marge = len;
		
		GetDlgItem(IDC_LEFT)->SetWindowText( marge );
		itoa(rect1.bottom * 0.01, len, 10);
		marge = len;
		GetDlgItem(IDC_DOWN)->SetWindowText( marge );
		itoa(rect1.right * 0.01, len, 10);
		marge = len;
		GetDlgItem(IDC_RIGHT)->SetWindowText( marge );
		itoa(rect1.top * 0.01, len, 10);
		marge = len;
		GetDlgItem(IDC_UP)->SetWindowText( marge );

		int error = ::GetLastError();

		UpdateData(FALSE);
	}

}
