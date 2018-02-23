#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define NUM 11

int start[] = { 0,2,1,4,3,6,5,8,7,10,9 };

void heap_adjust(int index, int length) {
	int index_element = start[index];
	int child_index;

	do {
		child_index = 2 * index;

		if (child_index > length) {
			start[index] = index_element;
			break;
		}
		else {
			//��child_indexָ�����ҽڵ��нϴ��һ��
			if (child_index + 1 <= length && start[child_index] > start[child_index + 1]) {
				child_index++;
			}

			if (index_element > start[child_index]) {
				//���ڵ����ӽڵ㽻�������ӽڵ��������adjust
				start[index] = start[child_index];
				index = child_index;
			}
			else {
				//���ڵ��������
				start[index] = index_element;
				break;
			}
		}

	} while (1);
}

int mainmsss() {
	int i;
	int k = 2;//�������������

	//��ǰk��������С����  
	for (i = k / 2; i > 0; i--) {
		heap_adjust(i, k);
	}

	vector<int> help;//�洢���

	//����ȡ���Ѷ�Ԫ�ش浽help
	int index = 1;
	while (k + index < NUM) {

		help.push_back(start[1]);
		start[1] = start[k + index];

		heap_adjust(1, k);
		index++;
	}

	//heapsort(1, k);
	for (i = 1; i < k+1; i++) {

		help.push_back(start[1]);
		start[1] = start[k-i+1];

		heap_adjust(1, k - i);
	}

	for (auto item : help) {
		cout << item << endl;
	}

	//���
	//���䣺���ڻ�����������ʱ�临�Ӷ�ΪN*logK����N*logNС�ˡ�
	//������Ƶ�Ľⷨ�������help�������Բ��õģ����ʹ�±��i��2i 2i+1�Ķ�Ӧ��ϵ�б仯�ˣ�������鷳һ��

	system("pause");

	return 0;
}