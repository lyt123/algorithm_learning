#include <iostream>
#include <vector>
using namespace std;

//int recur(vector<vector<int> > &map, int &n, int &m, int x, int y, int len) {
//	if (x == n) {
//		while (y != m) {
//			len += map[n-1][y];
//			y++;
//		}
//		return len;
//	}
//	if (y == m) {
//		while (x != n) {
//			len += map[x][m-1];
//			x++;
//		}
//		return len;
//	}
//	len += map[x][y];
//
//	int go_down = recur(map, n, m, x, y + 1, len);
//	int go_right = recur(map, n, m, x + 1, y, len);
//
//	return go_down > go_right ? go_right : go_down;
//}
//
//int getMin(vector<vector<int> > map, int n, int m) {
//	// write code here
//	int len = 0;
//	return recur(map, n, m, 0, 0, len);
//}

int getMin(vector<vector<int> > map, int n, int m) {
	// write code here
	int **dp = new int*[n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[m];
	}

	dp[0][0] = map[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = map[i][0] + dp[i - 1][0];
	}
	for (int j = 1; j < m; j++) {
		dp[0][j] = map[0][j] + dp[0][j - 1];
	}

	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++) {
			dp[i][j] = map[i][j] + (dp[i - 1][j] > dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j]);
		}
	return dp[n - 1][m - 1];
}


int mainjzzxlj()
{
	vector<int>v1 = { 1,3,5,9 };
	vector<int>v2 = { 8,1,3,4 };
	vector<int>v3 = { 5,0,6,1 };
	vector<int>v4 = { 8,8,4,0 };
	vector<vector<int>>v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	int res = getMin(v, 4, 4);
	int a = 54;
	system("pause");
	return 0;
}