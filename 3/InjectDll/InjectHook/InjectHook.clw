; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CInjectHookDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "InjectHook.h"

ClassCount=4
Class1=CInjectHookApp
Class2=CInjectHookDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_INJECTHOOK_DIALOG

[CLS:CInjectHookApp]
Type=0
HeaderFile=InjectHook.h
ImplementationFile=InjectHook.cpp
Filter=N

[CLS:CInjectHookDlg]
Type=0
HeaderFile=InjectHookDlg.h
ImplementationFile=InjectHookDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=InjectHookDlg.h
ImplementationFile=InjectHookDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_INJECTHOOK_DIALOG]
Type=1
Class=CInjectHookDlg
ControlCount=4
Control1=IDC_STATIC,button,1342177287
Control2=IDC_INFO_ED,edit,1350631552
Control3=IDC_INSTALL_BTN,button,1342242816
Control4=IDC_UNINSTALL_BTN,button,1342242816

