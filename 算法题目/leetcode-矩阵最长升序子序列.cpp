/*
�ܽ᣺�������ҵ�˼·���̣�ͻ�Ƶ����������һ��5*5��matrix���۾�Ѱ�ҵ�˼·��������С������Ȼ�������·�����ܿ�͵ó����
int longestIncreasingPath(vector<vector<int>>& matrix) {
	int cols, rows;
	i=0/cols  max(left/right) return;
	j=0/rows  max(up/down)    return;
	for(i in cols)
	for(j in rols)
	max(up,down,left,right) from matrix[i][j]
	return max;
}
//���Լ���������  dp[i][j]�����matrix[i][j]��ʼ���������   �����У����ǵ��ڵ㲻���ظ����ʵ����    �����У�����Ӵ������

//����dp�������벻�����ü���������dp[i][j] = dp[i-1][j] dp[i][j-1] dp[i+1][j] dp[i][j+1] �Ƚ�dp[i][j]�Ƿ�������ǣ�����dp[i][j] = ta+1

//©������һ��->�����л��ƣ����Ե��и�visited��¼

//�о��������������dp�Ķ�̬ת�Ʒ���

//����һ��5*5��matrix���ҵ�˼·�ˣ�Ӧ�þ��Ǳ�׼����

//д�Ĺ��������������ۣ�
pair<int, pair<int,int>> ԭ�����������Ľṹ�� <matrix, <i,j>> ��map��sortʱ�����⣬���Ըĳ�����vector���Ժ�ֱ����vector��
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

	//dp����
	int m, n;
	m = rows, n = cols;
	vector<vector<int>>help;
	vector<int> one_layer(n, -1);
	for (int i = 0; i < m; i++) {
		help.push_back(one_layer);
	}

	//my_map����
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

//��̬����m��n�еĶ�ά����
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