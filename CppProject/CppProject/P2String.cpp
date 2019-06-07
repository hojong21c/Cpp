#include "stdafx.h"
#include "P2String.h"

P2String::P2String()
{
}

P2String::~P2String()
{
}

P2String::P2String(const char* input_string) : P1String(input_string)
{

}
int P2String::Find(const char* input_string)
{
	if (input_string == NULL || GetString() == NULL)
		return -1;
	const char* pszResult = strstr(GetString(), input_string);

	if (pszResult != NULL)
		return pszResult - GetString();

	return -1;
}

// Virtual OnSetString 备泅
void P2String::OnSetString(char* pszData, int input_string_length)
{
	if (strcmp(pszData, "港港捞酒甸") == 0)
		strcpy_s(pszData, sizeof(char) * (input_string_length + 1), "具克捞酒甸");
}
