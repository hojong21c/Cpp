#include "stdafx.h"
#include "MyStringEx.h"

//�׽�Ʈ �Լ�
void TestFunc(const CMyString& strParam)
{
	cout << strParam << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CMyStringEx strTest;
	strTest.SetString("aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz");
	cout << strTest << endl;

	int nIndex = strTest.Find("jjkk");
	cout << "Index: " << nIndex << endl;

	return 0;
}

