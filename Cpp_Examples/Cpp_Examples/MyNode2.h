#pragma once

class CMyNode2
{
	friend class CMyList2;
public:
	CMyNode2(void);
	virtual ~CMyNode2(void);
	CMyNode2* GetNext(void) const { return pNext; }

	// ������ ���� �� �ʿ��� �������̽� �Լ����� ���� ���� �Լ��� ����
	virtual const char* GetKey(void) = 0;
	virtual void PrintNode(void) = 0;

private:
	// ���� ����Ʈ ��ü�� ���� ���
	CMyNode2* pNext;
};