/************************************************************************/
/* 说明 演示const在函数中的作用
/* const 修饰参数
/* const 修饰返回值
/* const 修饰函数体
/************************************************************************/
#include <iostream.h>
#include <assert.h>
//const 输入修饰输入参数
char* StringCopy(char *strDestination, const char *strSource)
{
   assert((strDestination != NULL) && (strSource != NULL));
   char* address = strDestination;
   while((*strDestination++ = *strSource++) != '\0')
	   NULL;
   return address;
}
//const 修饰返回值
const char * GetString(void)
{
	char* szOut = "日期输出结束";
	return szOut;
}
//类 DTime 
class DTime
{
//Operation
public:
	DTime(int iYear,int iMonth,int iDay)
	{
        m_nYear = iYear;
		m_nMonth = iMonth;
		m_nDay = iDay;
	}
	int GetYear() const{ return m_nYear;}//const 修饰函数体
	int GetMonth() const {return m_nMonth;}
	int GetDay() const{return m_nDay;}
public:
	int m_nYear;
	int m_nMonth;
	int m_nDay;
};

int main()
{
   char szOutStr[256];
   char* szInStr = "输入年月日";
   StringCopy(szOutStr,szInStr);
   cout<<szOutStr<<endl;

   int nYear;
   int nMonth;
   int nDay;

   cin>>nYear;
   cin>>nMonth;
   cin>>nDay;
   
   DTime dt(nYear,nMonth,nDay);

   cout<<dt.GetYear()<<"-"<<dt.GetMonth()<<"-"<<dt.GetDay()<<endl;

   
   const char* str = GetString();
   cout<<str<<endl;
   return 0;
}


