#include "stdafx.h"
#include "MyList3.h"
#include "UserData3.h"

CMyList3::CMyList3(CMyNode3* pHead)
{
	m_pHead = pHead;
}

CMyList3::~CMyList3(void)
{
	ReleaseList();
}

int CMyList3::AddNewNode(CMyNode3* pNewNode)
{
	if (FindNode(pNewNode->GetKey()) != NULL)
	{
		delete pNewNode;
		return 0;
	}

	
	if(OnAddNewNode(pNewNode))
	{
		pNewNode->pNext = m_pHead->pNext;
		m_pHead->pNext = pNewNode;

		return 1;
	}
	return -1;
}


/*
void CMyList3::PrintAll(void)
{
	CMyNode3* pTmp = m_pHead->pNext;

	while (pTmp != NULL)
	{
		pTmp->PrintNode();
		pTmp = pTmp->pNext;
	}

	printf("CUserData Couner : %d\n", CUserData3::GetUserDataCounter());


}
*/

CMyNode3* CMyList3::FindNode(const char* pszKey)
{
	CMyNode3* pTmp = m_pHead->pNext;
	while (pTmp != NULL)
	{
		if (strcmp(pTmp->GetKey(), pszKey) == 0)
			return pTmp;

			pTmp = pTmp->pNext;
	}

	return NULL;
}

int CMyList3::RemoveNode(const char* pszKey)
{
	CMyNode3* pPrevNode = m_pHead;
	CMyNode3* pDelete = NULL;

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

void CMyList3::ReleaseList(void)
{
	CMyNode3* pTmp = m_pHead;
	CMyNode3* pDelete = NULL;

	while (pTmp != NULL)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		delete pDelete;
	}
	m_pHead = NULL;
}

CMyIterator CMyList3::MakeIterator(void)
{
	CMyIterator it;
	it.m_pCurrent = m_pHead->pNext;
	it.m_pHead = m_pHead->pNext;

	return it;
}

int CMyList3::OnAddNewNode(CMyNode3* pNewNode)
{
	return 1;
}