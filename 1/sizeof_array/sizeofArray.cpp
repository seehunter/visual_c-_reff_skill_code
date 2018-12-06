#include <iostream.h>
struct A 
{
	char ch;
	int  n;
	float f;
};
void main()
{
	int n = sizeof(A);
	cout<<"sizeof(A) = "<<n<<endl;
}
