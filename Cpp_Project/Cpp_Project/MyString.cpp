#include "stdafx.h"
#include "MyString.h"

StringEx::StringEx() : charactor_string(NULL), charactor_string_length(0)
{

}

StringEx::StringEx(const StringEx& rhs) : charactor_string(NULL), charactor_string_length(0)
{
	this->SetCharString(rhs.GetCharString());
}

StringEx::StringEx(const char* pszParam) : charactor_string(NULL), charactor_string_length(0)
{
	SetCharString(pszParam);
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

int StringEx::SetCharString(const char* pszParam)
{
	Release();
	if (pszParam == NULL)
		return 0;

	int nLength = strlen(pszParam);
	if (nLength == 0)
		return 0;

	charactor_string = new char[nLength + 1];

	strcpy_s(charactor_string, sizeof(char) * (nLength + 1), pszParam);
	charactor_string_length = nLength;

	return nLength;
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

int StringEx::Append(const char* pszParam)
{
	if (pszParam == NULL)
		return 0;

	int nLenParam = strlen(pszParam);
	if (nLenParam == 0)
		return 0;

	if (charactor_string == NULL)
	{
		SetCharString(pszParam);
		return charactor_string_length;
	}

	int nLenCur = charactor_string_length;
	char* pszResult = new char[nLenCur + nLenParam + 1];

	strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), charactor_string);
	strcpy_s(pszResult + (sizeof(char) * nLenCur), sizeof(char) * (nLenParam + 1), pszParam);

	Release();
	charactor_string = pszResult;
	charactor_string_length = nLenCur + nLenParam;

	return charactor_string_length;
}

StringEx StringEx::operator+(const StringEx& rhs)
{
	StringEx strResult(charactor_string);
	strResult.Append(rhs.GetCharString());

	return strResult;
}

StringEx operator+(const char* pszParam, const StringEx& strParam)
{
	StringEx strResult(pszParam);
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