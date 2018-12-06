// LookAndCheckDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LookAndCheck.h"
#include "LookAndCheckDlg.h"
#include ".\lookandcheckdlg.h"

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


// CLookAndCheckDlg �Ի���



CLookAndCheckDlg::CLookAndCheckDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLookAndCheckDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLookAndCheckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLookAndCheckDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_LOOK, OnBnClickedLook)
	ON_BN_CLICKED(IDC_REPLACE, OnBnClickedReplace)

	ON_REGISTERED_MESSAGE(WM_FINDREPLACE, OnFindReplace)
END_MESSAGE_MAP()


// CLookAndCheckDlg ��Ϣ�������

BOOL CLookAndCheckDlg::OnInitDialog()
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

void CLookAndCheckDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLookAndCheckDlg::OnPaint() 
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
HCURSOR CLookAndCheckDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLookAndCheckDlg::OnBnClickedLook()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CFindReplaceDialog *pDlg=new CFindReplaceDialog;
	if(!pDlg->Create(TRUE,0,0,FR_DOWN,this))//�����Ի���
	{
		return;
	}
	pDlg->SetActiveWindow();
	pDlg->ShowWindow(SW_SHOW);//��ʾ�Ի���

}

void CLookAndCheckDlg::OnBnClickedReplace()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CFindReplaceDialog *pDlg=new CFindReplaceDialog;
	if(!pDlg->Create(FALSE,0,0,FR_DOWN,this))//�����Ի���
	{
		return;
	}
	pDlg->SetActiveWindow();
	pDlg->ShowWindow(SW_SHOW);//��ʾ�Ի���
}


BOOL CLookAndCheckDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���

	/*if( pMsg->message == FINDMSGSTRING){
		MessageBox("�õ���Ϣ�ˣ�", "��Ϣ��ʾ����", MB_OK);
	}*/

	return CDialog::PreTranslateMessage(pMsg);
}


LONG CLookAndCheckDlg::OnFindReplace( WPARAM wparam, LPARAM lparam )
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	//MessageBox("�õ���Ϣ�ˣ�", "��Ϣ��ʾ����", MB_OK);

	CFindReplaceDialog* pDlg = CFindReplaceDialog::GetNotifier(lparam);
	
	if( NULL != pDlg ){

		if( pDlg->FindNext() ){
			MessageBox("�ҵ���һ����", "��Ϣ��ʾ����", MB_OK);

		}else if( pDlg->ReplaceAll() ){

			MessageBox("�滻�������ݣ�", "��Ϣ��ʾ����", MB_OK);

		}else if( pDlg->ReplaceCurrent() ){
			MessageBox("�滻��ǰ�", "��Ϣ��ʾ����", MB_OK);
		}
	}else{
		delete pDlg;
	}

	return 1;
	
}
