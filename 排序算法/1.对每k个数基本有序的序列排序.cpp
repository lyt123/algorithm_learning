#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define NUM 11

int start[] = { 0,2,1,4,3,6,5,8,7,10,9 };

void heap_adjust(int index, int length) {
	int index_element = start[index];
	int child_index;

	do {
		child_index = 2 * index;

		if (child_index > length) {
			start[index] = index_element;
			break;
		}
		else {
			//将child_index指向左右节点中较大的一个
			if (child_index + 1 <= length && start[child_index] > start[child_index + 1]) {
				child_index++;
			}

			if (index_element > start[child_index]) {
				//父节点与子节点交换，从子节点继续向下adjust
				start[index] = start[child_index];
				index = child_index;
			}
			else {
				//父节点已是最大
				start[index] = index_element;
				break;
			}
		}

	} while (1);
}

int mainmsss() {
	int i;
	int k = 2;//基本有序的数量

	//将前k个数构建小顶堆  
	for (i = k / 2; i > 0; i--) {
		heap_adjust(i, k);
	}

	vector<int> help;//存储结果

	//不断取出堆顶元素存到help
	int index = 1;
	while (k + index < NUM) {

		help.push_back(start[1]);
		start[1] = start[k + index];

		heap_adjust(1, k);
		index++;
	}

	//heapsort(1, k);
	for (i = 1; i < k+1; i++) {

		help.push_back(start[1]);
		start[1] = start[k-i+1];

		heap_adjust(1, k - i);
	}

	for (auto item : help) {
		cout << item << endl;
	}

	//完成
	//补充：由于基本有序，所以时间复杂度为N*logK，比N*logN小了。
	//按照视频的解法，此题的help函数可以不用的，这就使下标的i和2i 2i+1的对应关系有变化了，代码会麻烦一点

	system("pause");

	return 0;
}