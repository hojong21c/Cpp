#include "stdafx.h"
#include <iostream>
using namespace std;

/*
	Aggregation 관계
	- CMyUI 클래스의 인스턴스가 선언될 때 CMyList1 클래스의 인스턴스가 참조로 전달
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
	CMyList1() : m_HeadNode("Dummy Head") {}
	~CMyList1()
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
	CMyUI(CMyList1 &rList) : m_list(rList){}
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
	CMyList1 &m_list;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyList1 list;
	CMyUI ui(list);
	ui.Run();

	return 0;
}