//-------------------------------------------------
//
//=================================================
#include <iostream.h>
/************************************************************************/
/* 类声明
/************************************************************************/
class point
{
public:
	int x;
	int y;

	point()		
	{
		x=0;	
		y=0;
	}
	
	point(int a,int b)
	{
		x=a;	
		y=b;
	}
	
	void output()
	{
		cout<<"x="<<x<<endl<<"y="<<y<<endl;	
	}
	
	void input(int x,int y)
	{
		this->x=x;	
		this->y=y;
	}
};
/************************************************************************/
/* 主函数调用
/************************************************************************/
void main()

{
	point pt(5,5);
	
	pt.input(10,10);
	
	pt.output();	
}

