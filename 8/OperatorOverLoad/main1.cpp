#include <iostream.h>
/************************************************************************/
/* ����������
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
//��Ԫ
	Complex operator +(Complex&);  
	Complex operator -(Complex&);
	Complex operator *(Complex&);
	Complex operator /(Complex&);
	Complex& operator ++(); //ǰ�÷�ʽ
	Complex& operator ++(int); //���÷�ʽ
//��Ա����
};
// "+"�������㷨
Complex Complex::operator +(Complex& temp1)//+��������غ���  
{  
    Complex ret;
	ret.x = x + temp1.x;
	ret.y = y + temp1.y ;
    return ret;  
} 
// "-"�������㷨
Complex Complex::operator -(Complex& temp1)//-��������غ���  
{  
    Complex ret;
	ret.x = x - temp1.x;
	ret.y = y - temp1.y;
    return ret;  
}  
// "*"�������㷨
Complex Complex::operator *(Complex& temp1)//*��������غ���  
{  
    Complex ret;
	ret.x = x * temp1.x ;
	ret.y = y * temp1.y ;
    return ret;  
} 
// "/"�������㷨
Complex Complex::operator /(Complex& temp1)//"/"��������غ���  
{  
    Complex ret;
	ret.x = x/temp1.x ;
	ret.y = y/temp1.y ;
    return ret;  
} 
// "++"ǰ�������

Complex& Complex::operator ++()//ǰ�������
{
   x = x + 1;
   y = y + 1;
   return *this;
}
// "++"���������
Complex& Complex::operator ++(int)//���������
{
	x = x ++;
	y = y ++;
	return *this;
}

// ������
void main()
{
	Complex  Complex1;
	Complex  Complex2;
	Complex  Ret;

	Complex1.SetX(30);
	Complex1.SetY(40);

	Complex2.SetX(10);
	Complex2.SetY(20);

	cout<<"���ؼӷ�����"<<endl;
	Ret = Complex1 + Complex2;
	cout<<"Ret.x="<<Ret.x<<endl;
	cout<<"Ret.y="<<Ret.y<<endl;

	cout<<"���ؼ�������"<<endl;
	Ret = Complex1 - Complex2;
	cout<<"Ret.x="<<Ret.x<<endl;
	cout<<"Ret.y="<<Ret.y<<endl;

	cout<<"���س˷�����"<<endl;
	Ret = Complex1 * Complex2;
	cout<<"Ret.x="<<Ret.x<<endl;
	cout<<"Ret.y="<<Ret.y<<endl;

	cout<<"���س˷�����"<<endl;
	Ret = Complex1 / Complex2;
	cout<<"Ret.x="<<Ret.x<<endl;
	cout<<"Ret.y="<<Ret.y<<endl;

	cout<<"ǰ��++�����"<<endl;
	Ret = ++Complex1;
	cout<<"Ret.x="<<Ret.x<<endl;
	cout<<"Ret.y="<<Ret.y<<endl;

	cout<<"����++�����"<<endl;
	Ret = Complex2++;
	cout<<"Ret.x="<<Ret.x<<endl;
	cout<<"Ret.y="<<Ret.y<<endl;
}


