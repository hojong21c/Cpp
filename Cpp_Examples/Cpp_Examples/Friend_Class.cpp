#include "stdafx.h"
#include <iostream>
using namespace std;

/*
	CMyList1 Ŭ������ CNode Ŭ������ friend Ŭ������ ����
	CMyList1 �� CNode Ŭ������ private ����鿡 ���� ������ �����ϴ�.
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
	list.AddNewNode("�浿");
	list.AddNewNode("ö��");
	list.AddNewNode("����");

	return 0;
}