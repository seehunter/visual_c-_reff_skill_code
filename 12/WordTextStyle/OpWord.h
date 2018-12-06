/*===========================================================
*文件名：OpWord.h
*对WORD文档进行操作
*比如设置字体类型\插入图片等等
===========================================================*/

#ifndef WORDFILE_H_
#define WORDFILE_H_
#include "msword.h"
//类定义
class COpWord
{

public:
	//构造函数
	COpWord( );
	//虚构函数
	virtual~COpWord( );

public:
	//打开Word，新建Word.Application,新建Word.Documents.Document文档
	BOOL FileInit( );
	//保存文件
	BOOL SaveDocument( );
	//插入字符
	void WriteTextToFile( BOOL bBefore, BOOL bChangeLine, CString strText, float fontsize );
	//插入图片
	void InsertPic( CString strFile, float fLeft, float fTop, float fWidth, float fHeight );
	//添加文本框
	void AddTextBox(CString strText, int nhorizontal, float fLeft, float fTop, float fWidth, float fHeight );
	//设置字符字体大小
	void SetTextSize( Range rng, float nSize );
	//设置字体
	void SetFont( Range rng, CString strfont );
	//设置字符颜色
	void SetTextColor( Range rng, long nColor );
	//设置段落对齐方式
	void SetParagraphAlign( unsigned nAlign );
	//设置段落格式
	void SetParagraphFormat( float nBlank );
    //设置页边距
	void SetMargin( float fLeft, float fRight );
    //设置文本的列
	void SetTextColumn( int nColumn );
	//添加模板
	BOOL AddTemplate();

public:
	Selection	    m_Sel;//当前选中内容

protected:
	int	            m_nOldX;
	int             m_nOldY;
	int             m_nHeight;
	CSize	        m_Oldsz;
	Documents	    m_Docs;//Word打开的所有文档
	_Document	    m_Doc;	//当前Word文档
	_Application	*pm_App; //定义Word应用程序

	BOOL	        m_bSave;//是否保存
	BOOL	        m_bInit;//是否初始化
	CString	        m_temp;//临时文件名
};

#endif