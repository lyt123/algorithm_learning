#include <iostream>
#include <algorithm>
using namespace std;
#define NUM 59

int src[NUM] = { 23,9,92, 10, 90, 30, 70, 709, 40, 80, 60 ,55, 13, 91, 32, 72, 42, 81, 65 ,3,23,9,92, 10, 90, 30, 70, 709, 40, 80, 60 ,55, 13, 91, 32, 72, 42, 81, 65 ,3 ,23,9,92, 10, 90, 30, 70, 709, 40, 80, 5923 ,55, 13, 91, 32, 72, 42, 81, 65};

int help[NUM] = { 0 };

void Merge(int start, int mid, int end)
{
	int i = start, j = mid, k = start;

	//�鲢�Ĺ���
	while (i != mid && j != end) {
		if (src[i] > src[j]) {
			help[k] = src[j];
			j++;
		}
		else {
			help[k] = src[i];
			i++;
		}
		k++;
	}
	//һ�������˵Ļ�������һ��ѭ����ӽ�ȥ
	if (i == mid) {
		while (j != end) {
			help[k] = src[j];
			k++;
			j++;
		}
	}
	if (j == end) {
		while (i != mid) {
			help[k] = src[i];
			k++;
			i++;
		}
	}

	//��help�����ݷŻ�src����
	for (i = start; i < end; i++) {
		src[i] = help[i];
	}
}

int main(){

	int i;
	//����������ã�����ֱ�ӽ��й鲢
	for (i = 0; i < NUM -1; i+=2) {
		if (src[i] > src[i + 1]) {
			swap(src[i], src[i + 1]);
		}
	}

	//���кϲ�
	int index = 1;
	while (index < NUM) {
		//�鲢�ľ���
		index *= 2;
		
		//���ݹ鲢�ľ��뻮��Ϊ�ܶ�С�Σ����й鲢
		i = 0;
		while (i < NUM - 2 * index) {
			Merge(i, i+ index, i + 2* index);
			i += 2 * index;
		}

		//���һ��merge
		//���Ԫ�صĸ����������19��Ԫ�ز���Ҫmerge��17/18�ǲ���merge��
		if (i + index < NUM) {
			Merge(i, i + index, NUM);
		}
	}

	for (i = 0; i < NUM; i++) {
		cout << src[i] << endl;
	}

	//���
	system("pause");

	return 0;
}