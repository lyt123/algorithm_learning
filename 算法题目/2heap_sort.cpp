#include <iostream>
#include <algorithm>
using namespace std;
#define NUM 15
int source[NUM] = { 6, 5,1,9,3,7,4,8,6 , 5,1,93,3,7,90 };

//û��ͨ���Ĳ�������2   ��ΪheapAdjust(0,1)�Ѵ�ֵ�ŵ�source[0],������swapһ��
//#define NUM 13
//int source[NUM] = { 54,35,48,36,27,12,44,44,8,14,26,17,28 };

//�������Ż���һ�£�ԭ����д��do while����ʽ����ţ�����ϣ�
void heapAdjust(int index, int length) {
	int index_element = source[index];
	int child_index = 2 * index + 1;

	while (child_index <= length) {
		//��child_indexָ�����ҽڵ��нϴ��һ��
		if (child_index + 1 <= length && source[child_index] < source[child_index + 1]) {
			child_index++;
		}

		if (index_element <= source[child_index]) {
			//���ڵ����ӽڵ㽻�������ӽڵ��������adjust
			source[index] = source[child_index];
			index = child_index;
			child_index = 2 * index + 1;
		}
		else {
			//���ڵ��������
			source[index] = index_element;
			break;
		}
	}
	source[index] = index_element;
}

int mainhs() {
	int i;

	for (i = NUM / 2; i >= 0; i--) {
		heapAdjust(i, NUM - 1);
	}

	//ע�����������NUM-1�Ĳ��裬��ΪheapAdjust(0,1)�Ѵ�ֵ�ŵ�source[0],������swapһ��
	for (i = 0; i < NUM - 1; i++) {
		swap(source[0], source[NUM - i - 1]);
		heapAdjust(0, NUM - i - 2);
	}

	for (i = 0; i < NUM; i++) {
		cout << source[i] << endl;
	}

	//���
	system("pause");

	return 0;
}