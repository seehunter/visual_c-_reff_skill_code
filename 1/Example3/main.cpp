#include <iostream.h>
//-----------------------------------------
//String ��
//==========================================
class String 
{
public:
	String(const char* str = NULL); //��ͨ���캯��
	String(const String &other);    //�������캯��
	~String(void);                  //��������
	String& operator = (const String& other);//��ֵ����
private:
	char* m_data;
}; 
/************************************************************************/
/* String ����������
/* ���ã���ֹ�ڴ�й¶
/************************************************************************/
String::~String(void)
{
	if(m_data != NULL)
	{
		delete m_data;
		m_data = NULL;//��ֹҰָ�����
	}
}
/************************************************************************/
/* String�Ĺ��캯��
/* ���ã����� һ���ַ�������
/************************************************************************/
String::String(const char* str /* = NULL */)
{
	if(str == NULL)
	{
		m_data = new char[1];
		m_data = '\0';
	}
	else
	{
		int length = strlen(str);
		m_data = new charp[length+1];
		strcpy(m_data,str);
	}
}
/************************************************************************/
/* String �Ŀ������캯��
/* ���� ���Դ�ֵ�ķ�ʽ����һ���������
/************************************************************************/
String::String(const String &other)
{
	int length = strlen(other,m_data);
	m_data = new char[length+1];
	strcpy(m_data,other.m_data);
}
/************************************************************************/
/* String�ĸ�ֵ����
/* ����:ʵ���ַ����Ĵ�ֵ
/************************************************************************/
String& String::operator = (const String& other)
{
	if(this == &other)
	{
		return* this;
	}
	delete m_data;
	//�����ڴ���Դ 
	int length = strlen(other.m_data);
	m_data = new char[length+1];
	strcpy(m_data,other.m_data);
	return *this;//���ر�����
}