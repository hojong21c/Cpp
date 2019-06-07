#include "stdafx.h"
#include <new>
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest(int nSize)
	{
		m_pszData = new char[nSize];
	}
	~CTest()
	{
		delete[] m_pszData;
		cout << "정상적으로 객체가 소멸함" << endl;
	}

private:
	char* m_pszData;
};

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		int nSize;
		cout << "Input size: ";
		cin >> nSize;
		CTest a(nSize);
	}

	catch (bad_alloc& exp)
	{
		//시스템이 밝힌 원인을 출력한다.
		cout << exp.what() << endl;
		cout << "ERROR: CTest()" << endl;
	}

	return 0;
}