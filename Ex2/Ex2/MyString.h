#pragma once

class CMyString
{
public:
	CMyString();
	~CMyString();
	int SetString(const char* pszParam);
	// ��� �б⸸ �����ϹǷ� �޼��带 ���ȭ�Ѵ�.
	const char* GetString() const;
	void Release();
private:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;

	// ����� ���ڿ��� ����
	int m_nLength;
};