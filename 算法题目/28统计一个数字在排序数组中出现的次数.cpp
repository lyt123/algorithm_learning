#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


//direction  0 左 1 右
int recur(vector<int>& data, int start, int end, int direction, int k) {
	int mid = (start + end) / 2;
	if (direction == 0) {
		if (start >= end)
			return data[start] == k ? start : start + 1;

		if (k > data[mid]) {
			return recur(data, mid + 1, end, 0, k);
		}
		else {
			//相等了
			return recur(data, start, mid - 1, 0, k);
		}
	}
	else {
		if (start >= end)
			return data[start] == k ? start : start - 1;

		if (k == data[mid]) {
			return recur(data, mid + 1, end, 1, k);
		}
		else {
			//不相等
			return recur(data, start, mid - 1, 1, k);
		}
	}
}
int GetNumberOfK(vector<int> &data, int k) {
	int max_index = data.size() - 1;
	if (max_index == 1)
		return data[0] == k ? 1 : 0;
	if (max_index == 2)
		return (data[0] == k ? 1 : 0) + (data[1] == k ? 1 : 0);

	int first_pos = 0, left_pos = 0, right_pos = 0;
	int mid = max_index / 2;
	while (mid != 0 && mid != max_index) {
		if (data[mid] == k) {
			left_pos = recur(data, 0, mid - 1, 0, k);
			right_pos = recur(data, mid + 1, max_index, 1, k);
			break;
		}
		else if (k < data[mid]) {
			mid = mid / 2;
		}
		else {
			mid = (mid + max_index) / 2;
		}
	}

	return (mid != 0 && mid != max_index) ? (right_pos - left_pos + 1) : 0;
}


int maintj()
{
	//vector<int> w = { 1,2,3,5,8,8,8,9,10,12 };
	//vector<int> w = { 1,2,3,3,3,3,4,5 };
	vector<int> w = { 3,3,3,3,4,5 };

	//string aaw = to_string(w[0]) + to_string(w[1]);
	int res = GetNumberOfK(w, 3);
	int a = 54;
	system("pause");
	return 0;
}