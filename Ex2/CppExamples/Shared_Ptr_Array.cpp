#include "stdafx.h"
#include <memory>
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest()" << endl; }
	~CTest() { cout << "~CTest()" << endl; }
	void TestFunc()
	{
		cout << "TestFunc()" << endl;
	}
};

void RemoveTest(CTest* pTest)
{
	cout << "RemoveTest()" << endl;
	delete[] pTest;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	shared_ptr<CTest> ptr(new CTest[3], RemoveTest);
	cout << "*****End*****" << endl;
	ptr.reset();//대상 삭제

	return 0;
}