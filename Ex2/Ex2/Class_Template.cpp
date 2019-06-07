#include "stdafx.h"
#include <iostream>
using namespace std;

/*
	template 의 범위는 클래스
*/
template<typename T>
class CMyData
{
public:
	CMyData(T param) : m_Data(param) {}
	T GetData() const { return m_Data; }
	operator T() { return m_Data; }
	void SetData(T param) { m_Data = param; }

private:
	T m_data;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyData<int> a(5);
	cout << a << endl;
	CMyData<double> b(123.45);
	cout << b << endl;
	
	return 0;
}