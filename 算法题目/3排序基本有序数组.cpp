/*
ʵ�����������Ҫ����O(k)���ڴ�ռ䣬��������Ƶ�ｲ������ͬһ������һֱ�������������
д����ʱ�Ƚ�˼·д�����д����Ĺ����־��ܲ���̫������޸ĸ���
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
			//��child_indexָ�����ҽڵ��нϴ��һ��
			if (child_index + 1 <= length && source3[child_index] < source3[child_index + 1]) {
				child_index++;
			}

			if (index_element <= source3[child_index]) {
				//���ڵ����ӽڵ㽻�������ӽڵ��������adjust
				source3[index] = source3[child_index];
				index = child_index;
				child_index = 2 * index + 1;
			}
			else {
				//���ڵ��������
				source3[index] = index_element;
				break;
			}
		}
		source3[index] = index_element;
	}

	vector<int> sortElement(vector<int> A, int n, int k) {

		//int b[2] = {0};
		int *b = new int[k];

		//��A�����k�������Ƶ�b��
		for (int i = 0; i < k; i++) {
			b[i] = A[n - 1 - i];
		}

		//��b�����ɴ����
		for (int i = k / 2; i >= 0; i--) {
			heapAdjust(b, i, k - 1);
		}

		//��b[0]���ϵĽ�����A��
		for (int i = n - 1; i >= k; i--) {
			A[i] = b[0];
			b[0] = A[i - k];
			heapAdjust(b, 0, k - 1);
		}

		//��b���ж�����
		for (int i = k - 1; i > 0; i--) {
			swap(b[0], b[i]);
			heapAdjust(b, 0, i - 1);
		}
		//��b���Ƶ�A��
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
	//���
	system("pause");

	return 0;
}
/*
��Ŀ��
����������������
��[2,1,4,3,6,5,8,7,10,9], 10, 2
�����[1,2,3,4,5,6,7,8,9,10]
*/