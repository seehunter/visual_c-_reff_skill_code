/************************************************************************/
/* ˵�� ��ʾconst�ں����е�����
/* const ���β���
/* const ���η���ֵ
/* const ���κ�����
/************************************************************************/
#include <iostream.h>
#include <assert.h>
//const ���������������
char* StringCopy(char *strDestination, const char *strSource)
{
   assert((strDestination != NULL) && (strSource != NULL));
   char* address = strDestination;
   while((*strDestination++ = *strSource++) != '\0')
	   NULL;
   return address;
}
//const ���η���ֵ
const char * GetString(void)
{
	char* szOut = "�����������";
	return szOut;
}
//�� DTime 
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
	int GetYear() const{ return m_nYear;}//const ���κ�����
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
   char* szInStr = "����������";
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


