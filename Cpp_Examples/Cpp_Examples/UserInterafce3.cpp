#include "stdafx.h"
#include "UserInterface3.h"
#include "MyList3.h"
#include "UserData3.h"
#include "MyIterator.h"


CUserInterface3::CUserInterface3(CMyList3& rList)
: m_List(rList)
{

}

CUserInterface3::~CUserInterface3(void)
{

}

void CUserInterface3::Add(void)
{
	char szName[32] = { 0 };
	char szPhone[32] = { 0 };

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	printf("Input phone number : ");

	fflush(stdin);
	gets_s(szPhone, sizeof(szPhone));

	int nResult = m_List.AddNewNode(new CUserData3(szName, szPhone));

	if (nResult == 0)
	{
		puts("ERROR: 이미 존재하는 데이터입니다.");
	}

	else if (nResult == -1)
	{
		puts("ERROR : 욕설을 이름으로 쓸 수 없습니다.");
	}	
}

int CUserInterface3::PrintUI(void)
{
	int nInput = 0;
	system("cls");
	printf("[1]Add\t [2]Search\t [3]Print all\t [4]Remove\t [0]Exit\n:");

	scanf_s("%d", &nInput);
	return nInput;
}

void CUserInterface3::Search(void)
{
	char szName[32] = { 0 };
	CUserData3* pNode = NULL;

	printf("Input name :");

	fflush(stdin);
	gets_s(szName, sizeof(szName));

	pNode = static_cast<CUserData3*>(m_List.FindNode(szName));

	if (pNode != NULL)
	{
		pNode->PrintNode();
	}

	else
	{
		puts("ERROR: 데이터를 찾을 수 없습니다.");
	}
}

void CUserInterface3::Remove(void)
{
	char szName[32] = { 0 };
	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	m_List.RemoveNode(szName);
}

int CUserInterface3::Run(void)
{
	int nMenu = 0;
	while ((nMenu = PrintUI()) != 0)
	{
		switch (nMenu)
		{
		case 1:	//Add
			Add();
			break;
		case 2:
			Search();
			break;
		case 3:
			PrintAll();
			break;
		case 4:
			Remove();
			break;
		}
	}

	return nMenu;
}

void CUserInterface3::PrintAll(void)
{
	CMyIterator it = m_List.MakeIterator();
	CUserData3* pNode = NULL;

	while ((pNode = static_cast<CUserData3*>(it.GetCurrent())) != NULL)
	{
		pNode->PrintNode();
		it.MoveNext();
	}
}