#include <iostream.h>
//-----------------------------------------
//String 类
//==========================================
class String 
{
public:
	String(const char* str = NULL); //普通构造函数
	String(const String &other);    //拷贝构造函数
	~String(void);                  //析构函数
	String& operator = (const String& other);//赋值函数
private:
	char* m_data;
}; 
/************************************************************************/
/* String 的析构函数
/* 作用：防止内存泄露
/************************************************************************/
String::~String(void)
{
	if(m_data != NULL)
	{
		delete m_data;
		m_data = NULL;//防止野指针产生
	}
}
/************************************************************************/
/* String的构造函数
/* 作用：创建 一个字符串对象
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
/* String 的拷贝构造函数
/* 作用 ：以传值的方式传递一个对象参数
/************************************************************************/
String::String(const String &other)
{
	int length = strlen(other,m_data);
	m_data = new char[length+1];
	strcpy(m_data,other.m_data);
}
/************************************************************************/
/* String的赋值函数
/* 作用:实现字符串的传值
/************************************************************************/
String& String::operator = (const String& other)
{
	if(this == &other)
	{
		return* this;
	}
	delete m_data;
	//分配内存资源 
	int length = strlen(other.m_data);
	m_data = new char[length+1];
	strcpy(m_data,other.m_data);
	return *this;//返回本对象
}