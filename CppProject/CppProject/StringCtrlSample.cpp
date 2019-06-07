#include "stdafx.h"
#include "MyStringEx.h"

//테스트 함수
void TestFunc(const CMyString& strParam)
{
	cout << strParam << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CMyStringEx strLeft("Hello"), strRight("World");
	cout << strLeft + strRight << endl;

	return 0;
}

