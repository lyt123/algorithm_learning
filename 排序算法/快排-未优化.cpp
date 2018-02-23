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
		src_arr[low] = src_arr[high];//用赋值而不是交换，减少开销
		while (low < high && src_arr[low] <= pivot_value) {
			low++;
		}
		src_arr[high] = src_arr[low];//用赋值而不是交换，减少开销
	}
	src_arr[low] = pivot_value;//将pivot_value放到中间 因为low==high
	return low;//到这一步时 low == high => pivot_index
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

	//完成
	system("pause");

	return 0;
}