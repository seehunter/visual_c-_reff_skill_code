/*======================================================
*�ļ���: OpWord.cpp
*����  : ����WORD
======================================================*/
#include "stdafx.h"
#include "OpWord.h"
#include <comdef.h>


/*======================================================
��  ��: ���캯��
======================================================*/
COpWord::COpWord( )
{
	m_bSave = FALSE;
	m_bInit = FALSE;
	m_nOldX = -1;
	m_nOldY = -1;
	m_nHeight = -1;
}

/*======================================================
��  ��: �鹹����
======================================================*/
COpWord::~COpWord( )
{
	m_Doc.ReleaseDispatch();
	m_Docs.ReleaseDispatch();
    m_Sel.ReleaseDispatch();
	pm_App->ReleaseDispatch( );
//	::CoUninitialize();
}

/*======================================================
��  ��: ��ʼ����COM���Զ���
����ֵ: bool Falseʧ�ܣ�true �ɹ�
======================================================*/
BOOL COpWord::FileInit( )
{
  //��ʼ��Com��
	if ( !AfxOleInit( ) )
	{
		AfxMessageBox("��ʼ��COM��ʧ��");
		return FALSE;
	}
	
	//����Ӧ�ö���,��WordӦ�ó���
	pm_App = new _Application;
	if( !pm_App->CreateDispatch("Word.Application", NULL) )
	{
		AfxMessageBox("����ʧ�ܣ�", MB_OK ); 
		pm_App->ReleaseDispatch( );
		::CoUninitialize();
		return FALSE;
	}

	pm_App->SetVisible( TRUE );//WordӦ�ó��򴰿ڿɼ�
	if( !AddTemplate( ) )//���ģ�壬�½�Word�ļ�
	{
		return FALSE;
	}
	m_bInit = TRUE;
	return TRUE;
}
/*======================================================
��  ��: ���ģ��
����ֵ: BOOL TRUE��ӳɹ� FALSE���ʧ��
======================================================*/
BOOL COpWord::AddTemplate()
{
	CFile tempFile;

	tempFile.Open( "temp.doc", CFile::modeCreate | CFile::modeWrite, NULL );
	m_temp = tempFile.GetFilePath( );
	tempFile.Close( );

	m_Docs = pm_App->GetDocuments();
	m_Docs.Add( (COleVariant)(_variant_t(m_temp)), COleVariant((long)0), &COleVariant((long)0), COleVariant((long)1));
	m_Doc =(_Document) pm_App->GetActiveDocument( );
	m_Sel =(Selection) pm_App->GetSelection( );

	return	TRUE;
}
/*======================================================
��  ��: ����ͼƬ
��  ��: CString strFileͼƬ�ļ���
	    nLeft ͼƬ���λ��
		nTop  ͼƬ����λ��
		nWidthͼƬ���
		nHeightͼƬ�߶�
======================================================*/
void COpWord::InsertPic( CString strFile, float fLeft, float fTop, float fWidth, float fHeight )
{
//	m_rng = m_Sel.GetRange( );
}

/*======================================================
��  ��: ֱ��д�ַ���strText��Word�ļ�
��  ��: bBefore FALSE��β������ַ���������ͷ������ַ���
		CString strText�ַ���
======================================================*/
void COpWord::WriteTextToFile( BOOL bBefore, BOOL bChangeLine,  CString strText, float fontsize )
{
	Range rng;
	_Font ft;
	if( m_bInit )
	{
		rng = m_Sel.GetRange( );
		if( bBefore )
		{
			rng.InsertBefore( strText );
			m_Sel.MoveLeft( &COleVariant((long)1), &COleVariant((long)strText.GetLength( ) ), &COleVariant((long)1) );
		}
		else
		{
			rng.InsertAfter( strText );
			m_Sel.MoveRight( &COleVariant((long)1), &COleVariant((long) strText.GetLength( ) ), &COleVariant((long) 1 ) );
		}
		if( bChangeLine )
		{
			m_Sel.InsertParagraphAfter( );		
		}
		ft = rng.GetFont( );
		ft.SetSize( fontsize );
		m_bSave = FALSE;
		m_Sel.EndKey( &COleVariant((long)6), &COleVariant((long)0) );
	}
}

/*======================================================
��  ��: ����rng��Χ�ڵ��ַ�������Ϊstrfont
��  ��: Range rng����ѡ���ַ���Χ��CString strfont��������
======================================================*/
void COpWord::SetFont(Range rng, CString strfont)
{
	_Font ft;

	ft = rng.GetFont( );
	ft.SetName( strfont );
}

/*======================================================
��  ��: ����rng��Χ�ڵ��ַ��������СΪnSize
��  ��: Range rng����ѡ���ַ���Χ��int nSize�����С
======================================================*/
void COpWord::SetTextSize(Range rng, float nSize)
{
	_Font ft;

	if( nSize <= 0 )
	{
		AfxMessageBox( "�����С����ΪС��0" );
		return ;
	}

	ft = rng.GetFont( );
	ft.SetSize( nSize );
}
/*======================================================
��  ��: ����rng��Χ�ڵ��ַ��������СΪnColor
��  ��: Range rng����ѡ���ַ���Χ��long nColor������ɫ
======================================================*/
void COpWord::SetTextColor(Range rng, long nColor )
{
	_Font ft;

	ft = rng.GetFont( );
	ft.SetColor( nColor );
}

