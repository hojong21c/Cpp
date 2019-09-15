#pragma once

class CMyList2;
class CUserInterface2
{
public:
	CUserInterface2(void);
	CUserInterface2(CMyList2& rList);
	~CUserInterface2(void);
	void Add(void);

protected:
	CMyList2& m_List;

public:
	void Search(void);
	void Remove(void);
	int PrintUI(void);
	int Run(void);
};