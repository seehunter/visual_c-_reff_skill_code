#include <iostream>
using namespace std;

int main()
{
	char* p ;
	int i = 2;
	int& n = i;

	char ch1[20] = "abcd";//���������ַ�������
	char ch2[20] = "1234";
	
	p = ch1;          //pָ��ch1
	cout<<p<<endl;
	p = ch2;          //pָ��ch2
	cout<<p<<endl;
    
	cout<<"i="<<i<<endl; //���i��n��ֵ
	cout<<"n="<<n<<endl;

	n = 5;//��n���¸�ֵ
	cout<<"i="<<i<<endl;//�ٴ���� i��n��ֵ
	cout<<"n="<<n<<endl;

	return 0;

}