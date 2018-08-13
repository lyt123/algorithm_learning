#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int  NumberOf1(int n) {
	if (n == 0)
		return 0;
	int count = 0;
	if (n > 0) {
		while (n != 0) {
			if (n & 1)
				count++;
			n >>= 1;
		}
	}
	else {
		if (~n == 0)
			return 32;
		while (~n) {
			if ((n & 1) == 0)
				count++;
			n >>= 1;
		}
		count = 32 - count;
	}

	return count;
}
int ejzzmain()
{
	NumberOf1(-5);
	int b = 3;

	int a = 5;
	//cout << sizeof(A) << endl;
	system("pause");
	return 0;
}