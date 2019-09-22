#pragma once
#include "MyNode3.h"

class CMyIterator
{
	friend class CMyList3;
public:
	CMyIterator(void);
	~CMyIterator(void);

	CMyNode3* GetCurrent(void) const { return m_pCurrent; }
	void MoveNext(void)
	{
		if (m_pCurrent != NULL)
			m_pCurrent = m_pCurrent->pNext;
	}

private:
	CMyNode3* m_pHead;
	CMyNode3* m_pCurrent;
};