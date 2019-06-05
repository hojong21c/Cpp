#include "stdafx.h"
#include "MyString.h"

//기본 생성자
CMyString::CMyString() : m_pszData(NULL), m_nLength(0)
{

}

//복사 생성자
CMyString::CMyString(const CMyString& rhs) : m_pszData(NULL), m_nLength(0)
{
	this->SetString(rhs.GetString());
}

//변환 생성자
CMyString::CMyString(const char* pszParam) : m_pszData(NULL), m_nLength(0)
{
	SetString(pszParam);
}

//이동 생성자
CMyString::CMyString(CMyString&& rhs) : m_pszData(NULL), m_nLength(0)
{
	cout << "CMySTring 이동 생성자 호출" << endl;

	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;
}
//소멸자 - 메모리 해제
CMyString::~CMyString()
{
	Release();
}

// 문자열 Setter
int CMyString::SetString(const char* pszParam) 
{
	Release();
	if (pszParam == NULL)
		return 0;

	int nLength = strlen(pszParam);
	if (nLength == 0)
		return 0;

	m_pszData = new char[nLength + 1];

	strcpy_s(m_pszData, sizeof(char) * (nLength + 1), pszParam);
	m_nLength = nLength;

	return nLength;
}

// 문자열 Getter
const char* CMyString::GetString() const
{
	return m_pszData;
}

// 메모리 해제
void CMyString::Release()
{
	if (m_pszData != NULL)
		delete[] m_pszData;

	m_pszData = NULL;
	m_nLength = 0;
}

// 기본 대입 연산자
// const 로 입력받고 참조변수를 return
CMyString& CMyString::operator=(const CMyString& rhs)
{
	if (this != &rhs)
		this->SetString(rhs.GetString());

	return *this;
}