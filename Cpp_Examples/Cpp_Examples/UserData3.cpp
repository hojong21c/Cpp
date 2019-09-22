#include "stdafx.h"
#include "UserData3.h"

int CUserData3::nUserDataCounter = 0;

CUserData3::CUserData3(void) /* : pNext(NULL)*/
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));
	nUserDataCounter++;
}

CUserData3::~CUserData3(void)
{
	nUserDataCounter--;
}

CUserData3::CUserData3(const char* pszName, const char* pszPhone)
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));

	strcpy_s(szName, sizeof(szName), pszName);
	strcpy_s(szName, sizeof(szPhone), pszPhone);

	nUserDataCounter++;
}

const char* CUserData3::GetKey(void)
{
	return szName;
}

void CUserData3::PrintNode(void)
{
#ifdef _DEBUG
	printf("[%p] %s\t%s [%p]\n", this, szName, szPhone, GetNext());
#else
	printf("%s\t%s\n", szName, szPhone);
#endif
}