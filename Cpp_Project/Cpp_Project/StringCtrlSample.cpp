#include "stdafx.h"
#include "MyString.h"

int _tmain(int argc, _TCHAR* argv[])
{
	StringEx b("Samuel"), c;
	c = "Yun" + b;
	cout << c << endl;

	return 0;
}

