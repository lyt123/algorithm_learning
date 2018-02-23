#include <iostream>
#include <algorithm>
using namespace std;
#define NUM 13

int orgin_arr[] = { 5412,351,4821,362,127,12,441,414,8,1499,2226,5717,268 };

void radix_sort() {
	//分配空间，二维数组help[9][NUM+1]  help[i][0]存该行上的数的总个数
	int help[10][NUM + 1] = { 0 };

	//循环多次->依据最大数为circle位数，这里为4
	int circle = 0;
	while (circle < 4) {
		//存进help里
		for (int i = 0; i < NUM; i++)
		{
			int value = (orgin_arr[i] / (int)pow(10, circle)) % 10;
			help[value][help[value][0] + 1] = orgin_arr[i];
			help[value][0]++;
		}

		//从help里导出来
		int index = 0, temp = 1;
 		for (int i = 0; i <= 9; i++)
		{
			while (help[i][0] > 0) {
				orgin_arr[index++] = help[i][temp++];
				help[i][0]--;
			}
			temp = 1;
		}

		circle++;
	}
}

int mainrss() {
	int i;

	radix_sort();

	for (i = 0; i < NUM; i++) {
		cout << orgin_arr[i] << endl;////
	}

	//完成
	system("pause");

	return 0;
}