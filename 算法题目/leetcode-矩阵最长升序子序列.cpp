/*
总结：下面是我的思路过程，突破点是在最后画了一个5*5的matrix，眼睛寻找的思路就是找最小的数，然后找其最长路径，很快就得出结果
int longestIncreasingPath(vector<vector<int>>& matrix) {
	int cols, rows;
	i=0/cols  max(left/right) return;
	j=0/rows  max(up/down)    return;
	for(i in cols)
	for(j in rols)
	max(up,down,left,right) from matrix[i][j]
	return max;
}
//可以记忆搜索了  dp[i][j]代表从matrix[i][j]开始的最长子序列   还不行，考虑到节点不能重复访问的情况    不会有，如果从大的找起

//想下dp方法，想不到就用记忆搜索了dp[i][j] = dp[i-1][j] dp[i][j-1] dp[i+1][j] dp[i][j+1] 比较dp[i][j]是否大于他们，是则dp[i][j] = ta+1

//漏考虑了一点->不能有环绕，所以得有个visited记录

//感觉很难想出来啊，dp的动态转移方程

//画了一个5*5的matrix后找到思路了，应该就是标准答案了

//写的过程中遇到的曲折：
pair<int, pair<int,int>> 原本想用这样的结构存 <matrix, <i,j>> 但map在sort时出问题，所以改成了用vector，以后直接用vector吧
*/

//https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/description/
#include<iostream>
#include<vector>
#include<string>
#include<fstream> 
#include<map> 
#include<algorithm>
using namespace std;
bool my_sor1t(const vector<int> &a, const vector<int>& b) {
	return a[2] < b[2];
}

int count(vector<vector<int>>& matrix, vector<vector<int>>& my_map, vector<vector<int>>& help) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	int res = 0;

	for (int k = 0; k < my_map.size(); k++) {
		int max = 0;
		int i = my_map[k][0];
		int j = my_map[k][1];
		//dp[i - 1][j] dp[i][j - 1] dp[i + 1][j] dp[i][j + 1]
		if (i - 1 >= 0 && matrix[i - 1][j] < matrix[i][j] && help[i - 1][j] > max) {
			max = help[i - 1][j];
		}
		if (j - 1 >= 0 && matrix[i][j - 1] < matrix[i][j] && help[i][j - 1] > max) {
			max = help[i][j - 1];
		}
		if (i + 1 <= rows - 1 && matrix[i + 1][j] < matrix[i][j] && help[i + 1][j] > max) {
			max = help[i + 1][j];
		}
		if (j + 1 <= cols - 1 && matrix[i][j + 1] < matrix[i][j] && help[i][j + 1] > max) {
			max = help[i][j + 1];
		}
		help[i][j] = max + 1;
		if (help[i][j] > res) res = help[i][j];
	}
	return res;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();

	//dp数组
	int m, n;
	m = rows, n = cols;
	vector<vector<int>>help;
	vector<int> one_layer(n, -1);
	for (int i = 0; i < m; i++) {
		help.push_back(one_layer);
	}

	//my_map数组
	vector<vector<int>> my_map;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			one_layer.clear();
			one_layer.push_back(i);
			one_layer.push_back(j);
			one_layer.push_back(matrix[i][j]);
			my_map.push_back(one_layer);
		}
	}

	sort(my_map.begin(), my_map.end(), my_sor1t);
	return count(matrix, my_map, help);
}

//动态生成m行n列的二维数组
int mainzdl()
{
	vector<vector<int>> help;
	int n = 3;
	vector<int> one_layer;
	int a, b, c;


	fstream myfile;
	myfile.open("xx.txt", ios::in);

	while (myfile >> a >> b >> c) {
		one_layer.push_back(a);
		one_layer.push_back(b);
		one_layer.push_back(c);
		help.push_back(one_layer);
		one_layer.clear();
	}

	int res = longestIncreasingPath(help);
	int asdfs = 5;
	system("pause");
	return 0;
}