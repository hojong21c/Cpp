#include "stdafx.h"
#include "MyString.h"

//테스트 함수
void TestFunc(const CMyString& strParam)
{
	cout << strParam << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CMyString strParam("HelloWorld");
	cout << strParam << endl;
	TestFunc(strParam);

	return 0;
}

	