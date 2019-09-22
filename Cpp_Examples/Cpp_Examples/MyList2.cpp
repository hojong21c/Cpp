#include "stdafx.h"
#include "MyList2.h"
#include "UserData2.h"

CMyList2::CMyList2(CMyNode2* pHead)
{
	// LoadList() 함수 코드 참고
	m_pHead = pHead;
}

CMyList2::~CMyList2(void)
{
	//SaveList() 함수 코드 참고
	ReleaseList();
}


CMyNode2* CMyList2::FindNode(const char* pszKey)
{
	CMyNode2* pTmp = m_pHead->pNext;

	while (pTmp != NULL)
	{
		if (strcmp(pTmp->GetKey(), pszKey) == 0)
			return pTmp;

		pTmp = pTmp->pNext;
	}

	return NULL;
}

int CMyList2::RemoveNode(const char* pszKey)
{
	CMyNode2* pPrevNode = m_pHead;
	CMyNode2* pDelete = NULL;

	while (pPrevNode->pNext != NULL)
	{
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->GetKey(), pszKey) == 0)
		{
			pPrevNode->pNext = pDelete->pNext;
			delete pDelete;

			return 1;
		}

		pPrevNode = pPrevNode->pNext;
	}

	return 0;
}

void CMyList2::ReleaseList(void)
{
	CMyNode2* pTmp = m_pHead;
	CMyNode2* pDelete = NULL;

	while (pTmp != NULL)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		delete pDelete;
	}

	m_pHead = NULL;
}


int CMyList2::AddNewNode(CMyNode2* pNewNode)
{
	if (FindNode(pNewNode->GetKey()) != NULL)
	{
		delete pNewNode;
		return 0;
	}
	pNewNode->pNext = m_pHead->pNext;
	m_pHead->pNext = pNewNode;

	return 1;
}

void CMyList2::PrintAll(void)
{
	CMyNode2* pTmp = m_pHead->pNext;

	while (pTmp != NULL)
	{
		pTmp->PrintNode();
		pTmp = pTmp->pNext;
	}

	printf("CUserData2 Counter : %d\n", CUserData2::GetUserDataCounter());
}