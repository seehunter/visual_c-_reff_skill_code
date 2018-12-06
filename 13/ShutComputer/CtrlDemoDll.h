#ifndef _CTRL_DEMO_DLL_H
#define _CTRL_DEMO_DLL_H
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifdef _AFXDLL
#ifdef _DEBUG
   #pragma comment(lib,"CtrlDemoDllD.lib") 
   #pragma message("Automatically linking with CtrlDemoDllD.Dll")
#else
   #pragma comment(lib,"CtrlDemoDll.lib") 
   #pragma message("Automatically linking with CtrlDemoDll.Dll") 
#endif
#include "CtrlHeader.h"
#endif //_AFXDLL
#endif//_CTRL_DEMO_DLL_H
