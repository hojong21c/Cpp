// MyList.cpp: implementation of the CMyList class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "MyList.h"
#include "UserData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyList::CMyList()
{

}

CMyList::~CMyList()
{

}

int CMyList::Insert(char *pszName, char *pszPhone)
{
	CUserData *pNewUser = new CUserData;
	pNewUser->SetName(pszName);
	pNewUser->SetPhone(pszPhone);

	int nResult = CSingleLinkedList::Insert(pNewUser);
	if(!nResult)
		delete pNewUser;

	return nResult;
}

void CMyList::OnInsert(CMyNode *pNode)
{
	static int nCount = 0;
	nCount++;
	cout << "[Count] " << nCount << endl;

	getch();

//	CSingleLinkedList::OnInsert(pNode);
}