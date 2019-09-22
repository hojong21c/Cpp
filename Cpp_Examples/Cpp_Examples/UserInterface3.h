#pragma once

class CMyList3;
class CUserInterface3
{
public:
	CUserInterface3(void);
	CUserInterface3(CMyList3& rList);
	~CUserInterface3(void);
	void Add(void);

protected:
	CMyList3& m_List;

public:
	void Search(void);
	void Remove(void);
	int PrintUI(void);
	void PrintAll(void);
	int Run(void);
	
};