// MyString.cpp: implementation of the CMyString class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "MyString.h"


CMyString operator + (const char* pszBuffer, CMyString& strTmp)
{
	CMyString strResult;
	strResult.SetString(pszBuffer);
//	strResult.Append(strTmp.GetString());
	strResult.Append(strTmp.m_pszData);
	return strResult;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyString::CMyString()
: m_pszData(NULL)
{
	cout << "CMyString()" << endl;
}

CMyString::CMyString(const char* pszBuffer)
: m_pszData(NULL)
{
	SetString(pszBuffer);
}

CMyString::CMyString(CMyString &rData)
: m_pszData(NULL)
{
	SetString(rData.m_pszData);
}

CMyString::~CMyString()
{
	Release();
	cout << "~CMyString()" << endl;
}

char* CMyString::GetString() const
{
	if(m_pszData == NULL)	return "(NULL)";

	return m_pszData;
}

void CMyString::SetString(const char *pszBuffer)
{
	if(pszBuffer == NULL)
	{
		Release();
		return;
	}

	int nLength = 0;
	nLength = strlen(pszBuffer);
	if(nLength <= 0)
	{
		Release();
		return;
	}

	Release();
	m_pszData = new char[nLength + 1];
	strcpy(m_pszData, pszBuffer);
}

void CMyString::Release()
{
	if(m_pszData != NULL)
	{
		delete [] m_pszData;
		m_pszData = NULL;
	}
}


CMyString& CMyString::operator = (CMyString &strTmp)
{
	SetString(strTmp.m_pszData);
	return *this;
}

CMyString& CMyString::operator = (const char* pszBuffer)
{
	SetString(pszBuffer);
	return *this;
}

CMyString& CMyString::operator = (int nData)
{
	char szBuffer[128] = {0};
	sprintf(szBuffer, "%d", nData);
	SetString(szBuffer);

	return *this;
}

CMyString& CMyString::operator += (CMyString &strTmp)
{
	Append(strTmp.m_pszData);
	return *this;
}

CMyString& CMyString::operator += (const char* pszBuffer)
{
	Append(pszBuffer);
	return *this;
}

void CMyString::Append(const char *pszBuffer)
{
	if(pszBuffer == NULL)			return;
	if(strlen(pszBuffer) <= 0)		return;

	if(m_pszData != NULL)
	{
		int nLenCurrent = strlen(m_pszData);
		int nLenAppend = strlen(pszBuffer);

		char *pszResult = new char[nLenCurrent + nLenAppend + 1];
//		strcpy(pszResult, m_pszData);
//		strcat(pszResult, pszBuffer);

//		sprintf(pszResult, "%s", m_pszData);
//		sprintf(pszResult + nLenCurrent, "%s", pszBuffer);

		strcpy(pszResult, m_pszData);
		strcpy(pszResult + nLenCurrent, pszBuffer);

		Release();
		m_pszData = pszResult;
	}
	else
	{
		SetString(pszBuffer);
	}
}

CMyString CMyString::operator + (CMyString &strTmp)
{
	CMyString strResult;
	strResult.SetString(this->m_pszData);
	strResult.Append(strTmp.m_pszData);

	return strResult;
}

CMyString CMyString::operator + (const char* pszBuffer)
{
	CMyString strResult;
	strResult.SetString(this->m_pszData);
	strResult.Append(pszBuffer);

	return strResult;
}

CMyString::operator char*()
{
	return m_pszData;
}