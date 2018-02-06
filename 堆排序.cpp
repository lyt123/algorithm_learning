#include <iostream>
#include <algorithm>
using namespace std;
#define NUM 29

int source[NUM] = { 0, 5,1,9,3,7,4,8,6 , 5,1,93,3,7,24,8,6 , 5,1,9,33,7,44,8,6 ,32,45};

void heapAdjust(int index, int length) {
	int index_element = source[index];
	int child_index;

	do {
		child_index = 2 * index;

		if (child_index >= length) {
			source[index] = index_element;
			break;
		}
		else {
			//��child_indexָ�����ҽڵ��нϴ��һ��
			if (child_index + 1 < length && source[child_index] < source[child_index + 1]) {
				child_index++;
			}

			if (index_element <= source[child_index]) {
				//���ڵ����ӽڵ㽻�������ӽڵ��������adjust
				source[index] = source[child_index];
				index = child_index;
			}
			else {
				//���ڵ��������
				source[index] = index_element;
				break;
			}
		}

	} while (1);
}

int mainhs() {
	int i;

	//source�ĵ�һ��Ԫ�ز�Ҫ�ˣ���Ϊ���ӽڵ��2i �� 2i+1��ϵҪ��
	for (i = NUM / 2; i > 0; i--) {
		heapAdjust(i, NUM);
	}

	for (i = 1; i < NUM - 1; i++) {
		swap(source[1], source[NUM - i]);
		heapAdjust(1, NUM - i);//����ȥ��lengthҪ�����湹���󶥶�ʱС1����Ϊ���������һ��Ԫ�ؾͲ�����ʹ����
	}

	for (i = 1; i < NUM; i++) {
		cout << source[i] << endl;
	}

	//���
	system("pause");

	return 0;
}