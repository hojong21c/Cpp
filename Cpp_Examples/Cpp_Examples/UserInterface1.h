#pragma once

class CMyList1;
class CUserInterface1
{
public:
	CUserInterface1(void);
	CUserInterface1(CMyList1& rList);
	~CUserInterface1(void);
	void Add(void);

protected:
	CMyList1& m_List;

public:
	void Search(void);
	void Remove(void);
	int PrintUI(void);
	int Run(void);
};