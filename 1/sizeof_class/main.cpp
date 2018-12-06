#include <iostream.h>
class A
{
	char ch;
	int a;
	int b;
};
class B
{

};
class C 
{
	static int sVale;
};
void main()
{
	int n = sizeof(A);
	int m = sizeof(B);
	int k = sizeof(C);
	cout<<"sizeof(A)="<<n<<endl;
	cout<<"sizeof(B)="<<m<<endl;
	cout<<"sizeof(C)="<<k<<endl;
}