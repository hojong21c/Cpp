// SingleLinkedList.cpp: implementation of the CSingleLinkedList class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "SingleLinkedList.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSingleLinkedList::CSingleLinkedList()
{
	Initialize();
}

CSingleLinkedList::~CSingleLinkedList()
{

}

void CSingleLinkedList::Initialize()
{
	ReleaseList();
}

void CSingleLinkedList::ReleaseList()
{
	m_Dummy.m_pNext = NULL;
}

int CSingleLinkedList::Insert(CMyNode *pNode)
{
	if(Search(pNode->GetPriKey()) != NULL)
		return 0;

	OnInsert(pNode);

	pNode->m_pNext = m_Dummy.m_pNext;
	m_Dummy.m_pNext = pNode;

	return 1;
}

CMyNode* CSingleLinkedList::Search(char *pszPriKey)
{
	CMyNode *pTmp = m_Dummy.m_pNext;
	while(pTmp != NULL)
	{
		if(strcmp(pTmp->GetPriKey(), pszPriKey) == 0)
			return pTmp;

		pTmp = pTmp->m_pNext;
	}

	return NULL;
}

int CSingleLinkedList::Delete(char *pszName)
{
	return 0;
}

void CSingleLinkedList::PrintAll()
{
	CMyNode *pTmp = m_Dummy.m_pNext;
	while(pTmp != NULL)
	{
		pTmp->PrintData();
		pTmp = pTmp->m_pNext;
	}

	getch();
}

void CSingleLinkedList::OnInsert(CMyNode *pNode)
{

}
