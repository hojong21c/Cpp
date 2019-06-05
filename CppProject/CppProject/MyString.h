#pragma once

class CMyString
{
public:
	CMyString();
	~CMyString();
	CMyString(const CMyString& rhs); //���� ������
	explicit CMyString(const char* pszParam); //��ȯ ������
	CMyString(CMyString&& rhs); // �̵� ������
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
	CMyString& operator=(const CMyString& rhs); //���� ������
	
private:
	// ���ڿ� ����
	char* m_pszData;
	// ���ڿ� ����
	int m_nLength;
};