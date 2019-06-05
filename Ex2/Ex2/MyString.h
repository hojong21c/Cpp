#pragma once

class CMyString
{
public:
	CMyString();
	~CMyString();
	CMyString(const CMyString& rhs); //복사 생성자
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
	CMyString& operator=(const CMyString& rhs); // 대입 연산자
private:
	// 문자열 저장
	char* m_pszData;
	// 문자열 길이
	int m_nLength;
};