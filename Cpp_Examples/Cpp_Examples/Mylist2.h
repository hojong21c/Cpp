#pragma once
#include "MyNode.h"

// ��� Ŭ������ ���� �˸� ����
class CMyNode;

class CMyList2
{
public:
	CMyList2(CMyNode* pHead);
	~CMyList2(void);

protected:
	void ReleaseList(void);
	CMyNode* m_pHead;

public:
	CMyNode* FindNode(const char* pszKey);
	int AddNewNode(CMyNode* pNewNode);
	void PrintAll(void);
	int RemoveNode(const char* spzKey);
};