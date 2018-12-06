// OLEDBView.cpp : implementation of the COLEDBView class
//

#include "stdafx.h"
#include "OLEDB.h"

#include "OLEDBSet.h"
#include "OLEDBDoc.h"
#include "OLEDBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COLEDBView

IMPLEMENT_DYNCREATE(COLEDBView, COleDBRecordView)

BEGIN_MESSAGE_MAP(COLEDBView, COleDBRecordView)
	//{{AFX_MSG_MAP(COLEDBView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, COleDBRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COLEDBView construction/destruction

COLEDBView::COLEDBView()
	: COleDBRecordView(COLEDBView::IDD)
{
	//{{AFX_DATA_INIT(COLEDBView)
	m_pSet = NULL;
	m_Name = _T("");
	m_Sex = _T("");
	m_Grade = 0;
	m_Age = 0;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

COLEDBView::~COLEDBView()
{
}

void COLEDBView::DoDataExchange(CDataExchange* pDX)
{
	COleDBRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COLEDBView)
	DDX_Text(pDX, IDC_NAME, m_Name);
	DDX_Text(pDX, IDC_SEX, m_Sex);
	DDX_Text(pDX, IDC_GRADE, m_Grade);
	DDX_Text(pDX, IDC_AGE, m_Age);
	//}}AFX_DATA_MAP
}

BOOL COLEDBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return COleDBRecordView::PreCreateWindow(cs);
}

void COLEDBView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_oLEDBSet;
	{
		CWaitCursor wait;
		HRESULT hr = m_pSet->Open();
		if (hr != S_OK)
		{
			AfxMessageBox(_T("Record set failed to open."), MB_OK);
			// Disable the Next and Previous record commands,
			// since attempting to change the current record without an
			// open RecordSet will cause a crash.
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}				
	}
	COleDBRecordView::OnInitialUpdate();

}

/////////////////////////////////////////////////////////////////////////////
// COLEDBView printing

BOOL COLEDBView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COLEDBView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COLEDBView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COLEDBView diagnostics

#ifdef _DEBUG
void COLEDBView::AssertValid() const
{
	COleDBRecordView::AssertValid();
}

void COLEDBView::Dump(CDumpContext& dc) const
{
	COleDBRecordView::Dump(dc);
}

COLEDBDoc* COLEDBView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COLEDBDoc)));
	return (COLEDBDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COLEDBView database support
CRowset* COLEDBView::OnGetRowset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// COLEDBView message handlers



BOOL COLEDBView::OnMove(UINT nIDMoveCommand) 
{

	if (!UpdateData())
		return TRUE;
	m_pSet->SetData(0);

	HRESULT hr = E_UNEXPECTED;
	switch (nIDMoveCommand)
	{
		case ID_RECORD_PREV:
			hr = m_pSet->MovePrev();
			if (hr != S_OK)
				m_bOnFirstRecord = TRUE;
			else
				m_bOnLastRecord  = FALSE;
			break;

		case ID_RECORD_FIRST:
			hr = m_pSet->MoveFirst();
			if (hr == S_OK)
			{
				m_bOnFirstRecord = TRUE;
				m_bOnLastRecord  = FALSE;
			}
			break;

		case ID_RECORD_NEXT:
			hr = m_pSet->MoveNext();
			if (hr == S_OK)
				m_bOnFirstRecord = FALSE;
			else
				m_bOnLastRecord  = TRUE;
			break;

		case ID_RECORD_LAST:
			hr = m_pSet->MoveLast();
			if (hr == S_OK)
			{
				m_bOnFirstRecord = FALSE;
				m_bOnLastRecord  = TRUE;
			}
			break;

		default:
			// Unexpected case value
			ASSERT(FALSE);
	}
    m_Name = m_pSet->m_name;
	m_Sex = m_pSet->m_sex;
    m_Age = m_pSet->m_age;
	m_Grade = m_pSet->m_grade;
    	UpdateData(FALSE);

	if (hr != S_OK)
		return FALSE;

	return COleDBRecordView::OnMove(nIDMoveCommand);
}
