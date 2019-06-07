#include "stdafx.h"
#include <iostream>
using namespace std;

/*
	Class Template 
	- 선언과 정의를 분리할 수 있음
	- 정적 멤버를 포함시키는 것이 가능함
*/

template<typename T>
class CTest
{
public:
	CTest();
	T TestFunc();

protected:
	static T m_Data;
};

template<typename T>
CTest<T>::CTest()
{

}

template<typename T>
T CTest<T>::TestFunc()
{
	return m_Data;
}

template<typename T>
T CTest<T>::m_Data = 15;

int _tmain(int argc, _TCHAR* argv[])
{
	CTest<double> a;
	cout << a.TestFunc() << endl;
	return 0;
}