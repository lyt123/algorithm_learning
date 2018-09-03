#include <iostream>
#include <algorithm>
using namespace std;
#define NUM 15
int source[NUM] = { 6, 5,1,9,3,7,4,8,6 , 5,1,93,3,7,90 };

//没有通过的测试用例2   因为heapAdjust(0,1)把大值放到source[0],故需再swap一次
//#define NUM 13
//int source[NUM] = { 54,35,48,36,27,12,44,44,8,14,26,17,28 };

//这里我优化了一下，原先是写成do while的形式（在牛客网上）
void heapAdjust(int index, int length) {
	int index_element = source[index];
	int child_index = 2 * index + 1;

	while (child_index <= length) {
		//将child_index指向左右节点中较大的一个
		if (child_index + 1 <= length && source[child_index] < source[child_index + 1]) {
			child_index++;
		}

		if (index_element <= source[child_index]) {
			//父节点与子节点交换，从子节点继续向下adjust
			source[index] = source[child_index];
			index = child_index;
			child_index = 2 * index + 1;
		}
		else {
			//父节点已是最大
			source[index] = index_element;
			break;
		}
	}
	source[index] = index_element;
}

int mainhs() {
	int i;

	for (i = NUM / 2; i >= 0; i--) {
		heapAdjust(i, NUM - 1);
	}

	//注意这里遍历到NUM-1的步骤，因为heapAdjust(0,1)把大值放到source[0],故需再swap一次
	for (i = 0; i < NUM - 1; i++) {
		swap(source[0], source[NUM - i - 1]);
		heapAdjust(0, NUM - i - 2);
	}

	for (i = 0; i < NUM; i++) {
		cout << source[i] << endl;
	}

	//完成
	system("pause");

	return 0;
}