/*
注意点：
1.在compare_str中如何对比需要花点时间想。
2.注意bs==sb时也是要返回true的。
3.两次compare_str调用的参数顺序要注意
*/
#include <vector>
#include <string>
using namespace std;

bool compare_str(string big, string small) {
	string bs = big + small;
	string sb = small + big;
	return (bs >= sb) ? true : false;
}
int partition(vector<string> &strs, int low, int high) {
	string pivot_value = strs[low];
	while (low < high) {
		while (low < high && compare_str(strs[high], pivot_value)) {
			high--;
		}
		strs[low] = strs[high];
		while (low < high && compare_str(pivot_value, strs[low])) {
			low++;
		}
		strs[high] = strs[low];
	}
	strs[low] = pivot_value;
	return low;
}
void quick_sort(vector<string> &strs, int low, int high) {
	if (low < high) {
		int index = partition(strs, low, high);
		quick_sort(strs, low, index - 1);
		quick_sort(strs, index + 1, high);
	}
}
string findSmallest(vector<string> strs, int n) {
	// write code here
	quick_sort(strs, 0, n - 1);
	string res = "";
	for (int i = 0; i < n; i++) {
		res += strs[i];
	}
	return res;
}

int mainpz() {
	vector<string> strs;
	string a = "abc";
	string b = "de";
	strs.push_back(a);
	strs.push_back(b);
	int n = 2;
	string res = findSmallest(strs, 2);
	int s = 5;
	return 0;
}
