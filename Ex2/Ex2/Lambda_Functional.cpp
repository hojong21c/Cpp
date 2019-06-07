#include "stdafx.h"
#include <functional>



void TestFunc(char* pszParam, std::function<int(char*, int)> param)
{
	cout << pszParam << endl;
	param((char*)"Hello", 10);
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	::TestFunc((char*)"TestFunc()", [](char* pszParam, int nParam)->int
		{
			cout << pszParam << " : " << nParam << endl;
			return 0;
		}
	);
}