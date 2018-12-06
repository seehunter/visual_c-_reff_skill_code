#include <iostream.h>

class Base
{
//构造函数和析构函数
public:
	Base(){cout<<"Base	构造函数"<<endl;}
	virtual ~Base(){cout<<"Base 析构函数"<<endl;}
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
//构造函数和析构函数
public:
	A(){cout<<"A 构造函数"<<endl;}
	virtual ~A(){cout<<"A 析构函数"<<endl;}
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
	B(){cout<<"B 构造函数"<<endl;}
	~B(){cout<<"B 析构函数"<<endl;}
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