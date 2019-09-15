#pragma once
#include "MyNode.h"

// CMyNode Ŭ������ �Ļ� Ŭ������ ����
class CUserData2 : public CMyNode
{
public:
	CUserData2(void);
	CUserData2(const char* pszName, const char* pszPhone);
	~CUserData2(void);

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