#include <iostream.h>

class Base
{
//���캯������������
public:
	Base(){cout<<"Base	���캯��"<<endl;}
	virtual ~Base(){cout<<"Base ��������"<<endl;}
public:
	virtual void foo()
	{
		cout<<"Base"<<endl;
	}

};
/************************************************************************/
/* 
/************************************************************************/
class A : public Base
{
//���캯������������
public:
	A(){cout<<"A ���캯��"<<endl;}
	virtual ~A(){cout<<"A ��������"<<endl;}
public:
	virtual void foo()
	{
		cout<<"A"<<endl;
	}
};
/************************************************************************/
/* 
/************************************************************************/
class B:public Base
{
public:
	B(){cout<<"B ���캯��"<<endl;}
	~B(){cout<<"B ��������"<<endl;}
public:
	virtual void foo()
	{
		cout<<"B"<<endl;
	}
};
/************************************************************************/
/* 
/************************************************************************/
int main()
{
	Base*  pBase = NULL; 
	pBase = new A;
	pBase->foo();
	if(pBase != NULL)
	{
		delete pBase;
		pBase = NULL;
	}
	
	pBase = new B;
	pBase->foo();
	if(pBase != NULL)
	{
		delete pBase;
		pBase = NULL;
	}
	

	return 0;
}