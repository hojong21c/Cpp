#include "stdafx.h"
#include "MyString.h"

StringEx::StringEx() : charactor_string(NULL), charactor_string_length(0)
{

}

StringEx::StringEx(const StringEx& rhs) : charactor_string(NULL), charactor_string_length(0)
{
	this->SetCharString(rhs.GetCharString());
}

StringEx::StringEx(const char* input_string) : charactor_string(NULL), charactor_string_length(0)
{
	SetCharString(input_string);
}

StringEx::StringEx(StringEx&& rhs) : charactor_string(NULL), charactor_string_length(0)
{
	cout << "이동 생성자" << endl;

	charactor_string = rhs.charactor_string;
	charactor_string_length = rhs.charactor_string_length;

	rhs.charactor_string = NULL;
	rhs.charactor_string_length = 0;
}

StringEx::~StringEx()
{
	Release();
}

int StringEx::SetCharString(const char* input_string)
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

	return input_string_length;
}

const char* StringEx::GetCharString() const
{
	return charactor_string;
}

void StringEx::Release()
{
	if (charactor_string != NULL)
		delete[] charactor_string;

	charactor_string = NULL;
	charactor_string_length = 0;
}

StringEx& StringEx::operator=(const StringEx& rhs)
{
	if (this != &rhs)
		this->SetCharString(rhs.GetCharString());

	return *this;
}

int StringEx::GetCharStringLength() const
{
	return charactor_string_length;
}

int StringEx::Append(const char* input_string)
{
	if (input_string == NULL)
		return 0;

	int string_length_temp2 = strlen(input_string);
	if (string_length_temp2 == 0)
		return 0;

	if (charactor_string == NULL)
	{
		SetCharString(input_string);
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

StringEx StringEx::operator+(const StringEx& rhs)
{
	StringEx strResult(charactor_string);
	strResult.Append(rhs.GetCharString());

	return strResult;
}

StringEx operator+(const char* input_string, const StringEx& strParam)
{
	StringEx strResult(input_string);
	strResult.Append(strParam.charactor_string);

	return strResult;
}

StringEx& StringEx::operator+=(const StringEx& rhs)
{
	Append(rhs.GetCharString());
	return *this;
}

char& StringEx::operator[](int nIndex)
{
	return charactor_string[nIndex];
}

char StringEx::operator[](int nIndex) const
{
	return charactor_string[nIndex];
}

int StringEx::operator==(const StringEx& rhs)
{
	if (charactor_string != NULL && rhs.charactor_string != NULL)
		if (strcmp(charactor_string, rhs.charactor_string) == 0)
			return 1;

	return 0;
}

int StringEx::operator!=(const StringEx& rhs)
{
	if (charactor_string != NULL && rhs.charactor_string != NULL)
		if (strcmp(charactor_string, rhs.charactor_string) == 0)
			return 0;

	return 1;
}