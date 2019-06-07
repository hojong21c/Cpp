#include "stdafx.h"
#include "P1String.h"

P1String::P1String() : charactor_string(NULL), charactor_string_length(0)
{

}

P1String::P1String(const P1String& rhs) : charactor_string(NULL), charactor_string_length(0)
{
	this->SetString(rhs.GetString());
}

P1String::P1String(const char* input_string) : charactor_string(NULL), charactor_string_length(0)
{
	SetString(input_string);
}

P1String::P1String(P1String&& rhs) : charactor_string(NULL), charactor_string_length(0)
{
	cout << "P1String 이동 생성자" << endl;

	charactor_string = rhs.charactor_string;
	charactor_string_length = rhs.charactor_string_length;

	rhs.charactor_string = NULL;
	rhs.charactor_string_length = 0;
}

P1String::~P1String()
{
	Release();
}


const char* P1String::GetString() const
{
	return charactor_string;
}

void P1String::Release()
{
	if (charactor_string != NULL)
		delete[] charactor_string;

	charactor_string = NULL;
	charactor_string_length = 0;
}

P1String& P1String::operator=(const P1String& rhs)
{
	if (this != &rhs)
		this->SetString(rhs.GetString());

	return *this;
}

int P1String::GetLength() const
{
	return charactor_string_length;
}

int P1String::Append(const char* input_string)
{
	if (input_string == NULL)
		return 0;

	int string_length_temp2 = strlen(input_string);
	if (string_length_temp2 == 0)
		return 0;

	if (charactor_string == NULL)
	{
		SetString(input_string);
		return charactor_string_length;
	}

	int string_length_temp1 = charactor_string_length;
	char* pszResult = new char[string_length_temp1 + string_length_temp2 + 1];

	strcpy_s(pszResult, sizeof(char) * (string_length_temp1 + 1), charactor_string);
	strcpy_s(pszResult + (sizeof(char) * string_length_temp1), sizeof(char) * (string_length_temp2 + 1), input_string);

	Release();
	charactor_string = pszResult;
	charactor_string_length = string_length_temp1 + string_length_temp2;

	return charactor_string_length;
}

P1String P1String::operator+(const P1String& rhs)
{
	P1String strResult(charactor_string);
	strResult.Append(rhs.GetString());

	return strResult;
}

P1String operator+(const char* input_string, const P1String& strParam)
{
	P1String strResult(input_string);
	strResult.Append(strParam.charactor_string);

	return strResult;
}

P1String& P1String::operator+=(const P1String& rhs)
{
	Append(rhs.GetString());
	return *this;
}

char& P1String::operator[](int nIndex)
{
	return charactor_string[nIndex];
}

char P1String::operator[](int nIndex) const
{
	return charactor_string[nIndex];
}

int P1String::operator==(const P1String& rhs)
{
	if (charactor_string != NULL && rhs.charactor_string != NULL)
		if (strcmp(charactor_string, rhs.charactor_string) == 0)
			return 1;

	return 0;
}

int P1String::operator!=(const P1String& rhs)
{
	if (charactor_string != NULL && rhs.charactor_string != NULL)
		if (strcmp(charactor_string, rhs.charactor_string) == 0)
			return 0;

	return 1;
}

void P1String::OnSetString(char* pszData, int nLegnth)
{

}

int P1String::SetString(const char* input_string)
{
	Release();

	if (input_string == NULL)
		return 0;

	int input_string_length = strlen(input_string);
	if (input_string_length == 0)
		return 0;

	charactor_string = new char[input_string_length + 1];

	strcpy_s(charactor_string, sizeof(char) * (input_string_length + 1), input_string);
	charactor_string_length = input_string_length;

	OnSetString(charactor_string, charactor_string_length);

	return input_string_length;
}
