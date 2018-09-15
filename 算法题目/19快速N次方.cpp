#include <iostream>
using namespace std;
int getPower(int k, int N) {
	// write code here
	if (k == 0)
		return 0;
	if (k == 1 || N == 0)
		return 1;
	long res = 1;
	long temp = k;
	do {
		if ((N & 1) == 1) {
			res *= temp;
		}
		temp = temp*temp;
		N >>= 1;
		temp %= 1000000007;
		res %= 1000000007;
	} while (N > 0);
	return res;
}

int mainwt()
{
	cout << getPower(2,3) << endl;
	system("pause");
	return 0;
}