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
	friend Complex operator +(Complex&,Complex&);  
	friend Complex operator -(Complex&,Complex&);
	friend Complex operator *(Complex&,Complex&);
	friend Complex operator /(Complex&,Complex&);
	friend Complex& operator ++(Complex&); //ǰ�÷�ʽ
	friend Complex& operator ++(Complex&,int); //���÷�ʽ
//��Ա����
};
// "+"�������㷨
Complex operator +(Complex& temp1,Complex& temp2)//+��������غ���  
{  
    Complex ret;
	ret.x = temp1.x + temp2.x;
	ret.y = temp1.y + temp2.y;
    return ret;  
} 
// "-"�������㷨
Complex operator -(Complex& temp1,Complex& temp2)//-��������غ���  
{  
    Complex ret;
	ret.x = temp1.x - temp2.x;
	ret.y = temp1.y - temp2.y;
    return ret;  
}  
// "*"�������㷨
Complex operator *(Complex& temp1,Complex& temp2)//*��������غ���  
{  
    Complex ret;
	ret.x = temp1.x * temp2.x;
	ret.y = temp1.y * temp2.y;
    return ret;  
} 
// "/"�������㷨
Complex operator /(Complex& temp1,Complex& temp2)//"/"��������غ���  
{  
    Complex ret;
	ret.x = temp1.x / temp2.x;
	ret.y = temp1.y / temp2.y;
    return ret;  
} 
// "++"ǰ�������
Complex& operator ++(Complex& temp1)//ǰ�������
{
   temp1.x = temp1.x + 1;
   temp1.y = temp1.y + 1;
   return temp1;
}
// "++"���������
Complex& operator ++(Complex& temp1,int)//���������
{
	temp1.x = temp1.x ++;
	temp1.y = temp1.y ++;
	return temp1;
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


