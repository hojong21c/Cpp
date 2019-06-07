#include "stdafx.h"
#include <memory>
#include <iostream>
using namespace std;

/*
	auto_ptr(스마트 포인터)
	 - 동적 할당한 인스턴스를 '자동'으로 삭제합니다.
*/

class CMyData
{
public:
	CMyData() { cout << "CMyData()" << endl; }
	~CMyData() { cout << "~CMyData()" << endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	{
		auto_ptr<CMyData> ptrTest(new CMyData);
	}

	cout << "*****End*****" << endl;

	return 0;
}