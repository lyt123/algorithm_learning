/*
1.将w=1的情况单独拉出来是有必要的
2.写代码是一步一步来的  好比第二点和第三点的前面更新和后面补充我原先写出来的代码比较难看，优化后就变成下面那样了
3.第四点如果没有在测试用例中报错，我很难发现问题
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class SlideWindow {
public:
	vector<int> slide(vector<int> arr, int n, int w) {
		//这一步可以放在最开始的地方，直接返回，下边的变量都不用定义了
		if (w == 1) {
			return arr;
		}
		vector<int>max_values;
		deque <int> max_indexs;

		//我这里先插入就省去了下面判空的操作了
		max_indexs.push_back(0);

		for (int i = 1; i < n; i++) {

			//1.队首超出的话  移除
			if (i - max_indexs.front() == w) {
				max_indexs.pop_front();
			}

			if (arr[max_indexs.back()] < arr[i]) {
				//2.前面更新
				while (!max_indexs.empty() && arr[max_indexs.back()] < arr[i])
					max_indexs.pop_back();
			}
			//3.后面补充
			max_indexs.push_back(i);

			//4.当i < w时，只构造max_indexs队列而不push_back。如果没有考虑这一点，会出错
			if (i >= w - 1)
				max_values.push_back(arr[max_indexs.front()]);
		}

		return max_values;
	}
};

int mainzfz() {
	system("pause");
	return 0;
}