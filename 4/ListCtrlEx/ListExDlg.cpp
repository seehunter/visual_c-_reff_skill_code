// ListExDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ListEx.h"
#include "ListExDlg.h"
#include ".\listexdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



int CALLBACK CompareFunc(LPARAM lParam1,LPARAM lParam2,LPARAM lParamSort)
{
     CListCtrl *p=(CListCtrl *)lParamSort;
    
     CString strItem1 = p->GetItemText(lParam1,0); 
     CString strItem2 = p->GetItemText(lParam2,0);

	 int item1 = atoi(strItem1);
	 int item2 = atoi(strItem2);

	 if( p->m_nFlags ){//1Ϊ����
		if( item1 <= item2 ){
  
			return -1;
		}else {
			 return 1;
		}
	 }else {//0Ϊ����

		 if( item1 >= item2 ){
  
			return -1;
		}else {
			 return 1;
		}
	 }
}


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
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BEGIN_MESSAGE_MAP(CListExDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_BEGINLABELEDIT, IDC_LIST1, OnLvnBeginlabeleditList1)
	ON_NOTIFY(LVN_ENDLABELEDIT, IDC_LIST1, OnLvnEndlabeleditList1)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, OnLvnColumnclickList1)
	ON_BN_CLICKED(IDC_ADD, OnBnClickedAdd)
END_MESSAGE_MAP()


// CListExDlg ��Ϣ�������

BOOL CListExDlg::OnInitDialog()
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
	/*CFontDialog Dlg;
	COLORREF TextColor; 
	if(Dlg.DoModal() == IDOK)
	{
		LOGFONT lfont;
		Dlg.GetCurrentFont(&lfont);
		
		CFont font;
		font.CreateFont(lfont.lfHeight, lfont.lfWidth, lfont.lfEscapement, lfont.lfOrientation, lfont.lfWeight, 
			lfont.lfItalic,lfont.lfUnderline, lfont.lfStrikeOut, lfont.lfCharSet, lfont.lfOutPrecision, lfont.lfClipPrecision, 
			lfont.lfQuality, lfont.lfPitchAndFamily, lfont.lfFaceName);

		m_List.SetFont(&font);

		int index = 0;
		m_List.InsertColumn(0, "����", LVCFMT_CENTER, 100);
		m_List.InsertItem(index, "");
		m_List.SetItemText(index, 0, "123");


	}*/

	DWORD dwExStyle = LVS_EX_GRIDLINES ;
	m_List.SetExtendedStyle(dwExStyle);

	m_List.InsertColumn(0,"����",LVCFMT_CENTER,100);
	m_List.InsertItem(0, "");
	m_List.SetItemText(0, 0, "123");
	m_List.InsertItem(0, "456", 0);

	
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

// �����Ի��������С����ť������Ҫ����Ĵ���
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

void CListExDlg::OnLvnBeginlabeleditList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLVDISPINFO *pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//GetListCtrl().GetEditControl()->LimitText(20); //�����ı���󳤶� 
	m_List.GetEditControl()->LimitText(20);
	*pResult = 0;
}

void CListExDlg::OnLvnEndlabeleditList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLVDISPINFO *pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString strText; 
	m_List.GetEditControl()->GetWindowText(strText); //��ȡ��ǰ�ı� 
	if (strText.GetLength() > 0) 
	{ 
		//** Get the selected item handle 
		int hSelected = pDispInfo->item.iItem; 
		int hSelected1 = pDispInfo->item.iSubItem; 
		//** Set the modified text 
		m_List.SetItemText(hSelected, hSelected1, strText); //���ú����ı� 
	} 

	*pResult = 0;
}

void CListExDlg::OnLvnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData();
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	for(int i = 0; i < m_List.GetItemCount(); i++){   
		m_List.SetItemData(i, i);   
	}

	m_List.m_nFlags = !m_List.m_nFlags;//1Ϊ����0Ϊ����

     m_List.SortItems(CompareFunc,(LPARAM)&m_List);

	for( i = 0; i < m_List.GetItemCount(); i++){   
		m_List.SetItemData(i, i);   
	}

	*pResult = 0;
}

void CListExDlg::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	int m_nCurrentSel = m_List.InsertItem(0xffff,"");

	CString con = "";
	GetDlgItem(IDC_EDIT1)->GetWindowText(con);

	m_List.SetItem( m_nCurrentSel, 0, LVIF_TEXT, con, NULL, 0, 0, 0);
}
