#pragma once
#include "MyNode.h"

// CMyNode 클래스의 파생 클래스로 변경
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

	// pNext 멤버가 사라졌다!
	static int nUserDataCounter;

public:
	// 순수 가상 함수들 정의
	virtual const char* GetKey(void);
	virtual void PrintNode(void);
};