/*
总结：leetcode题目：https://leetcode.com/problems/course-schedule/description/
这里的关键是-1  0  1这三个状态的设定，如果只设定两个状态，复杂度就变得特别大了
还可以从入度出度的角度去写代码
*/
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
using namespace std;

//有环 返回true  无环 返回false
bool recur(vector<int>&visited, int start, vector<vector<int>>& help) {
	//-1  0  1
	//-1未访问  0正在访问  1已访问	
	if (visited[start] == 0) {
		return true;
	}
	else if (visited[start] == -1) {
		visited[start] = 0;
		for (int j = 0; j < help[start].size(); j++) {
			if (recur(visited, help[start][j], help))
				return true;
		}
		visited[start] = 1;
		return false;
	}
	else {
		return false;
	}
}
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<int>visited(numCourses, -1);
	vector<vector<int>>help;
	vector<int> temp;
	for (int i = 0; i < numCourses; i++) {
		help.push_back(temp);
	}
	for (int i = 0; i < prerequisites.size(); i++) {
		help[prerequisites[i].first].push_back(prerequisites[i].second);
	}
	for (int i = 0; i < numCourses; i++) {
		if (recur(visited, i, help))
			return false;
	}
	return true;
}
int main() {
	//输入：
	/*
	3
	1 0
	2 0
	*/
	vector<pair<int, int>> prerequisites;
	int n;
	int a, b;
	pair<int, int>one_layer;


	fstream myfile;
	myfile.open("1.txt", ios::in);

	myfile >> n;

	while (myfile >> a >> b) {
		one_layer.first = a;
		one_layer.second = b;
		prerequisites.push_back(one_layer);
	}
	bool res = canFinish(n, prerequisites);
	int afsdlj = 3;
	return 0;
}
