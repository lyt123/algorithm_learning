#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
#define NUM 29

int orgin[NUM] = { 0, 5,1,9,3,7,4,8,6 , 5,1,93,3,7,24,8,6 , 5,1,9,33,7,44,8,6 ,32,45 };

void counting_sort() {
	//求出max min	
	int max = 0, min = 0;
	for (int i = 0; i < NUM; i++) {
		if (orgin[i] > max) {
			max = orgin[i];
		}
		if (orgin[i] < min) {
			min = orgin[i];
		}
	}

	int dis = max - min + 1;

	//分配max-min的数组
	int * dis_arr = (int *)calloc(dis, sizeof(int));

	//统计，在该数组中计数
	for (int i = 0; i < NUM; i++)
	{
		int index = orgin[i] - min;
		dis_arr[index]++;
	}

	//根据计数，得到排序结果
	int j = 0;
	for (int i = 0; i < dis; i++) {
		while (dis_arr[i] > 0) {
			orgin[j] = min + i;
			j++;
			dis_arr[i]--;
		}
	}
}

int maincss   () {
	int i;
	counting_sort();

	for (i = 0; i < NUM; i++) {
		cout << orgin[i] << endl;
	}

	//完成
	system("pause");

	return 0;
}