#pragma once


class CMyNode3
{
	friend class CMyList3;
	friend class CMyIterator;
public:
	CMyNode3(void);
	virtual ~CMyNode3(void);
	CMyNode3* GetNext(void) const { return pNext; }

	// ������ ���� �� �ʿ��� �������̽� �Լ����� ���� ���� �Լ��� ����
	virtual const char* GetKey(void) = 0;
	virtual void PrintNode(void) = 0;

private:
	// ���� ����Ʈ ��ü�� ���� ���
	CMyNode3* pNext;
};