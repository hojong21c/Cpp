#pragma once

class CUserData1
{
	friend class CMyList1;
public:
	CUserData1(void);
	~CUserData1(void);

	const char* GetName(void) const { return szName; }
	const char* GetPhone(void) const { return szPhone; }
	const CUserData1* GetNext(void) const { return pNext; }
	static int GetUserDataCounter(void) { return nUserDataCounter; }

protected:
	char szName[32];
	char szPhone[32];
	CUserData1* pNext;
	static int nUserDataCounter;
};