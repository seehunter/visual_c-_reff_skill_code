// POP3.cpp : implementation file
//

#include "stdafx.h"
#include "POP3.h"


// CPOP3

CPOP3::CPOP3()
{
	m_PopServer.Create();
}

CPOP3::~CPOP3()
{
	m_PopServer.Close();
}



BOOL CPOP3::Connect(CString & Host, CString & User, CString & Password)
{
	char	buf [512];
	if (!m_PopServer.Connect(Host,110)) // 110 Pop3 Port
	{
		m_ErrorMes = _T("Á¬½Ó²»µ½µ½ÓÊ¼þ·þÎñÆ÷");
		return FALSE;
	}
	else
	{
		if(CheckResponse(CONNECTION_CHECK)==FALSE)
			return FALSE;

		wsprintf (buf, "USER %s\r\n", (LPCSTR) User);
		m_PopServer.Send(buf, (int)strlen(buf));
		if(CheckResponse(USER_CHECK)==FALSE)
			return FALSE;

		wsprintf (buf, "PASS %s\r\n", (LPCSTR) Password);
		m_PopServer.Send(buf, (int)strlen(buf)); 
		if (CheckResponse(PASSWORD_CHECK)==FALSE)
			return FALSE;

		return TRUE;
	}

}

BOOL CPOP3::Delete(int & MsgNumber)
{
	char	buf [512];

	wsprintf (buf, "DELE %d\r\n",MsgNumber );
	m_PopServer.Send(buf, (int)strlen(buf)); 
	if (CheckResponse(DELETE_CHECK)==FALSE)
		return FALSE;
	else
		return TRUE;
}

BOOL CPOP3::Disconnect()
{
	char	buf [512];

	wsprintf (buf, "QUIT \r\n");
	m_PopServer.Send(buf, (int)strlen(buf)); 
	if (CheckResponse(QUIT_CHECK)==FALSE)
		return FALSE;
	else
		return TRUE;
}

BOOL CPOP3::Noop()
{
	char	buf [512];

	wsprintf (buf, "NOOP  \r\n");
	m_PopServer.Send(buf, (int)strlen(buf)); 
	if (CheckResponse(NOOP_CHECK)==FALSE)
		return FALSE;
	else
		return TRUE;
}


int CPOP3::GetMessageSize(int MsgNumber)
{
	if(m_SizeOfMsg.GetSize() < MsgNumber+1)
		return 0;
	else
		return m_SizeOfMsg[MsgNumber+1];
	
}

BOOL CPOP3::Reset()
{
	char	buf [512];

	wsprintf (buf, "RSET \r\n");
	m_PopServer.Send(buf, (int)strlen(buf)); 
	if (CheckResponse(RSET_CHECK)==FALSE)
		return FALSE;
	else
		return TRUE;
}


BOOL CPOP3::Retrieve(int  MsgNumber)
{
	char	buf [512];

	wsprintf (buf, "RETR %d\r\n",MsgNumber );	
	m_PopServer.Send(buf, (int)strlen(buf)); 
	if (CheckResponse(RETR_CHECK)==FALSE)
		return FALSE;
	else
		return TRUE;
}

BOOL CPOP3::Statistics()
{
	char	buf [512];
	wsprintf (buf, "STAT \r\n");
	m_PopServer.Send(buf, (int)strlen(buf)); 
	if (CheckResponse(STAT_CHECK)==FALSE)
		return FALSE;
	else			
		return TRUE;	
}

CString CPOP3::GetMsgContents()
{
	return m_MsgContents;
}

int CPOP3::GetNumberOfMails()
{
	return m_NumberMail;
}

int CPOP3::GetTotalMailSize()
{
	return m_TotalSize;
}

BOOL CPOP3::Connect()
{
	Connect(m_Host, m_User, m_Password);
	return TRUE;
}

void CPOP3::SetHost(CString & Host)
{
	m_Host = Host;
}

CString CPOP3::GetHost()
{
	return m_Host;
}

