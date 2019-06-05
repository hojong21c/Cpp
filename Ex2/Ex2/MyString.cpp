#include "stdafx.h"
#include "MyString.h"

//�⺻ ������
CMyString::CMyString() : m_pszData(NULL), m_nLength(0)
{

}

//���� ������
CMyString::CMyString(const CMyString& rhs) : m_pszData(NULL), m_nLength(0)
{
	this->SetString(rhs.GetString());
}

//��ȯ ������
CMyString::CMyString(const char* pszParam) : m_pszData(NULL), m_nLength(0)
{
	SetString(pszParam);
}

//�̵� ������
CMyString::CMyString(CMyString&& rhs) : m_pszData(NULL), m_nLength(0)
{
	cout << "CMySTring �̵� ������ ȣ��" << endl;

	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;
}
//�Ҹ��� - �޸� ����
CMyString::~CMyString()
{
	Release();
}

// ���ڿ� Setter
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

// ���ڿ� Getter
const char* CMyString::GetString() const
{
	return m_pszData;
}

// �޸� ����
void CMyString::Release()
{
	if (m_pszData != NULL)
		delete[] m_pszData;

	m_pszData = NULL;
	m_nLength = 0;
}

// �⺻ ���� ������
// const �� �Է¹ް� ���������� return
CMyString& CMyString::operator=(const CMyString& rhs)
{
	if (this != &rhs)
		this->SetString(rhs.GetString());

	return *this;
}