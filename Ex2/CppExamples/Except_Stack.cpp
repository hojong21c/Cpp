#include "stdafx.h"
#include <iostream>
using namespace std;

void TestFunc1()
{
	cout << "***TestFunc1() - Begin***" << endl;
	cout << "****TestFunc1() - End" << endl;
}

void TestFunc2()
{
	cout << "***TestFunc2() - Begin***" << endl;
	TestFunc1();
	cout << "****TestFunc2() - End****" << endl;
}

void TestFunc3()
{
	cout << "***TestFunc3() - Begin ***" << endl;
	TestFunc2();
	cout << "****TestFunc3() - End****" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		TestFunc3();
	}
	catch (...)
	{
		cout << "Exception handling" << endl;
	}
	return 0;
}