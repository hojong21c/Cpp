#pragma once
#include "MyNode3.h"

// CMyNode Ŭ������ �Ļ� Ŭ������ ����
class CUserData3 : public CMyNode3
{
public:
	CUserData3(void);
	CUserData3(const char* pszName, const char* pszPhone);
	~CUserData3(void);

	const char* GetName(void) const { return szName; }
	const char* GetPhone(void) const { return szPhone; }
	static int GetUserDataCounter(void) { return nUserDataCounter; }

protected:
	char szName[32];
	char szPhone[32];

	// pNext ����� �������!
	static int nUserDataCounter;

public:
	// ���� ���� �Լ��� ����
	virtual const char* GetKey(void);
	virtual void PrintNode(void);
};