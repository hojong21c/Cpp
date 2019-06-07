
#pragma once

class StringEx
{
public: // 생성자
	StringEx();
	~StringEx();
	StringEx(const StringEx& rhs);
	explicit StringEx(const char* pszParam);
	StringEx(StringEx&& rhs);

private:
	// 문자열
	char* charactor_string;
	int charactor_string_length;

public://연산자 함수
	StringEx& operator=(const StringEx& rhs);
	StringEx& operator+=(const StringEx& rhs);
	StringEx operator+(const StringEx& rhs);
	int operator==(const StringEx& rhs);
	int operator!=(const StringEx& rhs);
	char& operator[](int nIndex);
	char operator[](int nIndex) const;

	//  (char*)const string을 위한 (char*) 연산자
	operator char* () const
	{
		return charactor_string;
	}
	// 문자열 처리
	int GetCharStringLength() const;
	int Append(const char* pszParam);

	int SetCharString(const char* pszParam);
	const char* GetCharString() const;
	void Release();

	//friend 선언 -> private member 에 직접 접근
	friend StringEx operator+(const char* pszParam, const StringEx& strParam);
};

