#include "stdafx.h"
#include "MyString.h"

//테스트 함수
void TestFunc(const CMyString& strParam)
{
	cout << strParam << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CMyString strLeft("Test"), strRight("String");
	if (strLeft == strRight)
		cout << "Same" << endl;
	else
		cout << "Different" << endl;

	strLeft = CMyString("String");

	if (strLeft != strRight)
		cout << "Different" << endl;
	else
		cout << "Same" << endl;

	return 0;
}

	