/*
不难，但是边界问题一定要注意。好比这里如果所要搜索的字符长度如果小于3，nextval数组的获取就要有所不同了
*/
#include<iostream>
#include<vector>
using namespace std;
void get_nextval(string & str, vector<int> & nextval) {
	nextval.push_back(0);
	int index = 1;
	while (index < str.size() - 2) {
		if (str[index] == str[nextval[index - 1]]) {
			nextval.push_back(nextval[index - 1] + 1);
		}
		else if (str[index] == str[0]) {
			nextval.push_back(1);
		}
		else {
			nextval.push_back(0);
		}
		index++;
	}
	nextval.push_back(0);

	//进一步优化
	for (int i = 1; i < str.size() - 3; i++) {
		if (nextval[i] < nextval[i + 1]) {
			nextval[i] = 0;
		}
	}
}

bool checkSubStrExist(string & src, string & str) {
	vector<int> nextval;
	//注意这里
	if (str.size() < 3) {
		nextval.push_back(0);
	}
	else {
		get_nextval(str, nextval);
	}
	//vector<int> better_nextval = get_better_nextval(str, nextval);

	//从头开始比对，没找到就回溯
	int str_point = 0, src_point = 0;

	while (
		src_point <= src.size() - 1 &&
		str_point <= str.size() - 1
		) {

		if (src[src_point] == str[str_point]) {  
			//相等 比较下去
			str_point++;
			src_point++;
		}
		else if (str_point == 0) {				 //str的第一个元素和src的第一个元素不等  src_point往后移
			src_point++;
		}
		else {									 //回溯
			str_point = nextval[str_point - 1];
		}

	}
	return (str_point == str.size()) ? true : false;
}

bool chkRotation(string A, int lena, string B, int lenb) {
	if (lena != lenb || A.empty() || B.empty()) {
		return false;
	}

	A = A + A;
	if (checkSubStrExist(A, B)) {
		return true;
	}
	return false;
}
int mainzx()
{
	//string A = "abcde";
	//string B = "deabc";
	//cout << (chkRotation(A, 5, B, 5) ? "yes" : "no") << endl;

	string A = "cba";
	string B = "adc";
	cout << (chkRotation(A, 4, B, 4) ? "yes" : "no") << endl;
	
	system("pause");
	return 0;
}