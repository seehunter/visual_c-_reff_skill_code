/*======================================================
*文件名: OpWord.cpp
*作用  : 操作WORD
======================================================*/
#include "stdafx.h"
#include "OpWord.h"
#include <comdef.h>


/*======================================================
功  能: 构造函数
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
功  能: 虚构函数
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
功  能: 初始化：COM和自动化
返回值: bool False失败，true 成功
======================================================*/
BOOL COpWord::FileInit( )
{
  //初始化Com，
	if ( !AfxOleInit( ) )
	{
		AfxMessageBox("初始化COM库失败");
		return FALSE;
	}
	
	//创建应用对象,打开Word应用程序
	pm_App = new _Application;
	if( !pm_App->CreateDispatch("Word.Application", NULL) )
	{
		AfxMessageBox("创建失败！", MB_OK ); 
		pm_App->ReleaseDispatch( );
		::CoUninitialize();
		return FALSE;
	}

	pm_App->SetVisible( TRUE );//Word应用程序窗口可见
	if( !AddTemplate( ) )//添加模板，新建Word文件
	{
		return FALSE;
	}
	m_bInit = TRUE;
	return TRUE;
}
/*======================================================
功  能: 添加模板
返回值: BOOL TRUE添加成功 FALSE添加失败
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
功  能: 插入图片
参  数: CString strFile图片文件名
	    nLeft 图片左边位置
		nTop  图片顶部位置
		nWidth图片宽度
		nHeight图片高度
======================================================*/
void COpWord::InsertPic( CString strFile, float fLeft, float fTop, float fWidth, float fHeight )
{
//	m_rng = m_Sel.GetRange( );
}

/*======================================================
功  能: 直接写字符串strText到Word文件
参  数: bBefore FALSE在尾部添加字符串否则，在头部添加字符串
		CString strText字符串
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
功  能: 设置rng范围内的字符的字体为strfont
参  数: Range rng设置选择字符范围，CString strfont字体名称
======================================================*/
void COpWord::SetFont(Range rng, CString strfont)
{
	_Font ft;

	ft = rng.GetFont( );
	ft.SetName( strfont );
}

/*======================================================
功  能: 设置rng范围内的字符的字体大小为nSize
参  数: Range rng设置选择字符范围，int nSize字体大小
======================================================*/
void COpWord::SetTextSize(Range rng, float nSize)
{
	_Font ft;

	if( nSize <= 0 )
	{
		AfxMessageBox( "字体大小不能为小于0" );
		return ;
	}

	ft = rng.GetFont( );
	ft.SetSize( nSize );
}
/*======================================================
功  能: 设置rng范围内的字符的字体大小为nColor
参  数: Range rng设置选择字符范围，long nColor字体颜色
======================================================*/
void COpWord::SetTextColor(Range rng, long nColor )
{
	_Font ft;

	ft = rng.GetFont( );
	ft.SetColor( nColor );
}

/*======================================================
功  能: 设置段落缩进格式
参  数: 缩进nBlank
======================================================*/
void COpWord::SetParagraphFormat( float nBlank)
{
	_ParagraphFormat ParaFormat;

	if( nBlank <= 0 )
	{
		AfxMessageBox( "缩进不能小于0" );
		return ;
	}
	
	ParaFormat = m_Sel.GetParagraphFormat( );
	ParaFormat.SetFirstLineIndent( nBlank );
	m_Sel.SetParagraphFormat( ParaFormat );
}
/*======================================================
功  能: 设置对齐方式
参  数: nAlign取值：ALIGN_LEFT，ALIGN_RIGHT,ALIGN_CENTER
======================================================*/
void COpWord::SetParagraphAlign(unsigned int nAlign)
{
	_ParagraphFormat ParaFormat;

	if( nAlign != 0 || nAlign != 1 || nAlign != 2 )
	{
		AfxMessageBox( "对齐方式不对" );
		return ;
	}

	ParaFormat = m_Sel.GetParagraphFormat( );
	ParaFormat.SetAlignment( nAlign );
	m_Sel.SetParagraphFormat( ParaFormat );	
}
/*======================================================
函数名:AddTextBox(CString strText)
功  能: 添加文本框，strText文本框内容
参  数: strText文本框内容
	    fLeft 文本框左边位置
		fTop  文本框顶部位置
		fWidth  文本框宽度
		fHeigth 文本框高度
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
功  能: 保存Word文件关闭Word应用程序
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
			
			CFileDialog SaveDlg( FALSE, "doc", NULL, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"Word文档|*.doc||",NULL);
			if( SaveDlg.DoModal( ) == IDOK )
			{
				strFile = SaveDlg.GetPathName( );
				if( ResFile.Open(strFile,CFile::modeWrite|CFile::modeCreate, NULL) )
				{
					ResFile.Close( );
					varFileName.bstrVal = _bstr_t(strFile);
					m_Doc.SaveAs( &varFileName, &vt, &vt, &vt,	&vt, &vt, &vt, &vt, &vt, &vt, &vt ,&vt,&vt,&vt,&vt,&vt);	
					VariantClear( &varFileName );
					//退出
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
					AfxMessageBox( "文件名重复!" );
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
/*功能:设置文本列
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
/*设置页边距
/************************************************************************/
void COpWord::SetMargin(float fLeft, float fRight)
{
	PageSetup psetup;
	psetup = m_Sel.GetPageSetup( );
	psetup.SetLeftMargin( fLeft );
	psetup.SetRightMargin( fRight );
}