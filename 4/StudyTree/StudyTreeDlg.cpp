// StudyTreeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudyTree.h"
#include "StudyTreeDlg.h"
#include ".\studytreedlg.h"

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


// CStudyTreeDlg �Ի���



CStudyTreeDlg::CStudyTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudyTreeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudyTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_TreeCtrl);
}

BEGIN_MESSAGE_MAP(CStudyTreeDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_ADD, OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DEL, OnBnClickedDel)
	ON_BN_CLICKED(IDC_SROR, OnBnClickedSror)
	ON_BN_CLICKED(IDC_LOOK, OnBnClickedLook)
	ON_WM_RBUTTONDOWN()
	ON_NOTIFY(TVN_ENDLABELEDIT, IDC_TREE1, OnTvnEndlabeleditTree1)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, OnNMDblclkTree1)
END_MESSAGE_MAP()


// CStudyTreeDlg ��Ϣ�������

BOOL CStudyTreeDlg::OnInitDialog()
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

	CStudyTreeApp *pApp=(CStudyTreeApp *)AfxGetApp();//����ͼ���б�

	Cil1.Create(16,16,ILC_COLOR,2,2);

	Cil1.Add(pApp->LoadIcon(IDI_PM));//����ͼ��

	Cil1.Add(pApp->LoadIcon(IDI_CJ));

	m_TreeCtrl.SetImageList(&Cil1,TVSIL_NORMAL); 

	DWORD dwStyles=GetWindowLong(m_TreeCtrl.m_hWnd,GWL_STYLE);

	dwStyles|=TVS_EDITLABELS|TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT;

	SetWindowLong(m_TreeCtrl.m_hWnd,GWL_STYLE,dwStyles);

	char * CJ[4]={"���ڵ�һ","���ڵ��","���ڵ���","���ڵ���"};//�������ڵ�����

	char * PM[4][5]={

		{"�ڵ�һһ","�ڵ�һ��","�ڵ�һ��","�ڵ�һ��","�ڵ�һ��"},//�����ӽڵ�����

		{"�ڵ��һ","�ڵ����","�ڵ����","�ڵ����","�ڵ����"},

		{"�ڵ���һ","�ڵ�����","�ڵ�����","�ڵ�����","�ڵ�����"},

		{"�ڵ���һ","�ڵ��Ķ�","�ڵ�����","�ڵ�����","�ڵ�����"}
	};

	int i,j;

	HTREEITEM hRoot,hCur;

	TV_INSERTSTRUCT TCItem;

	TCItem.hParent = TVI_ROOT;//���Ӹ���

	TCItem.hInsertAfter = TVI_LAST;//�������֮��

	TCItem.item.mask = TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;//������

	TCItem.item.pszText = "����ѡ��";

	TCItem.item.lParam = 0;//���

	TCItem.item.iImage = 0;//����ͼ��

	TCItem.item.iSelectedImage = 1;//ѡ��ʱͼ��

	hRoot = m_TreeCtrl.InsertItem(&TCItem);//���ظ�����

	for(i = 0; i < 4; i++){//���Ӹ�����

		TCItem.hParent = hRoot;
	
		TCItem.item.pszText = CJ[i];

		TCItem.item.lParam = ( i + 1 ) * 10;//�������

		hCur = m_TreeCtrl.InsertItem( &TCItem);

		for(j = 0; j < 5; j++){//���Ӹ���Ʒ
		
			TCItem.hParent = hCur;

			TCItem.item.pszText = PM[i][j];

			TCItem.item.lParam = ( i + 1 ) * 10 + ( j + 1 );//�������

			m_TreeCtrl.InsertItem( &TCItem );
	
		}

		m_TreeCtrl.Expand(hCur,TVE_EXPAND);//չ����

	}

	m_TreeCtrl.Expand(hRoot,TVE_EXPAND);//չ����һ����


	
	return TRUE;  // ���������˿ؼ��Ľ��㣬���򷵻� TRUE
}

void CStudyTreeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CStudyTreeDlg::OnPaint() 
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
HCURSOR CStudyTreeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CStudyTreeDlg::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	HTREEITEM hSel = m_TreeCtrl.GetSelectedItem();//����ѡ������

	if(hSel == NULL) return;

	static int nAddNo = 100;

	TV_INSERTSTRUCT TCItem;

	TCItem.hParent = hSel; //������

	TCItem.hInsertAfter = TVI_LAST;

	TCItem.item.mask = TVIF_TEXT | TVIF_PARAM | TVIF_IMAGE | TVIF_SELECTEDIMAGE;

	TCItem.item.pszText = "��������";

	TCItem.item.lParam = nAddNo++;//����������

	TCItem.item.iImage = 0;//��������ͼ��

	TCItem.item.iSelectedImage = 1;//����ѡ��ʱͼ��

	HTREEITEM hInsert = m_TreeCtrl.InsertItem(&TCItem);//����

	m_TreeCtrl.Expand(hSel,TVE_EXPAND);

	m_TreeCtrl.EditLabel(hInsert);//�޸����ӵ�����


}

void CStudyTreeDlg::OnBnClickedDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	HTREEITEM hSel=m_TreeCtrl.GetSelectedItem();//ȡ��ѡ����;

	if(hSel==NULL) return;//���κ�ѡ���򷵻�

	if(m_TreeCtrl.ItemHasChildren(hSel))//�ж��Ƿ�������

	if(MessageBox("��ǰ�ڵ������ӽڵ�,һͬɾ��?","��Ϣ��ʾ����",MB_YESNO)==IDNO) return;

	m_TreeCtrl.DeleteItem(hSel);


}

void CStudyTreeDlg::OnBnClickedSror()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	HTREEITEM hSel=m_TreeCtrl.GetSelectedItem();//ȡ��ѡ����;

	if(hSel==NULL) return;//���κ�ѡ���򷵻�

	m_TreeCtrl.SortChildren(hSel);


}

void CStudyTreeDlg::OnBnClickedLook()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	HTREEITEM hSel=m_TreeCtrl.GetSelectedItem();//ȡ��ѡ����;

	if(hSel==NULL) return;//���κ�ѡ���򷵻�

	CString cText=m_TreeCtrl.GetItemText(hSel);//ȡ����������

	LONG IDs=m_TreeCtrl.GetItemData(hSel);//ȡ�����������

	char temp[100];

	wsprintf(temp,"�ڵ�:%s ���:%05d",cText,IDs);

	MessageBox(temp,"ѡ����Ϣ");


}

void CStudyTreeDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialog::OnRButtonDown(nFlags, point);
}

void CStudyTreeDlg::OnTvnEndlabeleditTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVDISPINFO pTVDispInfo = reinterpret_cast<LPNMTVDISPINFO>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;

// TODO: Add your control notification handler code here

	if(pTVDispInfo->item.pszText==0) return;//�û�ȡ���޸Ĳ���

	m_TreeCtrl.SetItemText(pTVDispInfo->item.hItem,

	pTVDispInfo->item.pszText);//����������

	*pResult = 0;


}

void CStudyTreeDlg::OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	HTREEITEM hTreeItem = m_TreeCtrl.GetSelectedItem();
	CString S1 = m_TreeCtrl.GetItemText(hTreeItem);
	AfxMessageBox("You have selected "+S1);

	*pResult = 0;
}
