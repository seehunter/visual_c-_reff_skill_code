// StudyTreeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudyTree.h"
#include "StudyTreeDlg.h"
#include ".\studytreedlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CStudyTreeDlg 对话框



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


// CStudyTreeDlg 消息处理程序

BOOL CStudyTreeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将\“关于...\”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	CStudyTreeApp *pApp=(CStudyTreeApp *)AfxGetApp();//创建图象列表

	Cil1.Create(16,16,ILC_COLOR,2,2);

	Cil1.Add(pApp->LoadIcon(IDI_PM));//加载图标

	Cil1.Add(pApp->LoadIcon(IDI_CJ));

	m_TreeCtrl.SetImageList(&Cil1,TVSIL_NORMAL); 

	DWORD dwStyles=GetWindowLong(m_TreeCtrl.m_hWnd,GWL_STYLE);

	dwStyles|=TVS_EDITLABELS|TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT;

	SetWindowLong(m_TreeCtrl.m_hWnd,GWL_STYLE,dwStyles);

	char * CJ[4]={"根节点一","根节点二","根节点三","根节点四"};//创建根节点名称

	char * PM[4][5]={

		{"节点一一","节点一二","节点一三","节点一四","节点一五"},//创建子节点名称

		{"节点二一","节点二二","节点二三","节点二四","节点二五"},

		{"节点三一","节点三二","节点三三","节点三四","节点三五"},

		{"节点四一","节点四二","节点四三","节点四四","节点四五"}
	};

	int i,j;

	HTREEITEM hRoot,hCur;

	TV_INSERTSTRUCT TCItem;

	TCItem.hParent = TVI_ROOT;//增加根项

	TCItem.hInsertAfter = TVI_LAST;//在最后项之后

	TCItem.item.mask = TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;//设屏蔽

	TCItem.item.pszText = "数据选择";

	TCItem.item.lParam = 0;//序号

	TCItem.item.iImage = 0;//正常图标

	TCItem.item.iSelectedImage = 1;//选中时图标

	hRoot = m_TreeCtrl.InsertItem(&TCItem);//返回根项句柄

	for(i = 0; i < 4; i++){//增加各厂家

		TCItem.hParent = hRoot;
	
		TCItem.item.pszText = CJ[i];

		TCItem.item.lParam = ( i + 1 ) * 10;//子项序号

		hCur = m_TreeCtrl.InsertItem( &TCItem);

		for(j = 0; j < 5; j++){//增加各产品
		
			TCItem.hParent = hCur;

			TCItem.item.pszText = PM[i][j];

			TCItem.item.lParam = ( i + 1 ) * 10 + ( j + 1 );//子项序号

			m_TreeCtrl.InsertItem( &TCItem );
	
		}

		m_TreeCtrl.Expand(hCur,TVE_EXPAND);//展开树

	}

	m_TreeCtrl.Expand(hRoot,TVE_EXPAND);//展开上一级树


	
	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CStudyTreeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
HCURSOR CStudyTreeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CStudyTreeDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码

	HTREEITEM hSel = m_TreeCtrl.GetSelectedItem();//返回选择项句柄

	if(hSel == NULL) return;

	static int nAddNo = 100;

	TV_INSERTSTRUCT TCItem;

	TCItem.hParent = hSel; //父项句柄

	TCItem.hInsertAfter = TVI_LAST;

	TCItem.item.mask = TVIF_TEXT | TVIF_PARAM | TVIF_IMAGE | TVIF_SELECTEDIMAGE;

	TCItem.item.pszText = "新增数据";

	TCItem.item.lParam = nAddNo++;//索引号增加

	TCItem.item.iImage = 0;//加载正常图标

	TCItem.item.iSelectedImage = 1;//加载选中时图标

	HTREEITEM hInsert = m_TreeCtrl.InsertItem(&TCItem);//增加

	m_TreeCtrl.Expand(hSel,TVE_EXPAND);

	m_TreeCtrl.EditLabel(hInsert);//修改增加的数据


}

void CStudyTreeDlg::OnBnClickedDel()
{
	// TODO: 在此添加控件通知处理程序代码

	HTREEITEM hSel=m_TreeCtrl.GetSelectedItem();//取得选项句柄;

	if(hSel==NULL) return;//无任何选项则返回

	if(m_TreeCtrl.ItemHasChildren(hSel))//判断是否有子项

	if(MessageBox("当前节点下有子节点,一同删除?","信息提示窗口",MB_YESNO)==IDNO) return;

	m_TreeCtrl.DeleteItem(hSel);


}

void CStudyTreeDlg::OnBnClickedSror()
{
	// TODO: 在此添加控件通知处理程序代码

	HTREEITEM hSel=m_TreeCtrl.GetSelectedItem();//取得选项句柄;

	if(hSel==NULL) return;//无任何选项则返回

	m_TreeCtrl.SortChildren(hSel);


}

void CStudyTreeDlg::OnBnClickedLook()
{
	// TODO: 在此添加控件通知处理程序代码

	HTREEITEM hSel=m_TreeCtrl.GetSelectedItem();//取得选项句柄;

	if(hSel==NULL) return;//无任何选项则返回

	CString cText=m_TreeCtrl.GetItemText(hSel);//取得数据项名

	LONG IDs=m_TreeCtrl.GetItemData(hSel);//取得数据项序号

	char temp[100];

	wsprintf(temp,"节点:%s 编号:%05d",cText,IDs);

	MessageBox(temp,"选择信息");


}

void CStudyTreeDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialog::OnRButtonDown(nFlags, point);
}

void CStudyTreeDlg::OnTvnEndlabeleditTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVDISPINFO pTVDispInfo = reinterpret_cast<LPNMTVDISPINFO>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	//TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;

// TODO: Add your control notification handler code here

	if(pTVDispInfo->item.pszText==0) return;//用户取消修改操作

	m_TreeCtrl.SetItemText(pTVDispInfo->item.hItem,

	pTVDispInfo->item.pszText);//设置新数据

	*pResult = 0;


}

void CStudyTreeDlg::OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码

	HTREEITEM hTreeItem = m_TreeCtrl.GetSelectedItem();
	CString S1 = m_TreeCtrl.GetItemText(hTreeItem);
	AfxMessageBox("You have selected "+S1);

	*pResult = 0;
}
