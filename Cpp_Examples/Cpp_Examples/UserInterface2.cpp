#include "stdafx.h"
#include "UserInterface2.h"
#include "MyList2.h"
#include "UserData2.h"

CUserInterface2::CUserInterface2(CMyList2& rList) : m_List(rList)
{

}

CUserInterface2::~CUserInterface2()
{

}

void CUserInterface2::Add(void)
{
	char szName[32] = { 0 };
	char szPhone[32] = { 0 };

	cout << "Input name :" << endl;
	cin >> szName;
	cout << "Input phone number : " << endl;
	cin >> szPhone;
	
	m_List.AddNewNode(new CUserData2(szName, szPhone));
}

int CUserInterface2::PrintUI(void)
{
	int nInput = 0;

	printf("[1]Add\t[2]Search\t[3]Print all\t[4]Remove\t[0]Exit\n");
	scanf_s("%d", &nInput);

	return nInput;
}

void CUserInterface2::Search(void)
{
	char szName[32] = { 0 };
	CUserData2* pUserData;

	printf("Input name : ");
	fflush(stdin);
	cin >> szName;
	

	//Have to Fix////////////////////////////////////
	pUserData = (CUserData2*)m_List.FindNode(szName);
	/////////////////////////////////////////////////


	if (pUserData != NULL)
	{
		printf("[%p] %s\t%s [%p] \n", pUserData, pUserData->GetName(), pUserData->GetPhone(), pUserData->GetNext());
	}
	else
		puts("ERROR: 데이터를 찾을 수 없습니다.");
}

void CUserInterface2::Remove(void)
{
	char szName[32] = { 0 };
	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	m_List.RemoveNode(szName);
}

int CUserInterface2::Run(void)
{
	int nMenu = 0;
	while ((nMenu = PrintUI()) != 0)
	{
		switch (nMenu)
		{
		case 1:
			printf("1\n");
			Add();
			printf("3\n");
			break;
		case 2:
			Search();
			break;
		case 3:
			m_List.PrintAll();
			break;
		case 4:
			Remove();
			break;

		}
	}

	return nMenu;
}