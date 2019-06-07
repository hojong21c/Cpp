#include "stdafx.h"
#include <vector>

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec(3);
	vec[0] = 10;
	vec[1] = 10;
	vec[2] = 10;

	for (auto& n : vec)
		cout << n << '\t';

	cout << endl;

	vec.push_back(30);
	vec.push_back(40);

	for (auto& n : vec)
		cout << n << '\t';

	cout << endl;

	return 0;
}