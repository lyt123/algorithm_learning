#include <iostream>
#include <algorithm>
using namespace std;
#define NUM 29

int source[NUM] = { 0, 5,1,9,3,7,4,8,6 , 5,1,93,3,7,24,8,6 , 5,1,9,33,7,44,8,6 ,32,45};

void heapAdjust(int index, int length) {
	int index_element = source[index];
	int child_index;

	do {
		child_index = 2 * index;

		if (child_index >= length) {
			source[index] = index_element;
			break;
		}
		else {
			//将child_index指向左右节点中较大的一个
			if (child_index + 1 < length && source[child_index] < source[child_index + 1]) {
				child_index++;
			}

			if (index_element <= source[child_index]) {
				//父节点与子节点交换，从子节点继续向下adjust
				source[index] = source[child_index];
				index = child_index;
			}
			else {
				//父节点已是最大
				source[index] = index_element;
				break;
			}
		}

	} while (1);
}

int mainhs() {
	int i;

	//source的第一个元素不要了，因为父子节点的2i 和 2i+1关系要求
	for (i = NUM / 2; i > 0; i--) {
		heapAdjust(i, NUM);
	}

	for (i = 1; i < NUM - 1; i++) {
		swap(source[1], source[NUM - i]);
		heapAdjust(1, NUM - i);//传进去的length要比上面构建大顶堆时小1，因为交换后，最后一个元素就不能再使用了
	}

	for (i = 1; i < NUM; i++) {
		cout << source[i] << endl;
	}

	//完成
	system("pause");

	return 0;
}