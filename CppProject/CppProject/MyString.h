#pragma once

class CMyString
{
public: // ������
	CMyString();
	~CMyString();
	CMyString(const CMyString& rhs); //���� ������
	explicit CMyString(const char* pszParam); //��ȯ ������
	CMyString(CMyString&& rhs); // �̵� ������
	
private:
	// ���ڿ�
	char* m_pszData;
	int m_nLength;

public:
	CMyString& operator=(const CMyString& rhs);
	CMyString& operator+=(const CMyString& rhs);
	CMyString operator+(const CMyString& rhs);

	char& operator[](int nIndex);
	char operator[](int nIndex) const;
	operator char* () const
	{
		return m_pszData;
	}
	int GetLength() const;
	int Append(const char* pszParam);

	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
};