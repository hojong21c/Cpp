#include "stdafx.h"
#include <iostream>
using namespace std;

/*
	Composition (집합) 관계
	- CMyUI 클래스의 인스턴스가 생성되면 CMyList클래스의 인스턴스도 같이 생성됨.
	- 반대로 CMyUI 클래스 인스턴스가 소멸하면 CMyList 클래스의 인스턴스도 소멸함.
*/

class CNode
{
	friend class CMyList;

public:
	explicit CNode(const char* pszName)
	{
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}

private:
	char m_szName[32];
	CNode* pNext = nullptr;
};

class CMyList
{
public:
	CMyList() : m_HeadNode("Dummy Head"){}
	~CMyList()
	{
		CNode* pNode = m_HeadNode.pNext;
		CNode* pDelete = nullptr;
		while (pNode)
		{
			pDelete = pNode;
			pNode = pNode->pNext;
			delete pDelete;
		}
		m_HeadNode.pNext = nullptr;
	}

	void Add_New_Node(const char* pszName)
	{
		CNode* pNode = new CNode(pszName);
		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

	void Print()
	{
		CNode* pNode = m_HeadNode.pNext;
		while (pNode)
		{
			cout << pNode->m_szName << endl;
			pNode = pNode->pNext;
		}
	}

private:
	CNode m_HeadNode;
};

class CMyUI
{
public:
	int PrintMenu()
	{
		system("cls");
		cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n";
		cout.flush();
		int nInput = 0;
		cin >> nInput;
		return nInput;
	}

	void Run()
	{
		char szName[32];
		int nInput = 0;
		while ((nInput = PrintMenu()) > 0)
		{
			switch (nInput)
			{
			case 1:
				cout << "이름: ";
				cout.flush();
				cin >> szName;
				m_list.Add_New_Node(szName);
				break;
			case 2:
				m_list.Print();
				break;
			default:
				break;
			}
		}
	}

private:
	CMyList m_list;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyUI ui;
	ui.Run();

	return 0;
}