void CPOP3::SetUser(CString & User)
{
	m_User = User;
}

CString CPOP3::GetUser()
{
	return m_User;
}

void CPOP3::SetPassword(CString & Password)
{
	m_Password = Password;
}

CString CPOP3::GetPassword()
{
	return m_Password;
}

BOOL CPOP3::CheckResponse(int ResponseType)
{
	char buf [256]="";

	m_PopServer.Receive(buf, sizeof(buf));

	switch (ResponseType)
	{
		case CONNECTION_CHECK:
			if (strnicmp(buf,"-ERR", 4) == 0)
			{
				m_ErrorMes = _T("Á¬½ÓÊ§°Ü£¡");
				return FALSE;
			} 
			break;

		case USER_CHECK:
			if (strnicmp(buf,"-ERR", 4) == 0)
			{
				m_ErrorMes = _T("ÓÃ»§Ãû²»ÕýÈ·£¡");
				return FALSE;
			} 
			break;
		case PASSWORD_CHECK:
			if (strnicmp(buf,"-ERR", 4) == 0)
			{
				m_ErrorMes = _T("ÃÜÂë´íÎó£¡");
				return FALSE;
			}
			break;
		case QUIT_CHECK:
			if (strnicmp(buf,"-ERR", 4) == 0)
			{
				m_ErrorMes = _T("QUIT ÃüÁî´íÎó£¡");
				return FALSE;
			}
			break;
		case DELETE_CHECK:
			if (strnicmp(buf,"-ERR", 4) == 0)
			{
				m_ErrorMes = _T("DELE ÃüÁî´íÎó£¡");
				return FALSE;
			}
			break;
		case RSET_CHECK:
			if (strnicmp(buf,"-ERR", 4) == 0)
			{
				m_ErrorMes = _T("RSET ÃüÁî´íÎó£¡");
				return FALSE;
			}
			break;
		case STAT_CHECK:
			if (strnicmp(buf,"-ERR", 4) == 0)
			{
				m_ErrorMes = _T("STAT ÃüÁî´íÎó£¡");
				return FALSE;
			}
			else
			{
				BOOL EmailNumber = TRUE;
				for (char *p = buf; *p != '\0'; p++)
				{
					if (*p == '\t' || *p == ' ')
					{						
						if(EmailNumber == TRUE)
						{
							m_NumberMail = atoi(p);
							EmailNumber = FALSE;
						}
						else
						{
							m_TotalSize = atoi(p);
							return TRUE;
						}
						
						
					}
				}

			}
			break;
		case NOOP_CHECK:
			if (strnicmp(buf,"-ERR", 4) == 0)
			{
				m_ErrorMes = _T("NOOP ÃüÁî´íÎó£¡");
				return FALSE;
			}
			break;

		case LIST_CHECK:
			if (strnicmp(buf,"-ERR", 4) == 0)
			{
				m_ErrorMes = _T("Error occured during LIST");
				return FALSE;
			}
			else
			{
				m_PopServer.Receive(buf, sizeof(buf));

				for (char *p = buf; *p != '.'; p++)
					if (*p == '\t' || *p == ' ')
						m_SizeOfMsg.Add(atoi(p));
			}
			break;	
		case RETR_CHECK:
			if (strnicmp(buf,"-ERR", 4) == 0)
			{
				m_ErrorMes = _T("RETR ÃüÁî´íÎó£¡");
				return FALSE;
			}
			else
			{
				char temp[9000];
				m_PopServer.Receive(temp, sizeof(temp));
				m_MsgContents = temp;
			}
			break;	
	}
	return TRUE;
}

CString CPOP3::GetErrorMessage()
{
	return m_ErrorMes;
}

BOOL CPOP3::List()
{
	char	buf [512];

	wsprintf (buf, "LIST  \r\n");
	m_PopServer.Send(buf, (int)strlen(buf)); 
	if (CheckResponse(LIST_CHECK)==FALSE)
		return FALSE;
	else
		return TRUE;

}


// CPOP3 member functions
