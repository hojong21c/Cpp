// UserInterface.cpp: implementation of the CUserInterface class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "UserInterface.h"
#include "MyList.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUserInterface::CUserInterface(CSingleLinkedList &list)
: m_List(list)
{
}

CUserInterface::~CUserInterface()
{

}

void CUserInterface::StartUI()
{
	int nSelect = 0;
	while( (nSelect = PrintUI()) != 0 )
	{
		switch(nSelect)
		{
		case 0:
			return;
			break;

		case 1:
			GetNewData();
			break;

		case 4:
			m_List.PrintAll();
			break;
		}
	}
}

int CUserInterface::PrintUI()
{
	system("cls");
	puts("[1]Insert\t[2]Search\t[3]Delete\t[4]Print all\t[0]Exit");

	int nInput = 0;
	fflush(stdin);
	scanf("%d", &nInput);

	return nInput;
}

void CUserInterface::GetNewData()
{
	cout << "Input name : ";
	cout.flush();
	char szName[32] = {0};
	cin >> szName;

	cout << "Input phone number : ";
	cout.flush();
	char szPhone[32] = {0};
	cin >> szPhone;

	CMyList* pList = (CMyList*)&m_List;
	pList->Insert(szName, szPhone);
}
