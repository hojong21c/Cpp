
#pragma once

class StringEx
{
public: // ������
	StringEx();
	~StringEx();
	StringEx(const StringEx& rhs);
	explicit StringEx(const char* input_string);
	StringEx(StringEx&& rhs);

private:
	// ���ڿ�
	char* charactor_string;
	int charactor_string_length;

public://������ �Լ�
	StringEx& operator=(const StringEx& rhs);
	StringEx& operator+=(const StringEx& rhs);
	StringEx operator+(const StringEx& rhs);
	int operator==(const StringEx& rhs);
	int operator!=(const StringEx& rhs);
	char& operator[](int nIndex);
	char operator[](int nIndex) const;

	//  (char*)const string�� ���� (char*) ������
	operator char* () const
	{
		return charactor_string;
	}
	// ���ڿ� ó��
	int GetCharStringLength() const;
	int Append(const char* input_string);

	int SetCharString(const char* input_string);
	const char* GetCharString() const;
	void Release();

	//friend ���� -> private member �� ���� ����
	friend StringEx operator+(const char* input_string, const StringEx& strParam);
};
