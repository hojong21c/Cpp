#pragma once
#include "UserData1.h"

class CMyList1
{
public:
	CMyList1(void);
	~CMyList1(void);

protected:
	void ReleaseList(void);
	CUserData1 m_Head;

public:
	CUserData1* FindNode(const char* pszName);
	int AddNewNode(const char* pszName, const char* pszPhone);
	void PrintAll(void);
	int RemoveNode(const char* pszName);
};