/*======================================================
��  ��: ���ö���������ʽ
��  ��: ����nBlank
======================================================*/
void COpWord::SetParagraphFormat( float nBlank)
{
	_ParagraphFormat ParaFormat;

	if( nBlank <= 0 )
	{
		AfxMessageBox( "��������С��0" );
		return ;
	}
	
	ParaFormat = m_Sel.GetParagraphFormat( );
	ParaFormat.SetFirstLineIndent( nBlank );
	m_Sel.SetParagraphFormat( ParaFormat );
}
/*======================================================
��  ��: ���ö��뷽ʽ
��  ��: nAlignȡֵ��ALIGN_LEFT��ALIGN_RIGHT,ALIGN_CENTER
======================================================*/
void COpWord::SetParagraphAlign(unsigned int nAlign)
{
	_ParagraphFormat ParaFormat;

	if( nAlign != 0 || nAlign != 1 || nAlign != 2 )
	{
		AfxMessageBox( "���뷽ʽ����" );
		return ;
	}

	ParaFormat = m_Sel.GetParagraphFormat( );
	ParaFormat.SetAlignment( nAlign );
	m_Sel.SetParagraphFormat( ParaFormat );	
}
/*======================================================
������:AddTextBox(CString strText)
��  ��: ����ı���strText�ı�������
��  ��: strText�ı�������
	    fLeft �ı������λ��
		fTop  �ı��򶥲�λ��
		fWidth  �ı�����
		fHeigth �ı���߶�
======================================================*/
void COpWord::AddTextBox(CString strText, int nhorizontal, float fLeft, float fTop, float fWidth, float fHeight )
{
	int nLen = 0;
	VARIANT vLen;
	Shape Shp;
	float factor = 1;
	nLen = strText.GetLength( );
	vLen = COleVariant((long) nLen );
	ShapeRange ShapeRng;
	m_Sel.InsertBefore( strText );
	m_Sel.CreateTextbox( );
	ShapeRng =(ShapeRange)m_Sel.GetShapeRange( );
	float fl = ShapeRng.GetLeft( );
	float ft = ShapeRng.GetTop( );
	ShapeRng.IncrementLeft( ( fLeft - fl ) );
	ShapeRng.IncrementTop( ( fTop - ft ) );
	if( fTop >= 700 )
	{
		ShapeRng.IncrementTop( fHeight );
	}
	FillFormat fillfmt;
	fillfmt = ShapeRng.GetFill( );
	fillfmt.SetTransparency( 0.5 );
	WrapFormat wrapfmt;
	wrapfmt = ShapeRng.GetWrapFormat( );
	wrapfmt.SetType( 3 );
	ShapeRng.ZOrder( 5 );
	long nCount = ShapeRng.GetCount( );
	VARIANT vCount;
	vCount.vt = VT_I4;
	vCount.lVal = nCount;
	Shp = (Shape) ShapeRng.Item( &vCount );
	Shp.SetHeight( fHeight );
	Shp.SetWidth( fWidth );
	LineFormat Linefmt = (LineFormat) Shp.GetLine( );
	Linefmt.SetVisible( 0 );
	m_Sel.EndKey( &COleVariant((long)6), &COleVariant((long)0) );
	
}
/*======================================================
��  ��: ����Word�ļ��ر�WordӦ�ó���
======================================================*/
BOOL COpWord::SaveDocument()
{
	if( m_bInit )
	{
		if( !m_bSave )
		{
			CString strFile;
			CFile ResFile;
			
			VARIANT vt ;
			vt.vt =VT_ERROR;
			vt.scode =DISP_E_PARAMNOTFOUND;
			VARIANT varFileName;
			VariantInit(&varFileName);
			varFileName.vt =VT_BSTR;
			
			CFileDialog SaveDlg( FALSE, "doc", NULL, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"Word�ĵ�|*.doc||",NULL);
			if( SaveDlg.DoModal( ) == IDOK )
			{
				strFile = SaveDlg.GetPathName( );
				if( ResFile.Open(strFile,CFile::modeWrite|CFile::modeCreate, NULL) )
				{
					ResFile.Close( );
					varFileName.bstrVal = _bstr_t(strFile);
					m_Doc.SaveAs( &varFileName, &vt, &vt, &vt,	&vt, &vt, &vt, &vt, &vt, &vt, &vt ,&vt,&vt,&vt,&vt,&vt);	
					VariantClear( &varFileName );
					//�˳�
//					m_Doc.Close( &COleVariant((long)0), &vt, &vt );
					m_Docs.Close( &COleVariant((long)0), &vt, &vt );
					pm_App->Quit( &COleVariant((long)0), &vt, &vt );
					CFile::Remove( m_temp );
					m_bSave = TRUE;
				}
				else
				{
					m_Doc.Close( &COleVariant((long)0), &vt, &vt );
					m_Docs.Close( &COleVariant((long)0), &vt, &vt );
					pm_App->Quit( &COleVariant((long)0), &vt, &vt );
					CFile::Remove( m_temp );
					AfxMessageBox( "�ļ����ظ�!" );
					return FALSE;
				}
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}
		else
		{
			return TRUE;
		}
	}
	return FALSE;
}
/************************************************************************/
/*����:�����ı���
/************************************************************************/
void COpWord::SetTextColumn(int nColumn)
{
	PageSetup psetup;
	TextColumns txtColumn;
	psetup = m_Doc.GetPageSetup( );
	txtColumn = psetup.GetTextColumns( );
	txtColumn.SetCount( nColumn );
}
/************************************************************************/
/*����ҳ�߾�
/************************************************************************/
void COpWord::SetMargin(float fLeft, float fRight)
{
	PageSetup psetup;
	psetup = m_Sel.GetPageSetup( );
	psetup.SetLeftMargin( fLeft );
	psetup.SetRightMargin( fRight );
}