#include "stdafx.h"
#include "MyString.h"

//테스트 함수
void TestFunc(const CMyString& param)
{
	cout << "TestFunc : " << param.GetString() << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CMyString strData, strTest;
	strData.SetString("Hello");
	strTest.SetString("World");

	CMyString strNewData(strData); //복사 생성
	cout << strNewData.GetString() << endl;
	TestFunc(strData);

	strNewData = strTest; //대입 연산
	cout << strNewData.GetString() << endl;
	TestFunc(strTest);
	
	return 0;
}