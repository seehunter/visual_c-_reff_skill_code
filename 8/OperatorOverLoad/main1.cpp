#include <iostream.h>
/************************************************************************/
/* 声明复数类
/************************************************************************/
class Complex 
{
//Attribute
public:
	int x;
	int y;
//Operator
    void SetX(int a){ x = a ;}
	void SetY(int b){ y = b ;}
//友元
	Complex operator +(Complex&);  
	Complex operator -(Complex&);
	Complex operator *(Complex&);
	Complex operator /(Complex&);
	Complex& operator ++(); //前置方式
	Complex& operator ++(int); //后置方式
//成员函数
};
// "+"重载运算法
Complex Complex::operator +(Complex& temp1)//+运算符重载函数  
{  
    Complex ret;
	ret.x = x + temp1.x;
	ret.y = y + temp1.y ;
    return ret;  
} 
// "-"重载运算法
Complex Complex::operator -(Complex& temp1)//-运算符重载函数  
{  
    Complex ret;
	ret.x = x - temp1.x;
	ret.y = y - temp1.y;
    return ret;  
}  
// "*"重载运算法
Complex Complex::operator *(Complex& temp1)//*运算符重载函数  
{  
    Complex ret;
	ret.x = x * temp1.x ;
	ret.y = y * temp1.y ;
    return ret;  
} 
// "/"重载运算法
Complex Complex::operator /(Complex& temp1)//"/"运算符重载函数  
{  
    Complex ret;
	ret.x = x/temp1.x ;
	ret.y = y/temp1.y ;
    return ret;  
} 
// "++"前置运算符

Complex& Complex::operator ++()//前置运算符
{
   x = x + 1;
   y = y + 1;
   return *this;
}
// "++"后置运算符
Complex& Complex::operator ++(int)//后置运算符
{
	x = x ++;
	y = y ++;
	return *this;
}

// 主函数
void main()
{
	Complex  Complex1;
	Complex  Complex2;
	Complex  Ret;

	Complex1.SetX(30);
	Complex1.SetY(40);

	Complex2.SetX(10);
	Complex2.SetY(20);

	cout<<"重载加法运算"<<endl;
	Ret = Complex1 + Complex2;
	cout<<"Ret.x="<<Ret.x<<endl;
	cout<<"Ret.y="<<Ret.y<<endl;

	cout<<"重载减法运算"<<endl;
	Ret = Complex1 - Complex2;
	cout<<"Ret.x="<<Ret.x<<endl;
	cout<<"Ret.y="<<Ret.y<<endl;

	cout<<"重载乘法运算"<<endl;
	Ret = Complex1 * Complex2;
	cout<<"Ret.x="<<Ret.x<<endl;
	cout<<"Ret.y="<<Ret.y<<endl;

	cout<<"重载乘法运算"<<endl;
	Ret = Complex1 / Complex2;
	cout<<"Ret.x="<<Ret.x<<endl;
	cout<<"Ret.y="<<Ret.y<<endl;

	cout<<"前置++运算符"<<endl;
	Ret = ++Complex1;
	cout<<"Ret.x="<<Ret.x<<endl;
	cout<<"Ret.y="<<Ret.y<<endl;

	cout<<"后置++运算符"<<endl;
	Ret = Complex2++;
	cout<<"Ret.x="<<Ret.x<<endl;
	cout<<"Ret.y="<<Ret.y<<endl;
}


