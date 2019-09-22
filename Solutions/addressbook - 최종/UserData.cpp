// UserData.cpp: implementation of the CUserData class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "UserData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUserData::CUserData()
{
}

CUserData::~CUserData()
{

}

void CUserData::SetName(char *pszName)
{
	m_strName = pszName;
}

char* CUserData::GetName()
{
	return m_strName;
}

void CUserData::SetPhone(char *pszPhone)
{
	m_strPhone = pszPhone;
}

char* CUserData::GetPhone()
{
	return m_strPhone;
}

void CUserData::PrintData()
{
	printf("[%p] %s, %s [NEXT:%p]\n",
		this,
		m_strName,
		m_strPhone,
		m_pNext);
}

char* CUserData::GetPriKey()
{
	return m_strName.GetString();
}
