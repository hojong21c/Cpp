#pragma once
#include "MyString.h"

class CMyStringEx : public CMyString
{
public:
	CMyStringEx();
	CMyStringEx(const char* pszParam);
	~CMyStringEx();
	int Find(const char* pszParam);
	void OnSetString(char* pszData, int nLength); // virtal 구현을 위한 선언
};