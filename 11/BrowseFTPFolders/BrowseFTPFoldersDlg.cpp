// BrowseFTPFoldersDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BrowseFTPFolders.h"
#include "BrowseFTPFoldersDlg.h"
#include ".\browseftpfoldersdlg.h"

#include "afxinet.h"

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


// CBrowseFTPFoldersDlg �Ի���



CBrowseFTPFoldersDlg::CBrowseFTPFoldersDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBrowseFTPFoldersDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBrowseFTPFoldersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CBrowseFTPFoldersDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_LOOK, OnBnClickedLook)
END_MESSAGE_MAP()


// CBrowseFTPFoldersDlg ��Ϣ�������

BOOL CBrowseFTPFoldersDlg::OnInitDialog()
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

	DWORD dwExStyle = LVS_EX_GRIDLINES ;
	m_ListCtrl.SetExtendedStyle(dwExStyle);

	m_ListCtrl.InsertColumn(0,"�ļ�/�ļ���",LVCFMT_CENTER,200);
	m_ListCtrl.InsertColumn(1,"����",LVCFMT_CENTER,100);
	
	return TRUE;  // ���������˿ؼ��Ľ��㣬���򷵻� TRUE
}

void CBrowseFTPFoldersDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBrowseFTPFoldersDlg::OnPaint() 
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
HCURSOR CBrowseFTPFoldersDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBrowseFTPFoldersDlg::OnBnClickedLook()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);
	//�½�CInternetSession����
	m_pIntSession = new CInternetSession(AfxGetAppName(),1,PRE_CONFIG_INTERNET_ACCESS);
	try 
	{ 
		//�½����Ӷ���
		CString ftp = "";
		GetDlgItem(IDC_FTP)->GetWindowText(ftp);
		if( ftp == "" ){
			MessageBox("������FTP��ַ��", "��Ϣ��ʾ����", MB_OK);
			return;
		}

		CString name = "";
		GetDlgItem(IDC_NAME)->GetWindowText(name);
		if( name == "" ){
			MessageBox("������FTP��ַ��", "��Ϣ��ʾ����", MB_OK);
			return;
		}

		CString password = "";
		GetDlgItem(IDC_PASSWORD)->GetWindowText(password);
		if( password == "" ){
			MessageBox("������FTP��ַ��", "��Ϣ��ʾ����", MB_OK);
			return;
		}
		m_pFTPConnection = m_pIntSession->GetFtpConnection(ftp, name, password); 

		ASSERT(m_pFTPConnection);

		MessageBox("FTP���������ӳɹ���", "��Ϣ��ʾ����", MB_OK);
		return;

	} 
	catch(CInternetException *pEx) 
	{
		//��ȡ������Ϣ
		TCHAR szError[1024];
		if(pEx->GetErrorMessage(szError,1024))
			AfxMessageBox(szError);
		else  
			AfxMessageBox("�����������");
		pEx->Delete();
		m_pFTPConnection = NULL;
		return;
	}

	m_pRemoteFinder = new CFtpFileFind(m_pFTPConnection);
	//��÷�������Ŀ¼�������ļ������б������ʾ
	BrowseFolder("",&m_ListCtrl,m_pRemoteFinder,&m_ArrayRemoteFiles);
}


void CBrowseFTPFoldersDlg::BrowseFolder(CString strDir,CListCtrl* pLstCtrl,CFileFind* pFinder,CArray<FILEITEM,FILEITEM&>* pFilesArr)
{
	//����б��
	pLstCtrl->DeleteAllItems();
	pFilesArr->RemoveAll();
	int nIndex = 0;	
	CString szDir = strDir;
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	szDir += "*.*";	
	//����Ŀ¼�µ��ļ�
	BOOL res = pFinder->FindFile(szDir);
	while(res)
	{
		res = pFinder->FindNextFile();
		//��Ŀ¼
		if(pFinder->IsDirectory() && !pFinder->IsDots())
		{
			FILEITEM fileitem;
			fileitem.nItem = nIndex;
			fileitem.bDir = TRUE;
			fileitem.StrFileName = pFinder->GetFileName();
			pFilesArr->Add(fileitem);
			AddItem(pLstCtrl,nIndex,TRUE,pFinder->GetFileName());
		}
		//���ļ�
		else if(!pFinder->IsDirectory() && !pFinder->IsDots())
		{
			FILEITEM fileitem;
			fileitem.nItem = nIndex;
			fileitem.bDir = FALSE;
			fileitem.StrFileName = pFinder->GetFileName();
			pFilesArr->Add(fileitem);
			AddItem(pLstCtrl,nIndex,FALSE,pFinder->GetFileName());			
		}		
		nIndex++;
	}
}
//���б������һ����¼
void CBrowseFTPFoldersDlg::AddItem(CListCtrl* pLstCtrl,int nIndex,BOOL bDir,CString strText)
{
	LV_ITEM lvitem;
	int iActualItem;
	for(int iSubItem=0;iSubItem<2;iSubItem++)
	{
		lvitem.mask = LVIF_TEXT|(iSubItem == 0? LVIF_IMAGE : 0);
		lvitem.iItem = (iSubItem == 0)? nIndex : iActualItem;
		lvitem.iSubItem = iSubItem;
		switch(iSubItem)
		{
		case 0:
			lvitem.pszText =(LPTSTR)(LPCTSTR)strText;
			break;
		case 1:
			if(bDir)
				lvitem.pszText = "�ļ���";
			else
				lvitem.pszText = "�ļ�";
			break;
		} 
		if (iSubItem == 0)
			iActualItem = pLstCtrl->InsertItem(&lvitem);
		else
			pLstCtrl->SetItem(&lvitem);
	}
}
