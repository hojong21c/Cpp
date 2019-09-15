#include "stdafx.h"
#include "UserData1.h"

int CUserData1::nUserDataCounter = 0;

CUserData1::CUserData1(void):pNext(NULL)
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));

	nUserDataCounter++;
}

CUserData1::~CUserData1()
{
	nUserDataCounter--;
}