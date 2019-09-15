#include "stdafx.h"
#include "MyList1.h"

CMyList1::CMyList1(void)
{
}
CMyList1::~CMyList1(void)
{
	ReleaseList();
}

int CMyList1::AddNewNode(const char* pszName, const char* pszPhone)
{
	CUserData1* pNewUser = NULL;

	if (FindNode(pszName) != NULL)
		return 0;

	pNewUser = new CUserData1;
	strcpy_s(pNewUser->szName, sizeof(pNewUser->szName), pszName);
	strcpy_s(pNewUser->szPhone, sizeof(pNewUser->szPhone), pszPhone);
	pNewUser->pNext = NULL;

	pNewUser->pNext = m_Head.pNext;
	m_Head.pNext = pNewUser;

	return 1;
}

void CMyList1::PrintAll(void)
{
	CUserData1* pTmp = m_Head.pNext;

	while (pTmp != NULL)
	{
		printf("[%p] %s\t%s [%p]\n", pTmp, pTmp->szName, pTmp->szPhone, pTmp->pNext);

		pTmp = pTmp->pNext;
	}

	printf("CUserData1 Counter : %d\n", CUserData1::GetUserDataCounter());
}

CUserData1* CMyList1::FindNode(const char* pszName)
{
	CUserData1* pTmp = m_Head.pNext;
	while (pTmp != NULL)
	{
		if (strcmp(pTmp->szName, pszName) == 0)
			return pTmp;

		pTmp = pTmp->pNext;
	}

	return NULL;
}


int CMyList1::RemoveNode(const char* pszName)
{
	CUserData1* pPrevNode = &m_Head;
	CUserData1* pDelete = NULL;

	while (pPrevNode->pNext != NULL)
	{
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->szName, pszName) == 0)
		{
			pPrevNode->pNext = pDelete->pNext;
			delete pDelete;

			return 1;
		}
		pPrevNode = pPrevNode->pNext;
	}

	return 0;
}

void CMyList1::ReleaseList(void)
{
	CUserData1* pTmp = m_Head.pNext;
	CUserData1* pDelete = NULL;

	while (pTmp != NULL)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		delete pDelete;
	}

	m_Head.pNext = NULL;
}