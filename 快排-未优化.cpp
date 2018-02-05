#include <iostream>
#include <algorithm>
using namespace std;
#define NUM 9

int src_arr[NUM] = { 5,1,9,3,7,4,8,6,2 };

int partition(int low, int high) {
	int pivot_value = src_arr[low];

	while (low < high) {
		while (low < high && src_arr[high] >= pivot_value) {
			high--;
		}
		src_arr[low] = src_arr[high];//�ø�ֵ�����ǽ��������ٿ���
		while (low < high && src_arr[low] <= pivot_value) {
			low++;
		}
		src_arr[high] = src_arr[low];//�ø�ֵ�����ǽ��������ٿ���
	}
	src_arr[low] = pivot_value;//��pivot_value�ŵ��м� ��Ϊlow==high
	return low;//����һ��ʱ low == high => pivot_index
}

void quick_sort(int low, int high) {
	int pivot_index;
	if (low < high) {
		pivot_index = partition(low, high);
		quick_sort(low, pivot_index - 1);
		quick_sort(pivot_index + 1, high);
	}
}

int main() {
	int i;

	quick_sort(0,8);

	for (i = 0; i < NUM; i++) {
		cout << src_arr[i] << endl;
	}

	//���
	system("pause");

	return 0;
}