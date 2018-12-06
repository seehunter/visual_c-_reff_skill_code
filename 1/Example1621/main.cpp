#include <iostream.h>
#include <string.h>
class AutoNewDel
{
//Attribte
private:
	char* m_szBuf;
	unsigned int  m_nSize;
	int* m_count;
public:
	AutoNewDel(unsigned int n=1)//在构造函数中申请内存
	{
		m_szBuf = new char[n];
		m_nSize = n;
		m_count = new int;
		*m_count = 1;
		cout<<"count is : "<<*m_count<<endl;
	};
	AutoNewDel(const AutoNewDel& s)
	{
		m_nSize = s.m_nSize;
		m_szBuf = s.m_szBuf;
		m_count = s.m_count;
		(*m_count)++;
		cout<<"count is :"<<*m_count<<endl;
	}
	~AutoNewDel()
	{
		(*m_count)--;
		cout<<"count is :"<<*m_count<<endl;
		if(*m_count == 0)
		{
			cout<<"buf is deleted"<<endl;
			if(m_szBuf != NULL)//提高安全机制
			{
				delete[] m_szBuf;//删除字符数组
				m_szBuf = NULL;//防止出现野指针
				if(m_count != NULL)
				{
					delete m_count;
					m_count = NULL;			
				}
			}
		}
	};
	char* GetBuf()
	{
		return m_szBuf;
	};
};

void fun()
{
	AutoNewDel tmpObj(100);
	char* p = tmpObj.GetBuf();
	strcpy(p,"one world, one dream");
	cout<<p<<endl;

	AutoNewDel tmpObj2 = tmpObj;
	cout<<"tmpObj2.m_szBuf = "<<tmpObj2.GetBuf()<<endl;
}
int main()
{
   fun();
   cout<<"exit main"<<endl;
   return 0;
}