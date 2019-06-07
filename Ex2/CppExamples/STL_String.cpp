#include "stdafx.h"
#include <string>


int _tmain(int argc, _TCHAR* argv[])
{
	string strName;
	cout << "이름: ";
	cin >> strName;
	cout << "당신의 이름은 " + strName + "입니다." << endl;

	return 0;
}