#include "stdafx.h"
#include <functional>
#include <iostream>
using namespace std;

class CTestData
{
public:
	CTestData()
	{
		m_array[0] = 30;
		m_array[1] = 10;
		m_array[2] = 50;
		m_array[3] = 40;
		m_array[4] = 20;
	}

	void Print()
	{
		for (auto& n : m_array)
			cout << n << '\t';
		cout << endl;
	}

	void Sort(function<int(int, int)> cmp)
	{
		int nTmp;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = i + 1; j < 5; ++j)
			{
				if (cmp(m_array[i], m_array[j] < 0))
				{
					nTmp = m_array[i];
					m_array[i] = m_array[j];
					m_array[j] = nTmp;
				}
			}
		}
	}

private:
	int m_array[5];
};

int _tmain(int argc, _TCHAR* argv[])
{
	CTestData data;
	data.Sort([](int a, int b)->int {return a - b; });
	data.Print();

	//오름차순 정렬
	data.Sort([](int a, int b)->int {return b - a; });
	data.Print();

	return 0;
}