/*break demo*/
#include <iostream.h>
int main()
{
	char* p = "this is a test , welcome !";
	char* tmp;
	int i = 0;
	for(i=0 ; i<10; i++)
	{   
		tmp = p;
		while(*tmp)
		{
			if(*tmp == ',')
				break;
			cout<<*tmp;
			tmp++;
		}
	    cout<<endl;
		if(i == 8)
			break;
	}
	cout<<endl;
	return 0;
}