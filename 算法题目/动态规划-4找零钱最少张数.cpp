#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//#include <math.h>
#include <iomanip>
using namespace std;

//https://leetcode-cn.com/problems/house-robber/description/
int coinChange(vector<int>& coins, int amount) {
	////if (coins.size() < 5)
		//return 0;
	/*int ** dp = new int *[coins.size()];
	for (int i = 0; i < coins.size(); i++) {
		dp[i] = new int[amount];
	}*/
	int dp[3][11];

	for (int i = 0; i < coins.size(); i++) {
		for (int j = 0; j <= amount; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i <= amount; i++) {
		if (i % coins[0] == 0)
			dp[0][i] = i / coins[0];
	}
	for (int i = 0; i < coins.size(); i++) {
		dp[i][0] = 0;
	}
	for (int i = 1; i < coins.size(); i++) {
		for (int j = 1; j <= amount; j++) {
			if (j >= coins[i] && dp[i - 1][j] != -1 && dp[i][j - coins[i]] != -1) {
				dp[i][j] = min(dp[i][j - coins[i]] + 1, dp[i - 1][j]);
			}
			else {
				if (dp[i - 1][j] != -1) {
					dp[i][j] = dp[i - 1][j];
				}
				else if (j >= coins[i]) {
					dp[i][j] = 1 + dp[i][j - coins[i]];
				}
				else {
					dp[i][j] = -1;
				}
			}
		}
	}
	return dp[coins.size() - 1][amount];
}
int mainsfdf()
{
	vector<int> arr = { 1,2,5 };
	int res = coinChange(arr, 10);
	int asdf = 5;
	//system("pause");
	return 0;
}
//dp[i][j]
//dp[i][j] = max(dp[i][j-money[i]], dp[i-1][j]); //同时如果他俩如果有人为-1，则代表兑不成功，也是失败