#pragma once

class CMyString
{
public: // 생성자
	CMyString();
	~CMyString();
	CMyString(const CMyString& rhs); //복사 생성자
	explicit CMyString(const char* pszParam); //변환 생성자
	CMyString(CMyString&& rhs); // 이동 생성자
	
private:
	// 문자열
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