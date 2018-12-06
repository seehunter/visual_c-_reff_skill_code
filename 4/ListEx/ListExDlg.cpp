// ListExDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ListEx.h"
#include "ListExDlg.h"
#include ".\listexdlg.h"

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


// CListExDlg �Ի���



CListExDlg::CListExDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListExDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_SourData);
	DDX_Control(pDX, IDC_LIST2, m_AimData);
}

BEGIN_MESSAGE_MAP(CListExDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDB_ADD, OnBnClickedAdd)
	ON_BN_CLICKED(IDB_DELETE, OnBnClickedDelete)
	ON_BN_CLICKED(IDB_CLEAR, OnBnClickedClear)
END_MESSAGE_MAP()


// CListExDlg ��Ϣ��������

BOOL CListExDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��\������...\���˵������ӵ�ϵͳ�˵��С�

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

	m_SourData.AddString("ʾ��һ");
	m_SourData.AddString("ʾ����");
	m_SourData.AddString("ʾ����");
	m_SourData.AddString("ʾ����");
	m_SourData.AddString("ʾ����");
	m_SourData.AddString("ʾ����");
	m_SourData.AddString("ʾ����");
	m_SourData.AddString("ʾ����");
	m_SourData.SetCurSel(0);

	//// TODO: �ڴ����Ӷ���ĳ�ʼ������

	
	return TRUE;  // ���������˿ؼ��Ľ��㣬���򷵻� TRUE
}

void CListExDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CListExDlg::OnPaint() 
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
HCURSOR CListExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CListExDlg::OnBnClickedAdd()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������

	CString str;
	//for (int i = 0; i < m_SourData.GetCount(); i++){
		/*if (m_SourData.GetSel(i)){
			m_SourData.GetText(i, str);
			m_AimData.AddString(str);
		}*/

		m_SourData.GetText(m_SourData.GetCurSel(), str);
		m_AimData.AddString(str);

	//}
}

void CListExDlg::OnBnClickedDelete()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������

	for (int i = m_AimData.GetCount() - 1; i > -1; i--){
		if (m_AimData.GetSel(i))	{
			m_AimData.DeleteString(i);
		}
	}
}

void CListExDlg::OnBnClickedClear()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������

	m_AimData.ResetContent(); 	
}