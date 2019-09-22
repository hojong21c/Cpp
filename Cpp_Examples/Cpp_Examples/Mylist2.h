#pragma once
#include "MyNode2.h"

// 노드 클래스에 대한 알림 선언
class CMyNode2;
class CMyList2
{
public:
	CMyList2(CMyNode2* pHead);
	~CMyList2(void);

protected:
	void ReleaseList(void);
	CMyNode2* m_pHead;

public:
	CMyNode2* FindNode(const char* pszKey);
	int AddNewNode(CMyNode2* pNewNode);
	void PrintAll(void);
	int RemoveNode(const char* spzKey);
};