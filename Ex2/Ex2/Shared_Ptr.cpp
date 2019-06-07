#include "stdafx.h"
#include <memory>
#include <iostream>
using namespace std;

/*
	shared_ptr(스마트 포인터)
	- 포인팅 횟수를 계수해서 0이 되면 대상을 삭제합니다.
*/
class CTest
{
public:
	CTest() { cout << "CTest()" << endl; }
	~CTest() { cout << "CTest()" << endl; }
	void TestFunc() { cout << "TestFunc()" << endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	shared_ptr<CTest> ptr1(new CTest);

	cout << "Counter: " << ptr1.use_count() << endl;
	{
		shared_ptr<CTest> ptr2(ptr1);
		cout << "Counter: " << ptr1.use_count() << endl;
		ptr2->TestFunc();
	}
	
	cout << "Counter: " << ptr1.use_count() << endl;
	ptr1->TestFunc();
	cout << "******End******" << endl;

	return 0;
}