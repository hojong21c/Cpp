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

	// UI 코드. 설계상 바람직하지 않다.
	// void PrintAll(void);
	int RemoveNode(const char* spzKey);
	
	//열거지를 생성한다.
	CMyIterator MakeIterator(void);

	//데이터가 추가될 때마다 호출되는 가상 함수
	virtual int OnAddNewNode(CMyNode3* pNewNode);
};