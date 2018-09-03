/*
实现这个代码需要借助O(k)的内存空间，并不像视频里讲的能在同一个里面一直数组里进行排序
写代码时先将思路写清楚，写代码的过程种就能不用太多的修修改改了
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define NUM 10
int source3[NUM] = { 2,1,4,3,6,5,8,7,10,9 };

class ScaleSort {
public:
	void swap(int & a, int & b) {
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	void heapAdjust(int * source3, int index, int length) {
		int index_element = source3[index];
		int child_index = 2 * index + 1;

		while (child_index <= length) {
			//将child_index指向左右节点中较大的一个
			if (child_index + 1 <= length && source3[child_index] < source3[child_index + 1]) {
				child_index++;
			}

			if (index_element <= source3[child_index]) {
				//父节点与子节点交换，从子节点继续向下adjust
				source3[index] = source3[child_index];
				index = child_index;
				child_index = 2 * index + 1;
			}
			else {
				//父节点已是最大
				source3[index] = index_element;
				break;
			}
		}
		source3[index] = index_element;
	}

	vector<int> sortElement(vector<int> A, int n, int k) {

		//int b[2] = {0};
		int *b = new int[k];

		//将A的最后k个数复制到b上
		for (int i = 0; i < k; i++) {
			b[i] = A[n - 1 - i];
		}

		//将b构建成大跟堆
		for (int i = k / 2; i >= 0; i--) {
			heapAdjust(b, i, k - 1);
		}

		//将b[0]不断的交换到A上
		for (int i = n - 1; i >= k; i--) {
			A[i] = b[0];
			b[0] = A[i - k];
			heapAdjust(b, 0, k - 1);
		}

		//对b进行堆排序
		for (int i = k - 1; i > 0; i--) {
			swap(b[0], b[i]);
			heapAdjust(b, 0, i - 1);
		}
		//将b复制到A上
		for (int i = 0; i < k; i++) {
			A[i] = b[i];
		}

		return A;
	}
};
int mainss() {
	int k = 2;
	int n = NUM;
	vector<int> A(source3, source3 + 10);

	ScaleSort ss;
	A = ss.sortElement(A, n, k);

	int b = 3;
	//完成
	system("pause");

	return 0;
}
/*
题目：
排序基本有序的数组
如[2,1,4,3,6,5,8,7,10,9], 10, 2
排序成[1,2,3,4,5,6,7,8,9,10]
*/