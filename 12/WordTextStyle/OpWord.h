/*===========================================================
*�ļ�����OpWord.h
*��WORD�ĵ����в���
*����������������\����ͼƬ�ȵ�
===========================================================*/

#ifndef WORDFILE_H_
#define WORDFILE_H_
#include "msword.h"
//�ඨ��
class COpWord
{

public:
	//���캯��
	COpWord( );
	//�鹹����
	virtual~COpWord( );

public:
	//��Word���½�Word.Application,�½�Word.Documents.Document�ĵ�
	BOOL FileInit( );
	//�����ļ�
	BOOL SaveDocument( );
	//�����ַ�
	void WriteTextToFile( BOOL bBefore, BOOL bChangeLine, CString strText, float fontsize );
	//����ͼƬ
	void InsertPic( CString strFile, float fLeft, float fTop, float fWidth, float fHeight );
	//����ı���
	void AddTextBox(CString strText, int nhorizontal, float fLeft, float fTop, float fWidth, float fHeight );
	//�����ַ������С
	void SetTextSize( Range rng, float nSize );
	//��������
	void SetFont( Range rng, CString strfont );
	//�����ַ���ɫ
	void SetTextColor( Range rng, long nColor );
	//���ö�����뷽ʽ
	void SetParagraphAlign( unsigned nAlign );
	//���ö����ʽ
	void SetParagraphFormat( float nBlank );
    //����ҳ�߾�
	void SetMargin( float fLeft, float fRight );
    //�����ı�����
	void SetTextColumn( int nColumn );
	//���ģ��
	BOOL AddTemplate();

public:
	Selection	    m_Sel;//��ǰѡ������

protected:
	int	            m_nOldX;
	int             m_nOldY;
	int             m_nHeight;
	CSize	        m_Oldsz;
	Documents	    m_Docs;//Word�򿪵������ĵ�
	_Document	    m_Doc;	//��ǰWord�ĵ�
	_Application	*pm_App; //����WordӦ�ó���

	BOOL	        m_bSave;//�Ƿ񱣴�
	BOOL	        m_bInit;//�Ƿ��ʼ��
	CString	        m_temp;//��ʱ�ļ���
};

#endif