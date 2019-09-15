#include "stdafx.h"
#include <iostream>
using namespace std;

/*
	CMyList1 클래스를 CNode 클래스의 friend 클래스로 선언
	CMyList1 는 CNode 클래스의 private 멤버들에 직접 접근이 가능하다.
*/

class CNode
{
	friend class CMyList1;

public:
	explicit CNode(const char* pszName)
	{
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}

private:
	char m_szName[32];
	CNode* pNext = nullptr;
};

class CMyList1
{
public:
	CMyList1() : m_HeadNode("Dummy Head"){}
	~CMyList1()
	{
		CNode* pNode = m_HeadNode.pNext;
		CNode* pDelete = nullptr;

		while (pNode)
		{
			pDelete = pNode;
			pNode = pNode->pNext;

			cout << pDelete->m_szName << endl;
			delete pDelete;
		}

		m_HeadNode.pNext = nullptr;
	}

	void AddNewNode(const char* pszName)
	{
		CNode* pNode = new CNode(pszName);

		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

private:
	CNode m_HeadNode;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyList1 list;
	list.AddNewNode("길동");
	list.AddNewNode("철수");
	list.AddNewNode("영희");

	return 0;
}