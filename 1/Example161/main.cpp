#include <stdio.h>
#include <stdlib.h>
int nGlobal = 100;//全局变量
int main()
{
  char*       szLocalString1 = "LocslString1";
  const char*  szLocalString2 = "LocalString2";
  static int   nStatic = 100;
  int nLocal = 1;
  const int nLocalConst = 200;
  int*  pNew = new int[5];
  char*  szMalloc = (char*)malloc(1);
  
  printf("global variable : 0x%x\n",&nGlobal);
  printf("static varaible : 0x%x\n",&nStatic);
  printf("local expression 1: 0x%x\n",szLocalString1);
  printf("local expression 2: 0x%x\n",szLocalString2);

  printf("new 0x%x\n",&pNew);
  printf("local pointer(szLocalString1) : 0x%x\n",&szLocalString1);
  printf("local pointer(szLocalString2) : 0x%x\n",&szLocalString2);
  printf("local variable : 0x%x\n",&nLocal);
  printf("local pointer(szMalloc) : 0x%x\n",&szMalloc);
  printf("local const variable : 0x%x\n",&nLocalConst);

  return 0;
}