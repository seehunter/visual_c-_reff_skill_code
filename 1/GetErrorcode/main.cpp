#include <iostream.h>
#include <windows.h>
#include <stdio.h>

void main()
{
    unsigned short us = (unsigned short)6553658;
	int errorcode = GetLastError();	
	char sz[100];
	sprintf(sz,"errcode %d",errorcode);
	MessageBox(NULL,sz,"Tip",MB_OK);
}