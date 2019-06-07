#pragma once

class P1String
{
public: // 생성자
	P1String();
	~P1String();
	P1String(const P1String& rhs); //복사 생성자
	explicit P1String(const char* input_string); //변환 생성자
	P1String(P1String&& rhs); // 이동 생성자

private:
	// 문자열
	char* charactor_string;
	int charactor_string_length;

public://연산자 함수
	P1String& operator=(const P1String& rhs);
	P1String& operator+=(const P1String& rhs);
	P1String operator+(const P1String& rhs);
	int operator==(const P1String& rhs);
	int operator!=(const P1String& rhs);
	char& operator[](int nIndex);
	char operator[](int nIndex) const;

	//  (char*)const string을 위한 (char*) 연산자
	operator char* () const
	{
		return charactor_string;
	}
	// 문자열 처리
	int GetLength() const;
	int Append(const char* input_string);

	int SetString(const char* input_string);
	const char* GetString() const;
	void Release();

	// OnSetString : 문자열 대체 함수 --> virtual
	virtual void OnSetString(char* pszData, int input_string_length);

	//friend 선언 -> private member 에 직접 접근
	friend P1String operator+(const char* input_string, const P1String& strParam);
};