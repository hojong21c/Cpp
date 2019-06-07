#include "stdafx.h"
#include "MyStringEx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyStringEx strTest;
	strTest.SetString("∏€∏€¿Ã æ∆µÈ");
	cout << strTest << endl;

	return 0;
}

