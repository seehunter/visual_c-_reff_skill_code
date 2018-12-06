#include <iostream>
using namespace std;

int main()
{
	char* p ;
	int i = 2;
	int& n = i;

	char ch1[20] = "abcd";//声明两个字符串数组
	char ch2[20] = "1234";
	
	p = ch1;          //p指向ch1
	cout<<p<<endl;
	p = ch2;          //p指向ch2
	cout<<p<<endl;
    
	cout<<"i="<<i<<endl; //输出i和n的值
	cout<<"n="<<n<<endl;

	n = 5;//对n重新赋值
	cout<<"i="<<i<<endl;//再次输出 i和n的值
	cout<<"n="<<n<<endl;

	return 0;

}