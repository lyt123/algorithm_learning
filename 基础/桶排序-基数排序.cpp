#include <iostream>
#include <algorithm>
using namespace std;
#define NUM 13

int orgin_arr[] = { 5412,351,4821,362,127,12,441,414,8,1499,2226,5717,268 };

void radix_sort() {
	//����ռ䣬��ά����help[9][NUM+1]  help[i][0]������ϵ������ܸ���
	int help[10][NUM + 1] = { 0 };

	//ѭ�����->���������Ϊcircleλ��������Ϊ4
	int circle = 0;
	while (circle < 4) {
		//���help��
		for (int i = 0; i < NUM; i++)
		{
			int value = (orgin_arr[i] / (int)pow(10, circle)) % 10;
			help[value][help[value][0] + 1] = orgin_arr[i];
			help[value][0]++;
		}

		//��help�ﵼ����
		int index = 0, temp = 1;
 		for (int i = 0; i <= 9; i++)
		{
			while (help[i][0] > 0) {
				orgin_arr[index++] = help[i][temp++];
				help[i][0]--;
			}
			temp = 1;
		}

		circle++;
	}
}

int mainrss() {
	int i;

	radix_sort();

	for (i = 0; i < NUM; i++) {
		cout << orgin_arr[i] << endl;////
	}

	//���
	system("pause");

	return 0;
}