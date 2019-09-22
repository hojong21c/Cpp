#pragma once
#include "MyNode3.h"
#include "MyIterator.h"

class CMyNode3;
class CMyList3
{
public:
	CMyList3(CMyNode3* pHead);
	~CMyList3(void);

protected:
	void ReleaseList(void);
	CMyNode3* m_pHead;

public:
	CMyNode3* FindNode(const char* pszKey);
	int AddNewNode(CMyNode3* pNewNode);

	// UI �ڵ�. ����� �ٶ������� �ʴ�.
	// void PrintAll(void);
	int RemoveNode(const char* spzKey);
	
	//�������� �����Ѵ�.
	CMyIterator MakeIterator(void);

	//�����Ͱ� �߰��� ������ ȣ��Ǵ� ���� �Լ�
	virtual int OnAddNewNode(CMyNode3* pNewNode);
};