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
	friend Complex operator +(Complex&,Complex&);  
	friend Complex operator -(Complex&,Complex&);
	friend Complex operator *(Complex&,Complex&);
	friend Complex operator /(Complex&,Complex&);
	friend Complex& operator ++(Complex&); //前置方式
	friend Complex& operator ++(Complex&,int); //后置方式
//成员函数
};
// "+"重载运算法
Complex operator +(Complex& temp1,Complex& temp2)//+运算符重载函数  
{  
    Complex ret;
	ret.x = temp1.x + temp2.x;
	ret.y = temp1.y + temp2.y;
    return ret;  
} 
// "-"重载运算法
Complex operator -(Complex& temp1,Complex& temp2)//-运算符重载函数  
{  
    Complex ret;
	ret.x = temp1.x - temp2.x;
	ret.y = temp1.y - temp2.y;
    return ret;  
}  
// "*"重载运算法
Complex operator *(Complex& temp1,Complex& temp2)//*运算符重载函数  
{  
    Complex ret;
	ret.x = temp1.x * temp2.x;
	ret.y = temp1.y * temp2.y;
    return ret;  
} 
// "/"重载运算法
Complex operator /(Complex& temp1,Complex& temp2)//"/"运算符重载函数  
{  
    Complex ret;
	ret.x = temp1.x / temp2.x;
	ret.y = temp1.y / temp2.y;
    return ret;  
} 
// "++"前置运算符
Complex& operator ++(Complex& temp1)//前置运算符
{
   temp1.x = temp1.x + 1;
   temp1.y = temp1.y + 1;
   return temp1;
}
// "++"后置运算符
Complex& operator ++(Complex& temp1,int)//后置运算符
{
	temp1.x = temp1.x ++;
	temp1.y = temp1.y ++;
	return temp1;
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


