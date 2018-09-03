#include <iostream>
#include <algorithm>
using namespace std;
#define NUM 59

int src[NUM] = { 23,9,92, 10, 90, 30, 70, 709, 40, 80, 60 ,55, 13, 91, 32, 72, 42, 81, 65 ,3,23,9,92, 10, 90, 30, 70, 709, 40, 80, 60 ,55, 13, 91, 32, 72, 42, 81, 65 ,3 ,23,9,92, 10, 90, 30, 70, 709, 40, 80, 5923 ,55, 13, 91, 32, 72, 42, 81, 65};

int help[NUM] = { 0 };

void Merge(int start, int mid, int end)
{
	int i = start, j = mid, k = start;

	//归并的过程
	while (i != mid && j != end) {
		if (src[i] > src[j]) {
			help[k] = src[j];
			j++;
		}
		else {
			help[k] = src[i];
			i++;
		}
		k++;
	}
	//一边先完了的话，将另一边循环添加进去
	if (i == mid) {
		while (j != end) {
			help[k] = src[j];
			k++;
			j++;
		}
	}
	if (j == end) {
		while (i != mid) {
			help[k] = src[i];
			k++;
			i++;
		}
	}

	//将help的内容放回src里面
	for (i = start; i < end; i++) {
		src[i] = help[i];
	}
}

int main(){

	int i;
	//先两两排序好，后面直接进行归并
	for (i = 0; i < NUM -1; i+=2) {
		if (src[i] > src[i + 1]) {
			swap(src[i], src[i + 1]);
		}
	}

	//进行合并
	int index = 1;
	while (index < NUM) {
		//归并的距离
		index *= 2;
		
		//根据归并的距离划分为很多小段，进行归并
		i = 0;
		while (i < NUM - 2 * index) {
			Merge(i, i+ index, i + 2* index);
			i += 2 * index;
		}

		//最后一次merge
		//针对元素的个数，如果有19个元素才需要merge，17/18是不能merge的
		if (i + index < NUM) {
			Merge(i, i + index, NUM);
		}
	}

	for (i = 0; i < NUM; i++) {
		cout << src[i] << endl;
	}

	//完成
	system("pause");

	return 0;
}