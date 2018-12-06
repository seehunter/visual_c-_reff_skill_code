#include <iostream.h>
struct A
{
	char ch;
	int  n;
};
void main()
{
   int n = sizeof(A);
   cout<<"sizeof(A)="<<n<<endl;
}