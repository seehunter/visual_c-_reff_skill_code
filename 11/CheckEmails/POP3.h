#pragma once


#define CONNECTION_CHECK 0
#define USER_CHECK		1
#define PASSWORD_CHECK	2
#define QUIT_CHECK		3
#define DELETE_CHECK	4
#define RSET_CHECK		5 
#define STAT_CHECK		6 
#define NOOP_CHECK		7
#define LIST_CHECK		8
#define RETR_CHECK		9

// CPOP3 command target

class CPOP3 : public CObject
{
public:
	CPOP3();
	virtual ~CPOP3();
public:
	BOOL List();
	CWordArray m_SizeOfMsg;
	CString GetErrorMessage();
	CString GetPassword();
	void SetPassword(CString& Password);
	CString GetUser();
	void SetUser(CString& User);
	CString GetHost();
	void SetHost(CString& Host);
	BOOL Connect();
	int GetTotalMailSize();
	int GetNumberOfMails();
	CString GetMsgContents();
	BOOL Statistics();
	BOOL Retrieve(int MsgNumber);
	BOOL Reset();
	int  GetMessageSize(int MsgNumber);
	BOOL Noop();
	BOOL Disconnect();
	BOOL Delete(int& MsgNumber);
	BOOL Connect(CString& Host, CString& User, CString& Password);
private:
	CString m_ErrorMes;
	BOOL CheckResponse(int ResponseType);
	CString m_Password;
	CString m_User;
	CString m_Host;
	CString m_MsgContents;
	int m_TotalSize;	
	int m_NumberMail;
	CSocket m_PopServer;

};


