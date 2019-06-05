#include "stdafx.h"
#include "MyString.h"

//�׽�Ʈ �Լ�
void TestFunc(const CMyString& param)
{
	cout << "TestFunc : " << param.GetString() << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CMyString strData, strTest;
	strData.SetString("Hello");
	strTest.SetString("World");

	CMyString strNewData(strData); //���� ����
	cout << strNewData.GetString() << endl;
	TestFunc(strData);

	strNewData = strTest; //���� ����
	cout << strNewData.GetString() << endl;
	TestFunc(strTest);
	
	return 0;
}