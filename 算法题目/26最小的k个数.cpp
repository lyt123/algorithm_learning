#include <iostream>
#include <vector>
using namespace std;

void heapAdjust(vector<int>& source, int index, int length) {
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
void heapSort(vector<int>& A, int n) {
	int NUM = n;
	for (int i = NUM / 2; i >= 0; i--) {
		heapAdjust(A, i, NUM - 1);
	}
	for (int i = 0; i < NUM - 1; i++) {
		swap(A[0], A[NUM - i - 1]);
		heapAdjust(A, 0, NUM - i - 2);
	}
}
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	//将前k个数构建成大顶堆
	for (int i = k / 2; i >= 0; i--) {
		heapAdjust(input, i, k - 1);
	}

	//将最小的k个数放到堆里
	for (int i = k; i < input.size(); i++) {
		if (input[i] < input[0]) {
			swap(input[0], input[i]);
			heapAdjust(input, 0, k - 1);
		}
	}

	heapSort(input, k);
	vector<int>res;
	for (int i = 0; i < k; i++)
		res.push_back(input[i]);
	return res;
}

int mainzxs()
{
	/*vector<int> w = { 1,2,3 };
	vector<int> v = { 1,2,3 };
	int res = maxValue(w, v, 3, 6);*/
	vector<int> w = { 4,5,1,6,2,7,3,8 };
	vector<int> v = GetLeastNumbers_Solution(w, 4);
	int a = 54;
	system("pause");
	return 0;
}