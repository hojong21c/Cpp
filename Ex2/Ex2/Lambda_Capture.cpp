#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int nData = 10;
	cout << nData << endl;
	auto TestFunc1 = [](void)->void
	{
		int nData = 1;
		cout << nData << endl;
	};
	TestFunc1();

	auto TestFunc2 = [&nData](void)->void
	{
		cout << ++nData << endl;
	};
	TestFunc2();

	auto TestFunc3 = [nData](void) mutable ->void
	{
		cout << ++nData << endl;
	};
	TestFunc3();

	cout << nData << endl;

	int x = 10, y = 20;

	auto TestFunc4 = [x, y]()->int
	{
		return x + y;
	};

	double p = TestFunc4();
	cout << p << endl;
	
	return 0;
}