// MyString.h: interface for the CMyString class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

class CMyString;
CMyString operator + (const char* pszBuffer, CMyString& strTmp);

class CMyString  
{
public:
	void Append(const char* pszBuffer);
	void Release();
	void SetString(const char* pszBuffer);
	char* GetString() const;

	CMyString();
	CMyString(const char* pszBuffer);
	CMyString(CMyString &rData);
	virtual ~CMyString();

	CMyString& operator = (CMyString &strTmp);
	CMyString& operator = (const char* pszBuffer);
	CMyString& operator = (int nData);

	CMyString& operator += (CMyString &strTmp);
	CMyString& operator += (const char* pszBuffer);

	CMyString operator + (CMyString &strTmp);
	CMyString operator + (const char* pszBuffer);

	operator char*();

	friend CMyString operator + (const char* pszBuffer, CMyString& strTmp);

protected:
	char* m_pszData;
};

