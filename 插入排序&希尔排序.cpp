#include <iostream>
#include <algorithm>
using namespace std;
#define NUM 21

int source_arr[NUM] = { 0,5,1,9,3,7,4,8,1,39,3,7,4,28,12,9,34,7,46,8,26 };

void shell_sort() {
	//int inc = NUM;
	int increment = NUM;

	//简单插入排序
	do {
		increment = increment / 5 + 1;
		for (int i = increment + 1; i < NUM; i += increment) {
			int temp = source_arr[i];
			int j;
			if (temp < source_arr[i - increment]) {//这一步为最下面 source_arr[j+1]=temp做准备
				for (j = i - increment; j >= 0; j -= increment) {
					if (temp < source_arr[j]) {
						source_arr[j + increment] = source_arr[j];
					}
					else {
						break;
					}
				}
				source_arr[j + increment] = temp;
			}

		}
	} while (increment > 1);
}


void insertion_sort() {
	//int inc = NUM;

	//简单插入排序
	for (int i = 1; i < NUM; i++) {
		int temp = source_arr[i];
		int j;
		if (temp < source_arr[i - 1]) {//这一步为最下面 source_arr[j+1]=temp做准备
			for (j = i - 1; j >= 0; j--) {
				if (temp < source_arr[j]) {
					source_arr[j + 1] = source_arr[j];
				}
				else {
					break;
				}
			}
			source_arr[j + 1] = temp;
		}

	}
}

int mainsh () {
	int i;

	shell_sort();

	for (i = 0; i < NUM; i++) {
		cout << source_arr[i] << endl;
	}

	//完成
	system("pause");

	return 0;
}