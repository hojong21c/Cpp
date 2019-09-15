#include "stdafx.h"
#include "UserData2.h"

int CUserData2::nUserDataCounter = 0;

CUserData2::CUserData2(void) /* : pNext(NULL)*/
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));
	nUserDataCounter++;
}

CUserData2::~CUserData2(void)
{

}

CUserData2::CUserData2(const char* pszName, const char* pszPhone)
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));

	strcpy_s(szName, sizeof(szName), pszName);
	strcpy_s(szName, sizeof(szPhone), pszPhone);

	nUserDataCounter++;
}

const char* CUserData2::GetKey(void)
{
	return szName;
}

void CUserData2::PrintNode(void)
{
#ifdef _DEBUG
	printf("[%p] %s\t%s [%p]\n", this, szName, szPhone, GetNext());
#else
	printf("%s\t%s\n", szName, szPhone);
#endif
}