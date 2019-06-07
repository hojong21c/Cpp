#pragma once
#include "P1String.h"

class P2String : public P1String
{
public:
	P2String();
	P2String(const char* input_string);
	~P2String();
	int Find(const char* input_string);
	void OnSetString(char* pszData, int input_string_length); // virtal 구현을 위한 선언
};