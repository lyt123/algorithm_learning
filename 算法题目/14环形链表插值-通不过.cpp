///*
//1.������������ɣ��������ڵ�pre��now���ܣ����������temp->next->next����ʽ��һ�㡣��Ȼ����ʵ�֣��������źܶ�
//*/
//#include <iostream>
//#include <stack>
//#include <vector>
//using namespace std;
//
//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//ListNode* insert(vector<int> A, vector<int> nxt, int val) {
//	ListNode * pHead, *new_node, *temp;
//
//	//case 1  ����Ϊ��
//	if (A.empty()) {
//		pHead = new ListNode(val);
//		return pHead;
//	}
//
//	//��������
//	new_node = new ListNode(A[0]);
//	pHead = new_node;
//
//	temp = pHead;
//	for (int i = 1; i < A.size(); i++) {
//		temp->next = new ListNode(A[i]);
//		temp = temp->next;
//	}
//	temp->next = pHead;
//
//	//case 2  ����Ϊ��
//	temp = pHead;
//
//	//case 2.1 �ڵ�һ���ڵ����
//
//	if (val <= pHead->val) {
//		new_node = new ListNode(val);
//		new_node->next = pHead->next;
//		pHead->next = new_node;
//		return pHead;
//	}
//
//	while (1) {
//		if (val > temp->next->val && temp->next->next != pHead) {
//			temp = temp->next;
//		}
//		else {
//			//�������һ���ڵ�		
//			if (temp->next->next == pHead) {
//				if (val <= temp->next->val) {
//					//case2.2 �ڵ����ڶ���λ�ò���
//					//temp = temp->next;
//				}
//				else {
//					//case2.3��ĩβ����
//					temp = temp->next;
//				}
//			}
//
//			//case 2.4���м����
//			new_node = new ListNode(val);
//			new_node->next = temp->next;
//			temp->next = new_node;
//			break;
//		}
//	}
//	temp = pHead;
//	while (temp->next != pHead) {
//		temp = temp->next;
//	}
//	temp->next = nullptr;
//	return pHead;
//}
//
//int maintng() {
//	int a[5] = { 1,3,4,5,7 };
//	int b[5] = { 1,2,3,4,0 };
//	vector<int> va(a, a + 5);
//	vector<int>vb(b, b + 5);
//	int val = 2;
//	ListNode * res = insert(va, vb, 2);
//	int tttt = 5;
//	system("pause");
//	return 0;
//}