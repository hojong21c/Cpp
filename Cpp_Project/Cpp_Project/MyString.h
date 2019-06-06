
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

public://연산자 함수
	CMyString& operator=(const CMyString& rhs);
	CMyString& operator+=(const CMyString& rhs);
	CMyString operator+(const CMyString& rhs);
	int operator==(const CMyString& rhs);
	int operator!=(const CMyString& rhs);
	char& operator[](int nIndex);
	char operator[](int nIndex) const;

	//  (char*)const string을 위한 (char*) 연산자
	operator char* () const
	{
		return m_pszData;
	}
	// 문자열 처리
	int GetLength() const;
	int Append(const char* pszParam);

	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();

	//friend 선언 -> private member 에 직접 접근
	friend CMyString operator+(const char* pszParam, const CMyString& strParam);
};

