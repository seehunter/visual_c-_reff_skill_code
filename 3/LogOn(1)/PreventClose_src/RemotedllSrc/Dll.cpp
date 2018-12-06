//---------------------------------------------------------------------------
//作者    ：韦覃武
//网上呢称：BCB_FANS(四大名捕之追杀令)（此为CSDN和www.driverdevelop.com之帐号）
//E-Mail  ：slwqw@163.com
//日期    ：2002-10-20
//
//功能    ：在2000下屏蔽Ctrl + Alt + Del组合键。（在Windows 2000 Professional SP3
//          中文版平台下面测试通过）
//原理    ：采用远程线程注入技术，装载一个DLL到Winlogon进程，然后截获SAS窗口的窗
//          口过程，接管WM_HOTKEY消息，以达到屏蔽Ctrl + Alt + Del之目的。
//开发语言：Borland C++Builder 5.0 Patch2
//技术比较：关于在2000下面如何屏蔽Ctrl + Alt + Del组合键，一种常被提到的解决方法就
//	    是使用自己写的GINA去替换MSGINA.DLL，然后在WlxLoggedOnSAS里边直接返回
//	    WLX_SAS_ACTION_NONE。嘿嘿，说到底这并不是真正地屏蔽了这个组合键，只是
//	    直接返回WLX_SAS_ACTION_NONE时，Winlogon进程又自动从"Winlogon"桌面切换
//	    回原来的"Default"桌面了，而不是显示安全对话框，所以看起来被屏蔽了：），
//	    使用那种方法明显地看到桌面在闪烁！但是使用本文的方法时，你不会看到任
//	    何闪烁！
//鸣谢    ：www.driverdevelop.com上的icube和lu0。
//版权    ：转载请注明原作者：）

//---------------------------------------------------------------------------
// Author  : Wei Tanwu
// Nickname: BCB_FANS(a hue and cry of The four excellent head constables)
// (this is his account name at www.CSDN.net and www.driverdevelop.com)
// E-Mail  ：slwqw@163.com
// Last Update: 2002-10-20
//
// Feature	：Block Ctrl + Alt + Del Key Combination.(Tested on Windows 2000 Professional SP3)
// Function  : Load a dll to Winlogon process by using remote thread injection
// , then subclass the SAS window proc, hook WM_HOTKEY.
// Develop environment：Borland C++Builder 5.0 Patch2
// Compare with GINA:
// A common way to block Ctrl + Alt + Del on win2000 is replacing or Hooking GINA DLL 
// and return WLX_SAS_ACTION_NONE in WlxLoggedOnSAS.Hey, this is not the true blocking.
// Winlogon switch to default desktop from its desktop at this time, 
// seems blocked the key combination because the Windows Security window is not displayed as espected.
// You can see desktop switching quickly in this way, but you will bot see it using my code!

// This code is free for personal and commercial use, providing this 
// notice remains intact in the source files and all eventual changes are
// clearly marked with comments

// Thanks   icube and lu0 from www.driverdevelop.com .
//---------------------------------------------------------------------------

#include "stdafx.h"

#include <string>

using namespace std;

//---------------------------------------------------------------------------

HWND hSASWnd;
FARPROC FOldProc;

LRESULT CALLBACK SASWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);

BOOL CALLBACK EnumWindowsProc(HWND hwnd,LPARAM lParam);

//---------------------------------------------------------------------------

HANDLE hThread = NULL;
DWORD  dwThreadId;

DWORD WINAPI ThreadFunc();

//---------------------------------------------------------------------------
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
  switch(ul_reason_for_call)
  {
    case DLL_PROCESS_ATTACH :

      hThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadFunc,NULL,0,&dwThreadId);
      break;

    case DLL_PROCESS_DETACH :

      if(FOldProc != NULL)
      {
        SetWindowLong(hSASWnd,GWL_WNDPROC,long(FOldProc));
      }
      CloseHandle(hThread);
      break;
  }
  return TRUE;
}
//---------------------------------------------------------------------------
DWORD WINAPI ThreadFunc()
{
  HDESK hDesk;

  hDesk = OpenDesktop("Winlogon",0,false,MAXIMUM_ALLOWED);

  FOldProc = NULL;
  hSASWnd = NULL;

  EnumDesktopWindows(hDesk,(WNDENUMPROC)EnumWindowsProc,0);

  if(hSASWnd != NULL)
  {
    FOldProc = (FARPROC)SetWindowLong(hSASWnd,GWL_WNDPROC,long(SASWindowProc));
  }
  CloseHandle(hDesk); 

  return 1;
}
//---------------------------------------------------------------------------
//查找"Winlogon"桌面的窗口
//Search "Winlogon" desktop 
BOOL CALLBACK EnumWindowsProc(HWND hwnd,LPARAM lParam)
{
  char ClassBuf[128];

  GetWindowText(hwnd,ClassBuf,sizeof(ClassBuf));

  //我自己写了一个系统服务，然后在里边查询"Winlogon"桌面上的窗口，发现桌面上存在
  //窗口"SAS window"。
  //I wrote a system service and enumated all windows on "Winlogon" desktop, found that the window text of SAS windows is "SAS window"。
  string ClassName(ClassBuf); 
  

  if(ClassName.find("SAS window") != -1)
  {
    hSASWnd = hwnd;
    return false;
  }
  

  return true;
}
//---------------------------------------------------------------------------
//SAS窗口的窗口过程
//SAS WNDPROC
LRESULT CALLBACK SASWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	//屏蔽Ctrl + Alt + Del
	//Block Ctrl + Alt + Del
  if(uMsg == WM_HOTKEY)
  {
    WORD wKey = HIWORD(lParam);
    WORD wModifier = LOWORD(lParam);

    bool IsCtrlDown  = ((wModifier & VK_CONTROL) != 0);
    bool IsAltDown   = ((wModifier & VK_MENU) != 0);
    bool IsShiftDown = ((wModifier & VK_SHIFT) != 0);

    //按下Ctrl + Alt + Del组合键
	//Ctrl + Alt + Del Key Combination pressed
    if(IsCtrlDown && IsAltDown && wKey == VK_DELETE)
    {
      return 1;//handled
    }
    //按下Ctrl + Shift + Esc组合键，这个组合键将显示任务管理器，可根据需要是否屏蔽。
	//Ctrl + Shift + Esc Key Combination pressed, this Combination will launch task manager,can be blocked as will.
    else if(IsCtrlDown && IsShiftDown && wKey == VK_ESCAPE)
    {
      // Do nothing
    }                                   
  }

  return CallWindowProc((WNDPROC)FOldProc,hwnd,uMsg,wParam,lParam);
}
//---------------------------------------------------------------------------

