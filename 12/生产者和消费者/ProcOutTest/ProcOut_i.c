/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Jan 22 00:27:11 2008
 */
/* Compiler settings for E:\Visual C++编程技巧与代码参考\代码\第12章\ProcOut\ProcOut.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IObject = {0x6CEC51A9,0xE57B,0x49B3,{0x83,0x9B,0x88,0x0A,0xDD,0x12,0xDF,0xBD}};


const IID LIBID_PROCOUTLib = {0x2A8FBC12,0x1D32,0x49F6,{0xB4,0xA5,0xE8,0x68,0xA3,0x1D,0xED,0xDC}};


const CLSID CLSID_Object = {0x46BE1C21,0xDFC5,0x4529,{0xA4,0x8D,0xE7,0xB4,0x6E,0x15,0x8F,0x0E}};


#ifdef __cplusplus
}
#endif

