#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//#define SRC_LEN 15
//#define STR_LEN 7
//测试1
//char src[SRC_LEN] = "dgoogddkgoogle";
//char str[STR_LEN] = "google";
//int nextval[6] = { 0,0,0,0,1,0 };

//测试2
//char src[SRC_LEN] = "dgoogodkgoogoe";
//char str[STR_LEN] = "googoe";
//int nextval[6] = { 0,0,0,0,1,2 };

//测试3				 ababaaaba
//#define SRC_LEN 50
//#define STR_LEN 10
//char src[SRC_LEN] = "ababaaabkgoababaaabadsfabaeds";
//char str[STR_LEN] = "ababaaaba";
//int nextval[10] = { 0,0,1,2,3,1,1,2 };
//int better_nextval[10] = { 0,0,0,0,3,1,0,0 };


//测试4				 ababaaaba
#define SRC_LEN 50
#define STR_LEN 10
char src[SRC_LEN] = "ababaaabkgoaaaaaaaaabadsfabaeds";
//char str[STR_LEN] = "ababaaaba";
char str[STR_LEN] = "aaaaaaaab";
int right_nextval[10] = { 0,0,1,2,3,1,1,2 };
int nextval[10] = { 0 };
int right_better_nextval[10] = { 0,0,0,0,3,1,0,0 };
int better_nextval[10] = { 0 };

void get_better_nextval() {
	//理论依据我还不是特别清楚
	//简单一点想，好比"abcabdabf"，nextval[]为{000120120}当从2下降为0的那一个值才需要保留啊
	for (int i = 1; i < STR_LEN - 3; i++) {
		if (nextval[i] >= nextval[i + 1]) {
			better_nextval[i] = nextval[i];
		}
	}

	//最后一个元素特殊对待
	if (nextval[STR_LEN - 2] < nextval[STR_LEN - 3]) {
		better_nextval[STR_LEN - 3] = nextval[STR_LEN - 3];
	}
}

void get_nextval() {
	nextval[0] = 0;
	int index = 1;
	while (index < STR_LEN-2) {
		if (str[index] == str[nextval[index - 1]]) {
			nextval[index] = nextval[index - 1] + 1;
		}
		else if(str[index] == str[0]) {
			nextval[index] = 1;
		}
		else {
			nextval[index] = 0;
		}
		index++;
	}
}

//普通匹配算法
void str_match() {
	//从头开始比对，没找到就回滚
	int str_point = 0, src_point = 0;

	while (
		src_point < SRC_LEN - 1 &&
		str_point < STR_LEN - 1
		) {
		if (src[src_point] == str[str_point]) {
			src_point++;
			str_point++;
		}
		else {
			src_point = src_point - str_point + 1;
			str_point = 0;
		}

	}
	if (str_point == STR_LEN - 1) {
		cout << "匹配成功";
	}
}

//KMP算法
void str_match_kmp() {
	//从头开始比对，没找到就回溯
	int str_point = 0, src_point = 0;

	while (
		src_point < SRC_LEN - 1 &&
		str_point < STR_LEN - 1
		) {

		if (src[src_point] == str[str_point]) {  //相等 比较下去
			str_point++;
			src_point++;
		}
		else if (str_point == 0) {				 //str的第一个元素和src的第一个元素不等  src_point往后移
			src_point++;
		}
		else {									 //回溯
			str_point = nextval[str_point-1];
		}

	}
	if (str_point == STR_LEN - 1) {
		cout << "匹配成功";
	}
}

//KMP算法改良版-减少回溯
void str_match_better_kmp() {
	//从头开始比对，没找到就回溯
	int str_point = 0, src_point = 0;

	while (
		src_point < SRC_LEN - 1 &&
		str_point < STR_LEN - 1
		) {

		if (src[src_point] == str[str_point]) {  //相等 比较下去
			str_point++;
			src_point++;
		}
		else if (str_point == 0) {				 //str的第一个元素和src的第一个元素不等  src_point往后移
			src_point++;
		}
		else {									 //回溯
			str_point = better_nextval[str_point - 1];
		}

	}
	if (str_point == STR_LEN - 1) {
		cout << "匹配成功";
	}
}

int main() {
	get_nextval();
	get_better_nextval();
	str_match_better_kmp();

	//str_match_kmp();

	system("pause");

	return 0;
}