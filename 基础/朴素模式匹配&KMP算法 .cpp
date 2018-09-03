#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//#define SRC_LEN 15
//#define STR_LEN 7
//����1
//char src[SRC_LEN] = "dgoogddkgoogle";
//char str[STR_LEN] = "google";
//int nextval[6] = { 0,0,0,0,1,0 };

//����2
//char src[SRC_LEN] = "dgoogodkgoogoe";
//char str[STR_LEN] = "googoe";
//int nextval[6] = { 0,0,0,0,1,2 };

//����3				 ababaaaba
//#define SRC_LEN 50
//#define STR_LEN 10
//char src[SRC_LEN] = "ababaaabkgoababaaabadsfabaeds";
//char str[STR_LEN] = "ababaaaba";
//int nextval[10] = { 0,0,1,2,3,1,1,2 };
//int better_nextval[10] = { 0,0,0,0,3,1,0,0 };


//����4				 ababaaaba
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
	//���������һ������ر����
	//��һ���룬�ñ�"abcabdabf"��nextval[]Ϊ{000120120}����2�½�Ϊ0����һ��ֵ����Ҫ������
	for (int i = 1; i < STR_LEN - 3; i++) {
		if (nextval[i] >= nextval[i + 1]) {
			better_nextval[i] = nextval[i];
		}
	}

	//���һ��Ԫ������Դ�
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

//��ͨƥ���㷨
void str_match() {
	//��ͷ��ʼ�ȶԣ�û�ҵ��ͻع�
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
		cout << "ƥ��ɹ�";
	}
}

//KMP�㷨
void str_match_kmp() {
	//��ͷ��ʼ�ȶԣ�û�ҵ��ͻ���
	int str_point = 0, src_point = 0;

	while (
		src_point < SRC_LEN - 1 &&
		str_point < STR_LEN - 1
		) {

		if (src[src_point] == str[str_point]) {  //��� �Ƚ���ȥ
			str_point++;
			src_point++;
		}
		else if (str_point == 0) {				 //str�ĵ�һ��Ԫ�غ�src�ĵ�һ��Ԫ�ز���  src_point������
			src_point++;
		}
		else {									 //����
			str_point = nextval[str_point-1];
		}

	}
	if (str_point == STR_LEN - 1) {
		cout << "ƥ��ɹ�";
	}
}

//KMP�㷨������-���ٻ���
void str_match_better_kmp() {
	//��ͷ��ʼ�ȶԣ�û�ҵ��ͻ���
	int str_point = 0, src_point = 0;

	while (
		src_point < SRC_LEN - 1 &&
		str_point < STR_LEN - 1
		) {

		if (src[src_point] == str[str_point]) {  //��� �Ƚ���ȥ
			str_point++;
			src_point++;
		}
		else if (str_point == 0) {				 //str�ĵ�һ��Ԫ�غ�src�ĵ�һ��Ԫ�ز���  src_point������
			src_point++;
		}
		else {									 //����
			str_point = better_nextval[str_point - 1];
		}

	}
	if (str_point == STR_LEN - 1) {
		cout << "ƥ��ɹ�";
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