// PrintDialogDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PrintDialog.h"
#include "PrintDialogDlg.h"
#include ".\printdialogdlg.h"

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


// CPrintDialogDlg �Ի���



CPrintDialogDlg::CPrintDialogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintDialogDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPrintDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPrintDialogDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_PRINT_SETUP, OnBnClickedPrintSetup)
	ON_BN_CLICKED(IDC_PRINT, OnBnClickedPrint)
END_MESSAGE_MAP()


// CPrintDialogDlg ��Ϣ�������

BOOL CPrintDialogDlg::OnInitDialog()
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

void CPrintDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPrintDialogDlg::OnPaint() 
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
HCURSOR CPrintDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPrintDialogDlg::OnBnClickedPrintSetup()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CPrintDialog dlg(TRUE, PD_PAGENUMS | PD_USEDEVMODECOPIES);
	dlg.m_pd.nMinPage = dlg.m_pd.nFromPage = 1;//���ô�ӡ�Ի���ĳ�ʼ��ӡҳ
	dlg.m_pd.nMaxPage = dlg.m_pd.nToPage = 10;//���ô�ӡ�Ի���Ľ�����ӡҳ
	if( dlg.DoModal() == IDOK ){
		//�����û���ѡ����д�ӡ

		LPDEVMODE  mode = dlg.GetDevMode();

		CString large = ( CString )mode->dmFormName;

		GetDlgItem(IDC_LARGE)->SetWindowText(large);

		if( mode->dmDefaultSource == 7 ){

			GetDlgItem(IDC_SOURCE)->SetWindowText("�Զ�ѡ��");

		}else {

			GetDlgItem(IDC_SOURCE)->SetWindowText("�ֶ���ֽ");

		}

		if( mode->dmOrientation == 1 ){//����ֽ�Ŵ�ӡ����
			( ( CButton* )GetDlgItem(IDC_COL) )->SetCheck(FALSE);
			( ( CButton* )GetDlgItem(IDC_ROW) )->SetCheck(TRUE);
		}else {

			( ( CButton* )GetDlgItem(IDC_COL) )->SetCheck(TRUE);
			( ( CButton* )GetDlgItem(IDC_ROW) )->SetCheck(FALSE);
		}


		int error = ::GetLastError();
	}

}

void CPrintDialogDlg::OnBnClickedPrint()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CPrintDialog dlg(FALSE, PD_PAGENUMS | PD_USEDEVMODECOPIES);
	dlg.m_pd.nMinPage = dlg.m_pd.nFromPage = 1;//���ô�ӡ�Ի���ĳ�ʼ��ӡҳ
	dlg.m_pd.nMaxPage = dlg.m_pd.nToPage = 100;//���ô�ӡ�Ի���Ľ�����ӡҳ
	if( dlg.DoModal() == IDOK ){
		//�����û���ѡ����д�ӡ

		LPDEVMODE  mode = dlg.GetDevMode();

		char copy[10];//ʾ������ʵ��Ӧ���в���ʹ�ó���

		itoa(mode->dmCopies, copy, 10);

		CString copies = copy;

		GetDlgItem(IDC_SOME)->SetWindowText(copies);

		if( dlg.PrintAll()!= 0 ){

			( ( CButton* )GetDlgItem(IDC_ALL) )->SetCheck(TRUE);
			( ( CButton* )GetDlgItem(IDC_RANGE) )->SetCheck(FALSE);
			( ( CButton* )GetDlgItem(IDC_SELECT) )->SetCheck(FALSE);

			GetDlgItem(IDC_START)->SetWindowText("");
			GetDlgItem(IDC_END)->SetWindowText("");

		}else if( dlg.PrintSelection() != 0 ){

			( ( CButton* )GetDlgItem(IDC_ALL) )->SetCheck(FALSE);
			( ( CButton* )GetDlgItem(IDC_RANGE) )->SetCheck(FALSE);
			( ( CButton* )GetDlgItem(IDC_SELECT) )->SetCheck(TRUE);

			GetDlgItem(IDC_START)->SetWindowText("");
			GetDlgItem(IDC_END)->SetWindowText("");


		}else {

			( ( CButton* )GetDlgItem(IDC_ALL) )->SetCheck(FALSE);
			( ( CButton* )GetDlgItem(IDC_RANGE) )->SetCheck(TRUE);
			( ( CButton* )GetDlgItem(IDC_SELECT) )->SetCheck(FALSE);

			char range[10];//ʵ��Ӧ�ò�����ʹ�ó���

			itoa(dlg.GetFromPage(), range, 10);

			CString ranges  = range;

			GetDlgItem(IDC_START)->SetWindowText(ranges);
			
			itoa(dlg.GetToPage(), range, 10);
			ranges = range;
			GetDlgItem(IDC_END)->SetWindowText(ranges);

		}

		int error = ::GetLastError();

		MessageBox("���������ܴ�ӡ����ֻ����ʾ��", "��Ϣ��ʾ����", MB_OK);
	}
}
