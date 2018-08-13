/*
1.��w=1������������������б�Ҫ��
2.д������һ��һ������  �ñȵڶ���͵������ǰ����ºͺ��油����ԭ��д�����Ĵ���Ƚ��ѿ����Ż���ͱ������������
3.���ĵ����û���ڲ��������б����Һ��ѷ�������
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class SlideWindow {
public:
	vector<int> slide(vector<int> arr, int n, int w) {
		//��һ�����Է����ʼ�ĵط���ֱ�ӷ��أ��±ߵı��������ö�����
		if (w == 1) {
			return arr;
		}
		vector<int>max_values;
		deque <int> max_indexs;

		//�������Ȳ����ʡȥ�������пյĲ�����
		max_indexs.push_back(0);

		for (int i = 1; i < n; i++) {

			//1.���׳����Ļ�  �Ƴ�
			if (i - max_indexs.front() == w) {
				max_indexs.pop_front();
			}

			if (arr[max_indexs.back()] < arr[i]) {
				//2.ǰ�����
				while (!max_indexs.empty() && arr[max_indexs.back()] < arr[i])
					max_indexs.pop_back();
			}
			//3.���油��
			max_indexs.push_back(i);

			//4.��i < wʱ��ֻ����max_indexs���ж���push_back�����û�п�����һ�㣬�����
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