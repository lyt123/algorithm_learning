#include <iostream>
#include <vector>
using namespace std;

int maxValue(vector<int> w, vector<int> v, int n, int cap) {
	// write code here
	int ** dp = new int *[n];
	for (int i = 0; i< n; i++) {
		dp[i] = new int[cap + 1];
	}

	for (int i = 0; i< n; i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i<cap + 1; i++) {
		//这样的写法是错的
		//int num = i / w[0];
		//dp[0][i] = num * v[0];


		if (i >= w[0])
			dp[0][i] = v[0];
		else
			dp[0][i] = 0;
	}

	for (int i = 1; i<n; i++) {
		for (int j = 1; j< cap + 1; j++) {
			//这里比较用的是dp[i-1][j - w[i]] + v[i]，我一直写成dp[i][j - w[i]] + v[i]，是不对的，把找零钱问题带到了这里来了
			if (j >= w[i] && dp[i - 1][j] < (dp[i-1][j - w[i]] + v[i]))
				dp[i][j] = dp[i][j - w[i]] + v[i];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n - 1][cap];
}


int mainbbzd()
{
	/*vector<int> w = { 1,2,3 };
	vector<int> v = { 1,2,3 };
	int res = maxValue(w, v, 3, 6);*/
	vector<int> w = { 42,25,30,35,42,21,26,28 };
	vector<int> v = { 261,247,419,133,391,456,374,591 };
	int res = maxValue(w, v, 8, 297);
	int a = 54;
	system("pause");
	return 0;
}