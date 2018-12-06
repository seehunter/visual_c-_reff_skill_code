#include<stdio.h>
#include<conio.h>
#include <dos.h> 
#define indexaddr 0x295
#define dataaddr  0x296
void temperture();
//#define  si      0x4e
int main()
{    
//	clrscr();
	 temperture();
	 return 0;
}
     void temperture( )
{
 int value1,y;
 int value2,value3;

 _outp(indexaddr,0x4e);
 _outp(dataaddr,0x80);
// asm mov al,00000011b
// asm out 5dh,al
// asm in  al,5dh
// asm mov y,al
// printf("%x",y);
 _outp(indexaddr,0x27);
 //outportb(0x4e,0x80);
 value1=_inp(dataaddr);
 printf("system temperture:");
 printf("%d",value1);
 printf("\n");
// outportb(si,0x81);
 _outp(indexaddr,0x4e);
 _outp(dataaddr,0x81);
 _outp(indexaddr,0x50);
 value2=_inp(dataaddr);
 printf("cputin temperture:");
 printf("%d",value2);
 printf("\n");
 _outp(indexaddr,0x4e);
 _outp(dataaddr,0x82);
 _outp( indexaddr,0x50);
// outportb(si,0x82);
 value3=_inp(dataaddr);
 printf("auxtin temperture:");
 printf("%d",value3);
 printf("\n");
 }