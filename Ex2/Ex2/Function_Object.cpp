#include "stdafx.h"
#include <iostream>
using namespace std;

class Add
{
public:
	int operator()(int a, int b)
	{
		cout << "()(int, int)" << endl;

		return a + b;
	}

	double operator()(double a, double b)
	{
		cout << "()(double, double)" << endl;
		return a + b;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Add adder;

	cout << adder(3, 4) << endl;
	cout << adder(3.3, 4.4) << endl;

	return 0;
}