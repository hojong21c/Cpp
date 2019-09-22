// SingleLinkedList.h: interface for the CSingleLinkedList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLELINKEDLIST_H__EB525E62_DAD6_4BED_9999_EDCB3EFC3CBB__INCLUDED_)
#define AFX_SINGLELINKEDLIST_H__EB525E62_DAD6_4BED_9999_EDCB3EFC3CBB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyNode.h"

class CSingleLinkedList  
{
public:
	virtual void OnInsert(CMyNode *pNode);

	void PrintAll();
	int Delete(char* pszName);
	CMyNode* Search(char* pszPriKey);
	int Insert(CMyNode *pNode);
	void ReleaseList();
	void Initialize();

	CSingleLinkedList();
	virtual ~CSingleLinkedList();

protected:
	CMyNode	m_Dummy;
};

#endif // !defined(AFX_SINGLELINKEDLIST_H__EB525E62_DAD6_4BED_9999_EDCB3EFC3CBB__INCLUDED_)
