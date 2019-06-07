#pragma once

class P1String
{
public: // ������
	P1String();
	~P1String();
	P1String(const P1String& rhs); //���� ������
	explicit P1String(const char* input_string); //��ȯ ������
	P1String(P1String&& rhs); // �̵� ������

private:
	// ���ڿ�
	char* charactor_string;
	int charactor_string_length;

public://������ �Լ�
	P1String& operator=(const P1String& rhs);
	P1String& operator+=(const P1String& rhs);
	P1String operator+(const P1String& rhs);
	int operator==(const P1String& rhs);
	int operator!=(const P1String& rhs);
	char& operator[](int nIndex);
	char operator[](int nIndex) const;

	//  (char*)const string�� ���� (char*) ������
	operator char* () const
	{
		return charactor_string;
	}
	// ���ڿ� ó��
	int GetLength() const;
	int Append(const char* input_string);

	int SetString(const char* input_string);
	const char* GetString() const;
	void Release();

	// OnSetString : ���ڿ� ��ü �Լ� --> virtual
	virtual void OnSetString(char* pszData, int input_string_length);

	//friend ���� -> private member �� ���� ����
	friend P1String operator+(const char* input_string, const P1String& strParam);
};