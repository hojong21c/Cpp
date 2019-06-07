#include "stdafx.h"
#include <memory>
#include <iostream>
#include <string.h>
using namespace std;

template<typename T>
T Add(T a, T b) { return a + b; }

template<>
char* Add( char* pszLeft,  char* pszRight)
{
	int nLenLeft = strlen(pszLeft);
	int nLenRight = strlen(pszRight);
	char* pszResult = new char[nLenLeft + nLenRight + 1];

	strcpy_s(pszResult, nLenLeft + 1, pszLeft);
	strcpy_s(pszResult + nLenLeft, nLenRight + 1, pszRight);

	return pszResult;
}

int _tmain(int argc, _TCHAR* argv)
{
	int nResult = Add<int>(3, 4);
	cout << nResult << endl;


	char* pszResult = Add<char*>((char*)"Hello", (char*)"World");
	cout << pszResult << endl;
	delete[] pszResult;

	return 0;
}